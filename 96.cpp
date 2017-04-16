class Solution {
public:
    int numTrees(int n) {
        vector<vector<int>> tree(n, vector<int>(n, 0));
		dp(tree, n);
		return tree[0][n - 1];
    }
	
private:	
	int dfs(int low, int high) {
		int res = 0;
		if(low == high) {
			return 1;
		}
		for(int i = low; i <= high; ++i) {
			//vector<TreeNode*> left, right;
			int left = 1, right = 1;
			if(i - low > 0) {
				left = dfs(low, i - 1);
			}
			if(high - i > 0) {
				right = dfs(i + 1, high);
			}
			res += left * right;
			
		}
		return res;
	}
	
	void dp(vector<vector<int>> & tree, int n) {
	    for(int i = 0; i < n; ++i) {
	        tree[i][i] = 1;
	    }
		for(int i = n - 1; i >= 0; --i) {
			for(int j = i + 1; j < n; ++j) {
				int res = 0;
				for(int k = i; k <= j; ++k) {
					if(k == i) res += tree[k + 1][j];
					else if(k == j) res += tree[i][k - 1];
					else res += tree[i][k - 1] * tree[k + 1][j];
				}
				tree[i][j] = res;
				//cout << res << " ";
			}
			//cout << endl;
		}
	}
};