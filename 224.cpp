#include <iostream>
#include <string>

using namespace std;

struct _expr {
	enum {NUL, EXP_P, EXP_M, INT};
	
	int type;
	int oper;
	//union {
		struct _expr * left, * right;
		int val;
	//};
	_expr() : type(NUL) {}
	_expr(int _val) : type(INT), val(_val) {}
	_expr(int _type, _expr * _l, _expr * _r) : type(_type), left(_l), right(_r) {}
};

class Solution {
public:
    int calculate(string s) {
        str = s;
		str.push_back('$');
		loc = 0;
		
		_expr * ast = exp();
		return eval(ast);
    }
	
	int eval(_expr * ast) {
		
		if(ast->type == _expr::INT) return ast->val;
		else if(ast->type == _expr::EXP_P) return eval(ast->left) + eval(ast->right);
		else if(ast->type == _expr::EXP_M) return eval(ast->left) - eval(ast->right);
	}
private:
	string str;
	int loc;
	struct _expr * expression;
	
	void consume_space() {
		while(loc < str.size() && str[loc] == ' ') ++loc;
	}
	
	void match(char ch) {
		if(str[loc] == ch) ++loc;
	}
	
	_expr * exp() {
		consume_space();
		_expr * left = T();
		consume_space();
		int type = 0;
		if(str[loc] == '+') type = 1;
		else if(str[loc] == '-') type = 2;
		else return left;
		
		_expr * res =  new _expr(type, left, nullptr);
		return R(res);
	}
	
	_expr * T() {
		_expr * ret;
		consume_space();
		if(str[loc] == '(') {
			consume_space();
			match('(');
			ret = exp();
			consume_space();
			match(')');
		} else {
			int tmp = 0;
			while(loc < str.size() && str[loc] <= '9' && str[loc] >= '0') {
				tmp = tmp * 10 + str[loc] - '0';
				++loc;
			}
			cout << "num : " << tmp << endl;
			ret = new _expr(tmp);
		}
		return ret;
	}
	
	_expr * R(_expr * left) {
		consume_space();
		_expr * ret;
		if(str[loc] == '+') {
			match('+');
			consume_space();
			_expr * e_t = T();
			consume_space();
			left->right = e_t;
			
			if(str[loc] == '+') {
				ret = R(new _expr(_expr::EXP_P, left, nullptr));
			} else if(str[loc] == '-'){
				ret = R(new _expr(_expr::EXP_M, left, nullptr));
			} else {
				ret = left;
			}
		} else if(str[loc] == '-') {
			match('-');
			consume_space();
			_expr * e_t = T();
			consume_space();
			left->right = e_t;
			
			if(str[loc] == '+') {
				ret = R(new _expr(_expr::EXP_P, left, nullptr));
			} else if(str[loc] == '-'){
				ret = R(new _expr(_expr::EXP_M, left, nullptr));
			} else {
				ret = left;
			}
		} else {
			ret = left;
		}
		return ret;
	}
	
};

int main() {
	Solution sol;
	//cout << sol.calculate("1+2-5") << endl;
	cout << sol.calculate("(1+(4+5+2)-3)+(6+8)") << endl;
	
	return 0;
}
/*
exp -> TR
R -> +TR | -TR | 
T -> (exp) | num
*/
