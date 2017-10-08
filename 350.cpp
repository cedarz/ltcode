class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int> s1, s2;
		for(auto n : nums1) {
			s1[n]++;
		}
		for(auto n : nums2) {
			s2[n]++;
		}
		
		vector<int> res;
		for(auto p : s1) {
			if(s2.find(p.first) != s2.end()) {
				//res.push_back(i);
				for(int i = 0; i < min(s1[p.first], s2[p.first]); ++i) {
					res.push_back(p.first);
				}
			}
		}
		return res;
    }
};