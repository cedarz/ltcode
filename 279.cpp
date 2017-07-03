class Solution {
public:
    int numSquares(int n) {
        int res = n;
		
		if(n <= 0) return 0;
		
		vector<int> cost(n + 1, INT_MIN);
		cost[0] = 0;
		
		for(int i = 1; i * i <= n; ++i) {
			for(int j = i * i; j <= n; ++j) {
				cost[j] = min(cost[j], cost[j - i * i] + 1);
			}
		}
		return cost[n];
		
    }
};