class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int start = 0;
        int cnt = 0;
        int len = 0;
        int sz = words.size();
        if(sz == 0) return vector<string>();
        vector<string> res;
        for(int i = 0; i < sz; ++i) {
            if(cnt == 0) { 
                start = i;
            }
            
            if(cnt > 0) ++len; // one space at least
            if(len + words[i].size() <= maxWidth) {
                ++cnt;
                len += words[i].size();
                if(start + cnt == sz) {
                    goto COMBINE;
                }
            } else {
                --i;
                if(cnt > 0) --len;
                goto COMBINE;
            }
            
        
            continue;
COMBINE:
            cout << len << " : " << start << " " << cnt << endl;
            int spaces = maxWidth - len + cnt - 1;
            int div = cnt > 1 ? spaces / (cnt - 1) : spaces;
            int ram = cnt > 1 ? spaces % (cnt - 1) : 1;
        
            cout << spaces << " " << div << " / " << ram << endl;
            string just("");
            if(start + cnt == sz) {
                int last = spaces - cnt + 1;
                for(int cum = 0; cum < cnt; ++ cum) {
                    if(cum == cnt - 1) {
                        just += words[start + cum] + string(last, ' ');
                        break;
                    }
                    just += words[start + cum];
                    if(cnt > 1) {
                        just += " ";
                    }
                }
                len = 0;
                cnt = 0;
                res.push_back(just);
                break;
            }
            if(cnt == 1) {
                just += words[start] + string(div, ' ');
            } else {
            for(int cum = 0; cum < cnt; ++cum) {
                if(cum == cnt - 1) {
                    just += words[start + cum];
                    break;
                }
                if(cum < ram) {
                    just += words[start + cum] + string(div + 1, ' ');
                } else {
                    just += words[start + cum] + string(div, ' ');
                }
            }
            }
            len = 0;
            cnt = 0;
            res.push_back(just);
        }
        return res;       
    }
};


