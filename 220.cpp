struct node {
	int value;
	int loc;
	
	node(int _v, int _l) : value(_v), loc(_l) {}
	
	bool operator< (node b) {
		return value < b.value;
	}
};

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		if(nums.empty()) return false;
        vector<node> v;
		for(int i = 0; i < nums.size(); ++i) {
			node tmp(nums[i], i);
			v.push_back(tmp);
		}
		sort(v.begin(), v.end());

		for(int i = 0; i < nums.size() - 1; ++i) {
			for(int j = i + 1; j < nums.size(); ++j) {
				long long tmp = (long long)v[j].value - (long long)v[i].value;
				if(tmp <= t) {
					if(abs(v[j].loc - v[i].loc) <= k) return true;
				} else {
					break;
				}
			}
		}
		return false;
    }
};