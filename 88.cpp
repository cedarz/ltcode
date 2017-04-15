class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> res;
		int i, j;
		for(i = 0, j = 0; i < m && j < n; ) {
			if(nums1[i] < nums2[j]) {
				res.push_back(nums1[i]);
				++i;
			} else {
				res.push_back(nums2[j]);
				++j;
			}
		}
		if(i < m) {
			for(; i < m; ++i) {
				res.push_back(nums1[i]);
			}
		} else {
			for(; j < n; ++j) {
				res.push_back(nums2[j]);
			}
		}
		swap(nums1, res);
    }
};