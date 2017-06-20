class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n1 = 0, n2 = 0;
		int cnt1 = 0, cnt2 = 1;
		
		for(auto n : nums) {
			if(n == n1) ++cnt1;
			else if(n == n2) ++cnt2;
			else if(cnt1 == 0) {
				n1 = n;
				cnt1 = 1;
			} else if(cnt2 == 0) {
				n2 = n;
				cnt2 = 1;
			} else {
				--cnt1;
				--cnt2;
			}
		}
		
		cnt1 = 0, cnt2 = 0;
		for(auto n : nums) {
			if(n == n1) ++cnt1;
			else if(n == n2) ++cnt2;
		}
		
		vector<int> v;
		if(cnt1 > nums.size() / 3) v.push_back(n1);
		if(cnt2 > nums.size() / 3) v.push_back(n2);
		
		return v;
    }
};
/*Boyer-Moore Majority Vote algorithm */