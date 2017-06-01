class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int tmp = nums[0];
    	int i = 0;
    	int cnt = 1;
    	for(i = 1; i < nums.size(); ++i) {
    		if(nums[i] == tmp) {
    			++cnt;
    		} else {
    			--cnt;
    			if(cnt == 0) {
    				if(i != nums.size() - 1) tmp = nums[i + 1];
    			}
    		}
    	}
    	return tmp;
    }
};