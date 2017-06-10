#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

//sort(begin(arr), end(arr), [](string &s1, string &s2){ return s1+s2>s2+s1; });

bool comp(const string & a, const string & b) {
	size_t i = 0, j = 0;
	while(i < a.size() && j < b.size()) {
		if(a[i] < b[j]) {
			return true;
		} else if(a[i] > b[j]){
			return false;
		}
		++i;
		++j;
	}
	if(i == a.size() && j == b.size()) return true;
	if(i == a.size()) {
		//return a < b.substr(a.size());
        return comp(a, b.substr(a.size()));
	} else if(j == b.size()) {
		//return a.substr(b.size()) < b;
        return comp(a.substr(b.size()), b);
	}
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> vs;
        unordered_map<string, int> m;
		for(int i = 0; i < nums.size(); ++i) {
		    string tmp = to_string(nums[i]);
		    if(m.find(tmp) != m.end()) m[tmp]++;
			else {
			    m[tmp] = 1;
			    vs.push_back(tmp);
			}
		}
		sort(vs.begin(), vs.end(), comp);
		
		cout << vs.size() << endl;
		
		bool all_zero = true;
		string & big = vs[vs.size() - 1];
		for(int z = 0; z < big.size(); ++z) {
		    if(big[z] != '0') {
		        all_zero = false;
		        break;
		    }
		}
		if(all_zero) return string("0");
		
		string ret = "";
		
		for(int i = vs.size() - 1; i >= 0; --i) {
			for(int j = 0; j < m[vs[i]]; ++j) {
			    ret += vs[i];
			}
		}
		return ret;
    }
};

int main() {
	vector<int> s = {41,23,87,55,50,53,18,9,39,63,35,33,54,25,26,49,74,61,32,81,97,99,38,96,22,95,35,57,80,80,16,22,17,13,89,11,75,98,57,81,69,8,10,85,13,49,66,94,80,25,13,85,55,12,87,50,28,96,80,43,10,24,88,52,16,92,61,28,26,78,28,28,16,1,56,31,47,85,27,30,85,2,30,51,84,50,3,14,97,9,91,90,63,90,92,89,76,76,67,55};
	Solution sol;
	cout << sol.largestNumber(s) << endl;
    s = {8, 8887};
	cout << sol.largestNumber(s) << endl;
    
	return 0;
}
