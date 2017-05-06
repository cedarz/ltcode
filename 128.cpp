class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> um;
		
		if(nums.empty()) return 0;
		
		int sz = nums.size();
		int res = 1;
		
		for(int i = 0; i < sz; ++i) {
			um.insert(nums[i]);
		}
		for(int i = 0; i < sz; ++i) {
			int tmp = 1; 
			int seq = nums[i] - 1;
			if(um.find(seq) == um.end()) {
				seq = nums[i] + 1;
				while(um.find(seq++) != um.end()) {
					++tmp;
				}
				if(tmp > res) res = tmp;
			}
		}
		return res;
    }
};