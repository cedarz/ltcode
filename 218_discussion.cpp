#define left(i) (i<<1)

#define right(i) ((i<<1) + 1)

struct Node {
	int nodel, noder, nodeh;
};

struct Segment {
	int begin, end;
};

class Solution {
public:
	vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
	    if(buildings.size() == 0) return {};
		int sz = buildings.size();
		vector<int> nums;
		for (int i = 0; i<sz; i++) {
			nums.push_back(buildings[i][0]);
			nums.push_back(buildings[i][1]);
		}
		sort(nums.begin(), nums.end());
		int pre = 0;
		int numssz = nums.size();
		map<int, int> m;
		for (int i = 0; i < numssz; i++) {
			if (pre < nums[i]) segments.push_back({ pre, nums[i] - 1 });
			segments.push_back({ nums[i], nums[i] });
			int idx = segments.size()-1;
			m[nums[i]] = idx;
			pre = nums[i]+1;
		}
		int segmentsnum = segments.size();
		tree = vector<Node>(segmentsnum << 2, { 0, 0, 0 });
		heights = vector<int>(segmentsnum+1, 0);

		buildTree(1, 0, segmentsnum);

		for (int i = 0; i<sz; i++) {
			set(1, m[buildings[i][0]], m[buildings[i][1]]-1, buildings[i][2]);
		}
		getHeights();
		vector<pair<int, int>> ret;
		for (int i = 0; i < segmentsnum; i++) {
			if (i == 0 && heights[i] != 0 || i != 0 && heights[i] != heights[i - 1]) ret.push_back(make_pair(segments[i].begin, heights[i]));
		}
		if (heights[segmentsnum - 1] != 0) ret.push_back(make_pair(segments[segmentsnum - 1].begin, 0));
		return ret;
	}
private:
	vector<Node> tree;
	vector<int> heights;
	vector<Segment> segments;
	void buildTree(int idx, int l, int r) {
		tree[idx].nodel = l;
		tree[idx].noder = r;
		tree[idx].nodeh = 0;
		if (l == r)
		{
			return;
		}
		int mid = (l + r) / 2;
		buildTree(left(idx), l, mid);
		buildTree(right(idx), mid + 1, r);
	}

	void update(int idx) {
		if (tree[idx].nodel == tree[idx].noder) return;
		if (tree[left(idx)].nodeh < tree[idx].nodeh) {
			tree[left(idx)].nodeh = tree[idx].nodeh;
		}
		if (tree[right(idx)].nodeh < tree[idx].nodeh) {
			tree[right(idx)].nodeh = tree[idx].nodeh;
		}
		tree[idx].nodeh = 0;
	}

	void set(int idx, int l, int r, int h) {

		if (tree[idx].nodel >= l && tree[idx].noder <= r) {
			tree[idx].nodeh = max(tree[idx].nodeh, h);
			return;
		}

		int mid = (tree[idx].nodel + tree[idx].noder) / 2;
		update(idx);
		if (mid >= l) {
			set(left(idx), l, r, h);
		}
		if (mid<r) {
			set(right(idx), l, r, h);
		}

	}

	void getHeights() {
		queue<int> q;
		q.push(1);
		while (!q.empty()) {
			int idx = q.front();
			q.pop();
			update(idx);
			if (tree[idx].nodel == tree[idx].noder)
			{
				heights[tree[idx].nodel] = tree[idx].nodeh;
				continue;
			}
			q.push(left(idx));
			q.push(right(idx));
		}
	}
};