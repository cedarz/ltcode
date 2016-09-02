class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            m.clear();
            v.clear();
            int len = strs.size();
            for(int i = 0; i < len; ++i) {
                string s(strs[i]);
                sort(s.begin(), s.end());
                m[s].push_back(strs[i]);
            }
            map<string, vector<string>>::iterator mip = m.begin();
            for(; mip != m.end(); ++mip) {
                v.push_back(mip->second);
            }
            return v;
        }
    private:

        vector<vector<string>> v;
        map<string, vector<string>> m;
};

