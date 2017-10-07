#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;

// https://discuss.leetcode.com/topic/32475/c-o-n-amount-time-o-amount-space-dp-solution
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
		
		dp[0] = 0;
		
		for(int j = 1; j <= coins.size(); ++j) {
			for(int i = 1; i <= amount; ++i) {
				if(i >= coins[j - 1]) dp[i] = min(dp[i - coins[j - 1]] + 1, dp[i]);
			}
		}
		return dp[amount] > amount ? -1 : dp[amount];
    }
};

int main() {
	//int array[] = {1, 3, 5};
	//vector<int> c(array, array + 3);
	vector<int> c({3, 5});
	cout << Solution().coinChange(c, 11) << endl;
	
	return 0;
}
