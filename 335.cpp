//https://discuss.leetcode.com/topic/38635/the-best-submission-in-c-searching-for-the-crossing-patterns-is-the-key
class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        for(int i = 3; i < x.size(); ++i) {
			if(x[i] >= x[i - 2] && x[i - 1] <= x[i - 3]) return true;
			if(i >= 4 && x[i - 1] == x[i - 3] && x[i] >= x[i - 2] - x[i - 4]) return true;
			if(i > 4 && x[i - 1] <= x[i - 3] && x[i] >= x[i - 2] - x[i - 4] && 
				x[i - 3] <= x[i - 5] + x[i - 1] && x[i - 2] > x[i - 4]) return true;
			
		}
		return false;
    }
};