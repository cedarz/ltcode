class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
		int a, b;
		for(int i = 0; i < tokens.size(); ++i) {
			string & tmp = tokens[i];
			switch (tmp[0]){
				case '+':
				case '-':
				case '*':
				case '/':
					b = stk.top();
					stk.pop();
					a = stk.top();
					stk.pop();
					switch (tmp[0]) {
						case '+': stk.push(a + b); break;
						case '-': stk.push(a - b); break;
						case '*': stk.push(a * b); break;
						case '/': stk.push(a / b); break;
					}
					break;
				default:
					stk.push(str2int(tmp));
					break;
			}
		}
		return stk.top();
    }
private:
	int str2int(string & s) {
		int res = 0;
		int sign = 1;
		int i = 0;
		if(s[0] == '-') {
			sign = -1;
			i = 1;
		}
		
		if(s[0] == '+') {
			sign = 1;
			i = 1;
		}
		
		for(; i < s.size(); ++i) {
			res = res * 10 + (s[i] - '0');
		}
		return res * sign;
	}
};