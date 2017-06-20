class Solution {
public:
    int calculate(string s) {
		s.push_back('$');
		vector<int> v;
		int loc = 0;
		while(loc < s.size()) {
			while(s[loc] == ' ') ++loc;
			if(s[loc] == '$') break;
			else if(s[loc] <= '9' && s[loc] >= '0') {
				int tmp = 0;
				while(loc < s.size() && s[loc] <= '9' && s[loc] >= '0') {
					tmp = tmp * 10 + s[loc] - '0';
					++loc;
				}
				v.push_back(tmp);
			} else {
				switch (s[loc]) {
					case '+': v.push_back(-1); break;
					case '-': v.push_back(-2); break;
					case '*': v.push_back(-3); break;
					case '/': v.push_back(-4); break;
				}
			}
		}
		return eval(v);
    }
	
	int eval(vector<int> & v) {
		stack<int> stk;
		
		int loc = 0;
		stk.push(v[loc]);
		++loc;
		
		while(loc < v.size()) {
			if(v[loc] == -1 || v[loc] == -2) {
				int sig = v[loc] == -1 ? 1 : -1;
				++loc;
				stk.push(sig * v[loc]);
				++loc;
			} else {
				int tmp = stk.top();
				stk.pop();
				int oper = v[loc];
				++loc;
				if(oper == -3) stk.push(tmp * v[loc]);
				else stk.push(tmp / v[loc]);
				++loc;
			}
		}
		
		int ret = 0;
		while(!stk.empty()) {
			ret += stk.top();
			stk.pop();
		}
		return ret;
	}
	
};