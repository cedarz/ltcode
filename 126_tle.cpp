class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        sz = wordList.size();
		Len = beginWord.size();
		res.clear();
		
		vector<vector<int>> v(sz + 1, vector<int>(sz + 1, 0));
		
		for(int i = 0; i < sz; ++i) {
			if(one_char_distance(beginWord, wordList[i])) {
				v[0][i + 1] = 1;
				v[i + 1][0] = 1;
			}
		}
		
		for(int i = 0; i < sz; ++i) {
			for(int j = i + 1; j < sz; ++j) {
				if(one_char_distance(wordList[i], wordList[j])) {
					v[i + 1][j + 1] = 1;
					v[j + 1][i + 1] = 1;
				}
			}
		}
		
		
		vector<string> path;
		path.push_back(beginWord);
		vector<int> visited_bfs(sz + 1, 0);
		visited_bfs[0] = 1;
		
		min_p = bfs(v, wordList, visited_bfs, 0, endWord);
		
		vector<int> visited_dfs(sz + 1, 0);
		visited_dfs[0] = 1;
		dfs(v, path, wordList, visited_dfs, 0, endWord);
		
		
		return res;

    }
	
	bool one_char_distance(string & first, string & second) {
		int cnt = 0;
		for(int i = 0; i < Len; ++i) {
			if(first[i] != second[i]) {
				++cnt;
				if(cnt >= 2) {
					return false;
				}
			}
		}
		if(cnt == 1) {
			return true;
		} else {
			return false;
		}
	}
	int bfs(vector<vector<int>> & v, vector<string> & wls,
		vector<int> & visited, int k, string & endW) {
		int length = 1;
		vector<int> level;
		
		vector<int> next;
		next.push_back(k);
		bool flag = false;
		while(!flag) {
			++length;
			swap(level, next);
			next.clear();
			for(int k = 0; k < level.size(); ++k) {
				for(int i = 0; i <= sz; ++i) {
					if(visited[i] != 1 && v[level[k]][i] == 1){
						next.push_back(i);
						visited[i] = 1;
						if(wls[i - 1] == endW) {
							flag = true;
							//break;
						}
					}
				}
			}
			if(next.empty()) {
				length = 0;
				break;
			}
		}
		return length;
		
	}
	void dfs(vector<vector<int>> & v, vector<string> & path, vector<string> & wls,
				vector<int> & visited, int k, string & endWord) {
		for(int i = 0; i <= sz; ++i) {
			if(visited[i] != 1 && v[k][i] == 1){
				if(path.size() + 1 > min_p) break;
				path.push_back(wls[i - 1]);
				visited[i] = 1;
				if(wls[i - 1] == endWord) {
					cout << "here" << endl;
					res.push_back(path);
				} else {
					dfs(v, path, wls, visited, i, endWord);
				}
				path.pop_back();
				visited[i] = 0;
			}
		}
	}
	
private:
	int Len;
	int sz;
	int min_p;
	vector<vector<string>> res;
};


