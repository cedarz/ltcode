class Solution {
public:
    int maxCoins(vector<int>& nums) {
		if(nums.empty()) return 0;

        vector<int> coin(nums.size(), 0);
		
		vector<vector<int>> dp(nums.size(), vector<int> (nums.size(), 0));
		
		dfs(nums, coin, dp);
		
		return 0;
    }
	
	void dfs(vector<int> & nums, vector<int> & coin, vector<vector<int>> & dp) {
		for(int d = 0; d < nums.size(); ++d) {
			for(int i = 0; i + d < nums.size(); ++i) {
				int tmp  = 0;
				cout << i << " " << i + d << " ";
				for(int first = i; first <= i + d; ++first) {
					int sum = (i - 1 < 0 ? 1 : nums[i - 1]) * nums[i] * (i + d + 1 >= nums.size() ? 1 : nums[i + d + 1]);
					cout << (i - 1 < 0 ? 1 : nums[i - 1])  << " " << nums[i] << " " << (i + d + 1 >= nums.size() ? 1 : nums[i + d + 1]) << endl;;
					int left = i, right = first - 1;
					if(left <= right) 
						sum += dp[left][right];
					left = first + 1, right = i + d;
					if(left <= right) 
						sum += dp[left][right];
					tmp = max(tmp, sum);
				}
				dp[i][i + d] = tmp;
			}
		}
		
		for(int i = 0; i < dp.size(); ++i) {
			for(int j = 0; j < dp.size(); ++j) {
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}
	}
};

