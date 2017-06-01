class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator % denominator) return to_string(numerator / denominator);
		
		int g = gcd(abs(numerator), abs(denominator));
		return fractionToDecimal_(numerator / g, denominator / g);
    }
	
	string fractionToDecimal_(int a, int b) {
		int sign = (a > 0 ? 1 : -1) * (b > 0 ? 1 : -1);
		string ret = "";
		//int k = 0;
		if(sign == -1) {
			ret += "-";
			//++k;
		}
		
		long long  remainder = abs(a);
		long long  denom = abs(b);
		
		ret += to_string(remainder / denom);
		remainder = remainder % denom;
		
		unordered_map<long long, int> m;
		
		while(true) {
			if(remainder == 0) break;
			
			remainder = remainder * 10;
			
			if(m.find(remainder) != m.end()) {
				ret.insert(m[remainder], 1, '(');
				ret += string(")");
				//return ret;
				break;
			}
			
			m[remainder] = ret.size();
			ret += to_string(remainder / denom);
			remainder = remainder % denom;
		}
		return ret;
	}
	string int2str(int num) {
		char res[20];
		int k = 0;
		while(num) {
			res[k++] = num % 10;
			num /= 10;
		}
		res[k] = '\0';
		for(int i = 0, j = k - 1; i < j; ++i, --j) {
			swap(res[i], res[j]);
		}
		return string(res);
	}
	
	int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	}
	
};