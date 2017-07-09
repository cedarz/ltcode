class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>> E(n, vector<int>());
		for(auto e : edges) {
			E[e.first].push_back(e.second);
            E[e.second].push_back(e.first);
		}
		vector<int> len(n, 0);
        int MIN = INT_MAX;
		for(int i = 0; i < n; ++i) {
			len[i] = bfs(i, E, n);
            MIN = min(MIN, len[i]);
            //cout << len[i] << endl;
		}
		
		//sort(len.begin(), len.end());
		
		vector<int> res;
		for(int i = 0; i < n; ++i) {
			if(len[i] == MIN) res.push_back(i);
		}
		return res;
    }
	
	int bfs(int k, vector<vector<int>> & E, int n) {
		vector<int> v(n, 0);
		
		vector<int> level;
		level.push_back(k);
		v[k] = 1;
		int h = 0;
		while(!level.empty()) {
			++h;
			vector<int> tmp;
			for(auto p : level) {
				vector<int> & es = E[p];
				for(auto q : es) {
					if(!v[q]) {
						tmp.push_back(q);
						v[q] = 1;
					}
				}
			}
			swap(level, tmp);
		}
		return h;
	}
};