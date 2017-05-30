class Solution {
public:
    int maximumGap(vector<int>& nums) {
        const int L = nums.size();
		if(L < 2) return 0;
		
		const int base = 10;
		vector<list<int>> buckets(10);
		
		int max_elem = *max_element(nums.begin(), nums.end());
		
		for(long long i = 1; i <= max_elem; i *= base) {
			for(int j = 0; j < L; ++j) {
				int idx = (long long)nums[j] / i % base;
				buckets[idx].push_back(nums[j]);
			}
			
			int k = 0;
			 for (int j = 0; j < buckets.size(); j++) {
				for(auto item : buckets[j]) {
					nums[k++] = item;
				}
				buckets[j].clear();
			}
		}
		
		int gap = 0;
		for(int i = 1; i < L; ++i) {
			gap = max(gap, nums[i] - nums[i - 1]);
		}
		
		return gap;
    }
};