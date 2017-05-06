class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        sz = wordList.size();
		Len = beginWord.size();
		res.clear();
		
		vector<string>::iterator it = std::find(wordList.begin(), wordList.end(), endWord);
		if(it == wordList.end()) return res;
		
		
		
		//vector<vector<int>> v(sz + 1, vector<int>(sz + 1, 0));
		
		for(int i = 0; i < sz; ++i) {
			if(one_char_distance(beginWord, wordList[i])) {
				//v[0][i + 1] = 1;
				//v[i + 1][0] = 1;
				tree[0].push_back(i + 1);
				tree[i + 1].push_back(0);
			}
		}
		
		for(int i = 0; i < sz; ++i) {
			for(int j = i + 1; j < sz; ++j) {
				if(one_char_distance(wordList[i], wordList[j])) {
					//v[i + 1][j + 1] = 1;
					//v[j + 1][i + 1] = 1;
					tree[i + 1].push_back(j + 1);
					tree[j + 1].push_back(i + 1);
				}
			}
		}
		
		vector<string> path;
		path.push_back(beginWord);
		vector<int> level(sz + 1, 0);
		level[0] = 1;
		vector<int> visited(sz + 1, 0);
		visited[0] = 1;
		
		bfs(tree, level, 0, visited);
		min_p = level[it - wordList.begin() + 1];
		//dfs(tree, path, wordList, level, 0, endWord);
		//return res;
		
		return min_p;
    }
	
	//void bfs(vector<vector<int>> & v, vector<int> & level, int k, vector<int> & visited) {
	void bfs(unordered_map<int, vector<int>> & v, vector<int> & level, 
			int k, vector<int> & visited) {
		level[k] = 1;
		queue<int> q;
		q.push(k);
		
		while(!q.empty()) {
			int next = q.front();
			q.pop();
			//for(int i = 0; i <= sz; ++i) {
			if(v.find(next) == v.end()) continue;
			vector<int> & vn = v[next];
			for(int i = 0; i < vn.size(); ++i) {
				int idx = vn[i];
				if(visited[idx] != 1) {
					level[idx] = level[next] + 1;
					visited[idx] = 1;
					q.push(idx);
				}
			}
		}
	}
	void dfs(unordered_map<int, vector<int>> & v, vector<string> & path, vector<string> & wls,
				vector<int> & level, int k, string & endWord) {
		//for(int i = 0; i <= sz; ++i) {
		if(v.find(k) == v.end()) return;
		vector<int> & vn = v[k];
		for(int idx = 0; idx < vn.size(); ++idx) {
			int i = vn[idx];
			if(level[i] == level[k] + 1){
				if(1 + path.size() > min_p) break; 
				path.push_back(wls[i - 1]);
				
				if(wls[i - 1] == endWord) {
					//cout << "here" << endl;
					res.push_back(path);
				} else {
					dfs(v, path, wls, level, i, endWord);
				}
				path.pop_back();
			}
		}
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
	
private:
	int Len;
	int sz;
	int min_p;
	vector<vector<string>> res;
	unordered_map<int, vector<int>> tree;
};


