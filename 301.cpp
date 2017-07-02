class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        DFS(s, ')', 0);
        return res;
    }
	
	void DFS(string s, char ch, int loc) {
		int cnt = 0;
		for(int i = 0; i < s.size(); ++i) {
			if(s[i] == '(' || s[i] == ')') s[i] == ch ? ++cnt : --cnt;
			if(cnt <= 0) continue;
			
			for(int k = loc; k <= i; ++k) {
				if(s[k] == ch && (k == loc || s[k - 1] != ch)) { // 如果有连续右括号删除第一个右括号
					DFS(s.substr(0, k) + s.substr(k + 1), ch, k);
				}
			}
			return;
		}
		
		reverse(s.begin(), s.end());
		
		if(ch == ')') {
			DFS(s, '(', 0);
			return;
		} else {
			res.push_back(s);
		}
	}
private:
	vector<string> res;
};

/* BFS
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        unordered_map<string, int> visited;
        queue<string> q;
        q.push(s);
        ++visited[s];
        bool found = false;
        while (!q.empty()) {
            s = q.front(); q.pop();
            if (isValid(s)) {
                res.push_back(s);
                found = true;
            }
            if (found) continue;
            for (int i = 0; i < s.size(); ++i) {
                if (s[i] != '(' && s[i] != ')') continue;
                string t = s.substr(0, i) + s.substr(i + 1);
                if (visited.find(t) == visited.end()) {
                    q.push(t);
                    ++visited[t];
                }
            }
        }
        return res;
    }
    bool isValid(string t) {
        int cnt = 0;
        for (int i = 0; i < t.size(); ++i) {
            if (t[i] == '(') ++cnt;
            if (t[i] == ')' && cnt-- == 0) return false;
        }
        return cnt == 0;
    }
};
*/