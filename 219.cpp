class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> m;
		for(int i = 0; i < nums.size(); ++i) {
			m[nums[i]].push_back(i);
		}
		
		for(auto it : m) {
			vector<int> & tmp = it.second;
			if(tmp.size() > 1) {
				for(int i = 1; i < tmp.size(); ++i) {
					if(tmp[i] - tmp[i - 1] <= k) {
						return true;
					}
				}
			}
		}
		return false;
    }
};