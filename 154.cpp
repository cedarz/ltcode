class Solution {
public:
	int bs(vector<int> & nums) {
		const int L = nums.size();
		int low = 0, high = L - 1;;
		int mid = (low + high) / 2;
		
		while(low < high) {
			//if(nums[mid] <= nums[(mid + 1) % L] && nums[mid] <= nums[(mid - 1 + L) % L]) {
			//	return nums[mid];
			//} else {
				cout << low << " " << mid << " " << high << endl;
				
				if(nums[mid] > nums[high]) {
					low = mid + 1;
				} else if(nums[mid] == nums[high]) {
				    --high;
				} else {
					high = mid;
				}
			//}
			mid = (low + high) / 2;
		}
		return nums[mid];
	}
    int findMin(vector<int>& nums) {
        return bs(nums);
    }
};

/*
class Solution {
public:
    int findMin(vector<int> &num) {
        int lo = 0;
        int hi = num.size() - 1;
        int mid = 0;
        
        while(lo < hi) {
            mid = lo + (hi - lo) / 2;
            
            if (num[mid] > num[hi]) {
                lo = mid + 1;
            }
            else if (num[mid] < num[hi]) {
                hi = mid;
            }
            else { // when num[mid] and num[hi] are same
                hi--;
            }
        }
        return num[lo];
    }
};
*/