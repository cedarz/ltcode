class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>> E(n, vector<int>());
		
		vector<int> d(n, 0);
		vector<int> vis(n, 0);
		for(auto e : edges) {
			E[e.first].push_back(e.second);
            E[e.second].push_back(e.first);
			d[e.first]++;
			d[e.second]++;
		}
		
        int cnt = n;
        vector<int> tmp;
		while(true) {
			if(cnt <= 2) {
				for(int i = 0; i < n; ++i) {
					if(vis[i] == 0) tmp.push_back(i);
				}
				break;
			}
            
			for(int i = 0; i < n; ++i) {
				if(d[i] == 1 && vis[i] == 0) {
                    cout << "del " << i << endl;
					vis[i] = 1;
                    --cnt;
					vector<int> & es = E[i];
					for(auto e : es) {
						d[i]--;
						d[e]--;
					}
				}
			}
			
		}
		return tmp;
    }
	

};