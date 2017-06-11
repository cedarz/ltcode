class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> v;
        if(n > 45) return v;
		
		vector<int> tmp;
		dfs(v, 1, n, tmp, k);
		
		return v;
    }
	
	void dfs(vector<vector<int>> & v, int k, int sum, vector<int> & curr, int cnt) {
		if(sum == 0 && curr.size() == cnt) {
			//curr.push_back(k);
			v.push_back(curr);
			//curr.pop_back();
			return;
		} 
		
		if(k > 9 || sum < 0 || curr.size() > cnt) return;
		
		{
			curr.push_back(k);
			dfs(v, k + 1, sum - k, curr, cnt);
			curr.pop_back();
			
			dfs(v, k + 1, sum, curr, cnt);
		}
		
	}
};