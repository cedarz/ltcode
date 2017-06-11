class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return kth(nums, 0, nums.size() - 1, nums.size() - k);
    }
	
	int kth(vector<int> & a, int left, int right, int k) {
		int i = left, j = right;
		int tmp = a[i];
		
		while(i < j) {
			while(a[j] >= tmp && i < j) --j;
			swap(a[i], a[j]);
			while(a[i] <= tmp && i < j) ++i;
			swap(a[i], a[j]);
		}
		if(i == k) return tmp;
		else {
			a[i] = tmp;
			if(k > i) return kth(a, i + 1, right, k);
			else if(k < i) return kth(a, left, i - 1, k);
		}
	}
};