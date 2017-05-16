class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> m;
		for(int i = 0; i < nums.size(); ++i) {
			if(m[nums[i]]) m[nums[i]]++;
			else m[nums[i]] = 1;
			
			if(m[nums[i]] == 3) m.erase(nums[i]);
		}
		return m.begin()->first;
    }
};