class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sum = 0;
		int left = 0, right = 0;
		while(sum < s && right < nums.size()) {
			sum += nums[right++];
		}
		if(sum < s) return 0;
		
		int tmp = right - left;
		int res = tmp;
		while(true) {
			while(true) {
				if(sum - nums[left] >= s) {
					sum -= nums[left];
					++left;
					--tmp;
				} else break;
			}
			res = min(res, tmp);
			if(right < nums.size()) {
				sum += nums[right++];
				++tmp;
			} else {
				break;
			}
		}
		return res;
    }
};

/*
int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size(), start = 0, sum = 0, minlen = INT_MAX;
        for (int i = 0; i < n; i++) { 
            sum += nums[i]; 
            while (sum >= s) {
                minlen = min(minlen, i - start + 1);
                sum -= nums[start++];
            }
        }
        return minlen == INT_MAX ? 0 : minlen;
    }
*/