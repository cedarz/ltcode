class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1, s2;
		for(auto n : nums1) {
			s1.insert(n);
		}
		for(auto n : nums2) {
			s2.insert(n);
		}
		
		vector<int> res;
		for(auto i : s1) {
			if(s2.find(i) != s2.end()) {
				res.push_back(i);
			}
		}
		return res;
    }
};