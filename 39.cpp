#include <algorithm>
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        len = candidates.size();
        res.clear();
        vector<int> sol;
        dfs(sol, candidates, target, 0);
        return res;
    }
    
    void dfs(vector<int> & sol, vector<int> & candidates, int target, int loc) {
        if(target == 0)  res.push_back(sol);
        if(loc >= len || target < candidates[loc]) return;

        int cur_len = sol.size();
        for(int j = 0; j * candidates[loc] <= target; ++j) {
            if(j > 0) {
                sol.push_back(candidates[loc]);
                cur_len++;
            }
            dfs(sol, candidates, target - j * candidates[loc], loc + 1);
            while(sol.size() > cur_len) sol.pop_back();
        }
    }
        
private:
    vector<vector<int>> res;
    int len;
};


