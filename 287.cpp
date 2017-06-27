class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int L = nums.size();
		int mid = L / 2;
		
		int cl = 0, cm = 0, ch = 0;
		int low = 1, high = L - 1;
		while(true) {
			for(int i = 0; i < L; ++i) {
				if(nums[i] < mid) ++cl;
				if(nums[i] == mid) ++cm;
				if(nums[i] > mid) ++ch;
			}
			
			if(cm > 1) return mid;
			else if(cl > mid - 1) {
				high = mid - 1;
			} else if(ch > L - mid + 1) {
				low = mid + 1;
			}
			mid = (low + high) / 2;
		}
    }
};