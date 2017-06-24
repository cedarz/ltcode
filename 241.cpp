class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> nums;
		vector<char> opers;
		
		split(input, nums, opers);
		
		vector<int> res = dfs(nums, opers, 0, nums.size() - 1);
		sort(res.begin(), res.end());
		
		return res;
    }
	
	vector<int> dfs(vector<int> & nums, vector<char> & opers, int left, int right) {
		if(left == right) return vector<int>(1, nums[left]);
		if(left + 1 == right) {
			int tmp = 0;
			if(opers[left] == '+') tmp = nums[left] + nums[right];
			if(opers[left] == '-') tmp = nums[left] - nums[right];
			if(opers[left] == '*') tmp = nums[left] * nums[right];
			return vector<int>(1, tmp);
		}
		vector<int> ret;
		vector<int> L, R;
		for(int i = left; i < right; ++i) {
			L = dfs(nums, opers, left, i);
			R = dfs(nums, opers, i + 1, right);
			for(int ll = 0; ll < L.size(); ++ll) {
				for(int rr = 0; rr < R.size(); ++rr) {
					int tmp = 0; 
					if(opers[i] == '+') tmp = L[ll] + R[rr];
					if(opers[i] == '-') tmp = L[ll] - R[rr];
					if(opers[i] == '*') tmp = L[ll] * R[rr];
					ret.push_back(tmp);
				}
			}
		}
		return ret;
	}
	
	
	void split(string & input, vector<int> & nums, vector<char> & opers) {
		int loc = 0;
		input.push_back('$');
		while(true) {
			if(input[loc] == ' ') {
				while(input[loc++] == ' ');
			} else if(input[loc] <= '9' && input[loc] >= '0') {
				int tmp = 0;
				while(input[loc] <= '9' && input[loc] >= '0') {
					tmp = tmp * 10 + input[loc] - '0';
					++loc;
				}
				nums.push_back(tmp);
			} else if(input[loc] == '$'){
				break;
			} else {
				if(input[loc] == '+' || input[loc] == '-' || input[loc] == '*') {
					opers.push_back(input[loc]);
					++loc;
				}
			}
		}
	}

};