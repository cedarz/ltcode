// https://discuss.leetcode.com/topic/35976/7-lines-easy-java-solution
class Solution {
public:
    bool isValidSerialization(string preorder) {
        int pos = 0;
		//int i = 0;
		//int tmp = 0;
		vector<int> ns;
		while(pos < preorder.size()) {
			int start = pos;
			while(pos < preorder.size() && preorder[pos] != ',') ++pos;
			
			if(preorder[pos] == '#') ns.push_back(0);
			else ns.push_back(1);
			if(pos != preorder.size()) ++pos;
		}
		pos = 0;
		isValidSerialization(ns, pos);
		return pos == ns.size();
    }
	
	bool isValidSerialization(vector<int> & preorder, int & pos) {
		if(preorder[pos] != 0) {
			++pos;
			bool left = isValidSerialization(preorder, pos);
			bool right = isValidSerialization(preorder, pos);
			return left && right;
		} else {
			++pos;
			return true;
		}
	}
};