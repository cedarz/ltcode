#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int numDistinct(string s, string t) {
		int lt = t.size();
		int ls = s.size();
		vector<vector<int> > path(lt + 1, vector<int>(ls + 1, 0));
		
		for(int i = 0; i <= ls; ++i) {
			path[0][i] = 1;
		}
		
		for(int i = 1; i <= lt; ++i) {
			for(int j = i;j <= ls; ++j) {
				path[i][j] = path[i][j - 1];
				if(t[i - 1] == s[j - 1]) path[i][j] += path[i - 1][j - 1];
			}
		}
		return path[lt][ls];
	}
public:
    int numDistinct_(string s, string t) {
		
		int ls = s.size(); 
		int lt = t.size();
		vector<vector<int> > mat(lt + 1, vector<int>(ls + 1, 0));
		dp(mat, s, t);
		cout << dfs(mat, 3, 4) << endl;
		if(mat[lt][ls] != lt) return 0;
		else return dfs(mat, lt, ls);
    }
	
	void dp(vector<vector<int> > & v, string & s, string & t) {
		int ls = s.size();
		int lt = t.size();
		for(int i = 1; i <= lt; ++i) {
			for(int j = 1; j <= ls; ++j) {
				if(t[i - 1] == s[j - 1]) v[i][j] = 1 + v[i - 1][j - 1];
				else {
					v[i][j] = max(v[i - 1][j], v[i][j - 1]);
				}
                cout << v[i][j] << " ";
			}
            cout << endl;
		}
	}
	
	int dfs(vector<vector<int> > & v, int lt, int ls) {
		if(v[lt][ls] == 1) return 1;
		else {
			return (lt - 1 >= 0 && ls - 1 >= 0 && v[lt - 1][ls - 1] == v[lt][ls] - 1 ? dfs(v, lt - 1, ls - 1) : 0) +  
			 (lt - 1 >= 0 &&v[lt - 1][ls] == v[lt][ls] ? dfs(v, lt - 1, ls) : 0) +
				   (ls - 1 >= 0 && v[lt][ls - 1] == v[lt][ls] ? dfs(v, lt, ls - 1) : 0);
		}
	}
};

int main() {
	Solution s;
	cout << s.numDistinct("rabbbit", "rabbit") << endl;;
	
	return 0;
}
