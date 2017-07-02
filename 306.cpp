class Solution {
public:
    bool isAdditiveNumber(string num) {
        //cout << add("1123", "12344") << endl;
		if(num.size() < 3) return false;
		
		for(int i = 0; i <= (num[0] == '0' ? 0 : num.size() / 2); ++i) {
			for(int j = i + 1; num[i + 1] == '0' ? j <= i + 1 : num.size() - j - 1 >= max(i + 1, j - i); ++j) {
				string a = num.substr(0, i + 1);
				string b = num.substr(i + 1, j - i);
				//cout << a << " " << b << endl;
				bool flag = true;
				
				string left = num.substr(j + 1);
				while(true) {
					string c = add(a, b);
					if(c != left.substr(0, c.size())) break;
					else {
						if(c.size() == left.size()) return true;
						left = left.substr(c.size());
						swap(a, b);
						swap(b, c);
					}
				}
			}
		}
        return false;
    }
	
	string add(string a, string b) {
		if(a.size() < b.size()) return add(b, a);
		
		int carry = 0;
		string ret = "";
		int i, j;
		for(i = a.size() - 1, j = b.size() - 1; i >= 0 && j >= 0; --i, --j) {
			int tmp = (a[i] - '0') + (b[j] - '0') + carry;
			ret = string(1, '0' + tmp % 10) + ret;
			carry = tmp / 10;
		}
		
		for(; i >= 0; --i) {
			int tmp = (a[i] - '0') + carry;
			ret = string(1, '0' + tmp % 10) + ret;
			carry = tmp / 10;
		}
		
		if(carry > 0) {
			ret = string(1, carry + '0') + ret;
		}
		
		return ret;
	}
};