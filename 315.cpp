class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
		unordered_set<int> ns;
		for(auto i : nums) {
			ns.insert(i);
		}
		vector<int> vs;
		for(auto i : ns) {
			vs.push_back(i);
		}
		
		sort(vs.begin(), vs.end());
		unordered_map<int, int> ms;
		for(int i = 0; i < vs.size(); ++i) {
			ms[vs[is]] = i;
		}
		
		bit = vector<int> (vs.size() + 1, 0);
		
		vector<int> res(nums.size(), 0);
	
		for(int i = nums.size() - 1; i >= 0; --i) {
			res[i] = read(ms[nums[i]]);
			update(ms[nums[i]] + 1, vs.size());
		}
		return res;
	}

private:
	int lowbit(int idx) {
		return idx & (-idx);
	}
	
	void update(int idx, int maxIdx) {
		while(idx <= maxIdx) {
			++bit[idx];
			idx += lowbit(idx);
		}
	}
	
	int read(int idx) {
		int tmp = 0;
		while(idx >= 1) {
			tmp += bit[idx];
			idx -= lowbit(idx);

		}
		return tmp;
	}
	
	vector<int> bit;
};