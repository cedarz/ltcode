struct STNode {
	STNode * left, * right;
	int val;
	int x, y;
	
	STNode(int _x, int _y) : x(_x), y(_y), val(0), left(nullptr), right(nullptr) {}
};

class SegTree {
private:
	STNode * root;
	
	STNode * build(int a, int b) {
		STNode * r = new STNode(a, b);
		if(a + 1 == b) return r;
		
		if(a != b) {
			r->left = build(a, (a + b) / 2);
			r->right = build((a + b) / 2, b);
		}
		return r;
	}
	
public:
	SegTree(int a, int b) {
		root = build(a, b);
	}
	
	void update(STNode * r, int x, int y, int num) {
		if(x >= r->y || y <= x->x) return;
		if(x <= r->x && y >= r->y) {
			r->val = num;
		} else {
			int mid = (r->x + r->y) / 2;
			if(x <= mid) update(r->left, x, y, num);
			if(y >= mid + 1) update(r->right, x, y, num);
		}
	}
	
	int query(STNode * r, int x, int y) {
		if(r->x <= x && y <= r->y) return r->val;
		int mid = (r->x + r->y) / 2;
		
		if()
		
	}
}

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        
    }
};