class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>> E(n, vector<int>());
		
		vector<int> d(n, 0);
		for(auto e : edges) {
			E[e.first].push_back(e.second);
            E[e.second].push_back(e.first);
			d[e.first]++;
			d[e.second]++;
		}
		
		vector<int> level;
		for(int i = 0; i < n; ++i) {
			if(d[i] == 1) level.push_back(i);
		}
		while(level.size() > 2) {
			vector<int> tmp;
			for(auto p : level) {
				vector<int> & es = E[i];
				for(auto e : es) {
					d[i]--;
					d[e]--;
					if(d[e] == 1) tmp.push_back(e);
				}
			}
			swap(level, tmp);
		}
		return level;
    }
	

};