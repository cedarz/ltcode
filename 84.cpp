#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
		if(heights.empty()) return 0;
		int sz = heights.size();
		
		heights.push_back(0);
		stack<size_t> stk;
		
		stk.push(0);
		int res = 0;
		for(size_t i = 1; i <= sz; ++i) {
			if(heights[i] >= heights[stk.top()]) {
				stk.push(i);
			} else {
				while(!stk.empty() && heights[stk.top()] > heights[i]) {
					int tmp = heights[stk.top()];
					stk.pop();
					int loc = stk.empty() ? -1 : stk.top();
					std::cout << tmp << " " << i << " " << loc << " " << (i - loc) << std::endl;
					res = std::max(res,  tmp * int(i - loc - 1));
				}
				stk.push(i);
			}
		}
        return res;
    }
};

int main() {
	int a[] = {4,2,0,3,2,5};
	vector<int> v(a, a + 6);
	
	Solution s;
	std::cout << s.largestRectangleArea(v) << std::endl;
	
	return 0;
}
