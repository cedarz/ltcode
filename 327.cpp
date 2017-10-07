class Solution {
public:
// https://discuss.leetcode.com/topic/33738/share-my-solution
    int countRangeSum(vector<int>& nums, int lower, int upper) {
		res = 0;
        if(!nums.empty()) countRangeSum(nums, 0, nums.size() - 1, lower, upper);
		return res;
    }
	
	long long countRangeSum(vector<int> & nums, int i, int j, int lower, int upper) {
		if(i == j) {
			res += nums[i] <= upper && nums[i] >= lower ?  1 : 0;
			return nums[i];
		} else {
			int mid = (i + j) / 2;
			long long left = countRangeSum(nums, i, mid, lower, upper);
			long long right = countRangeSum(nums, mid + 1, j, lower, upper);
			//int sum = nums[mid] + nums[mid + 1];
			long long sum = left;
			for(int k = i - 1; k < mid; ++k) {
				if(k != i - 1) sum -= nums[k];
				long long tmp = sum;
				for(int m = mid + 1; m <= j; ++m) {
					tmp += nums[m];
					if(tmp <= upper && tmp >= lower)  ++res;
					//else break;
				}
			}
			return left + right;
		}
	}
private:
	int res;
};