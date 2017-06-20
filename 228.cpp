#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
		vector<string> v;
		if(nums.empty()) return v;
		
		int low = nums[0], high = nums[0];
		for(int i = 1; i < nums.size(); ++i) {
			if(nums[i] == high + 1) {
				++high;
			} else {
				stringstream ss;
				if(low != high) ss << low << "->" << high;
				else ss << low;
				v.push_back(ss.str());
				low = nums[i];
				high = nums[i];
			}
		}
		stringstream ss;
		if(low != high) ss << low << "->" << high;
		else ss << low;
		v.push_back(ss.str());
		
		return v;
    }
};

