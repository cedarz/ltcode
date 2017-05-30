class Solution {
public:
	int bs(vector<int> & nums) {
		const int L = nums.size();
		int low = 0, high = L - 1;;
		int mid = (low + high) / 2;
		
		while(low < high) {
			if(nums[mid] <= nums[(mid + 1) % L] && nums[mid] <= nums[(mid - 1 + L) % L]) {
				return nums[mid];
			} else {
				
				if(nums[mid] > nums[high]) {
					low = mid + 1;
				} else {
					high = mid - 1;
				}
			}
			mid = (low + high) / 2;
		}
		return nums[mid];
	}
    int findMin(vector<int>& nums) {
        return bs(nums);
    }
};