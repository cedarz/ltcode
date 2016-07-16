class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(s.empty() || words.empty()) return vector<int>();
        map<string, int> w;
        int N = words.size();
        for(int i = 0; i != N; ++i) {
            if(w.find(words[i]) != w.end()) {
                w[words[i]]++;
            } else {
                w[words[i]] = 1;
            }
        }
        int len = words[0].size();
        int ls = s.size();
        if(ls < len * N) return vector<int>();
        vector<int> res;
        map<string, int> dp;
        for(int i = 0; i != ls; ++i) {
            string x = s.substr(i, len);
            if(w.find(x) != w.end()) {
                dp.clear();
                dp[x] = 1;
                for(int j = 1; j < N; ++j) {
                    string tmp = s.substr(i + j * len, len);
                    if(w.find(tmp) == w.end()) {
                        goto there;
                    } else {
                        if(dp.find(tmp) != dp.end()) {
                            dp[tmp] ++;
                        } else {
                            dp[tmp] = 1;
                        }
                    }
                }
                bool flag = true;
                for(map<string, int>::iterator it = w.begin(); it != w.end(); ++it) {
                    if(dp.find(it->first) != dp.end()) {
                        if(it->second != dp[it->first]) {
                            //res.push_back(i);
                            flag = false;
                            break;
                        }
                    } else {
                        flag = false;
                        break;
                    }
                }
                if(flag) res.push_back(i);
                
            }
there: int a;
        }
        return res; 
    }
};

