string d_0_19[] = {
	"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", 
	"Sixteen", "Seventeen", "Eighteen", "Nineteen"
};

string tens[] = { 
	"Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
};

string hunds[] {
	"", "Thousand", "Million", "Billion"
};

class Solution {
public:
    string numberToWords(int num) {
        if(num < 0) return "";
		if(num == 0) return "Zero";
		
		string ret("");
		int cnt = 0;
		while(num) {
			int tmp = num % 1000;
			string s = hun_to_string(tmp);
			if(ret.empty()) {
			    if(!s.empty())
			        ret = s + (cnt > 0 ? string(" ") + hunds[cnt] : string(""));
			}
			else {
			    
			    if(!s.empty()) {
			        ret = s + " " + hunds[cnt] + " " + ret;
			    }
			}
			++cnt;
			num /= 1000;
			
		}
		return ret;
    }
	
	string hun_to_string(int k) {
		string ret("");
		int huns = k / 100;
		if(huns > 0) {
			ret += d_0_19[huns] + " " + "Hundred";
		}
		int n = k % 100;
		if(!ret.empty() && n > 0) ret += " ";
		if(n < 20 && n > 0) {
			ret += d_0_19[n];
		} else if(n >= 20) {
			ret += tens[n / 10] + (n % 10 ? string(" ") + d_0_19[n % 10] : ""); 
		}
		cout << k <<" " << ret << endl;
		return ret;
	}
};