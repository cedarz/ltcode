class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        map<string, vector<string>> ms;
		//map<string, int> vis;
		Len = tickets.size();
		for(auto pss : tickets) {
			ms[pss.first].push_back(pss.second);
		}
		for(auto & iter : ms) {
			//vis[iter.first] = 0;
			auto & it = iter.second;
			sort(it.begin(), it.end());
		}
		
		vector<string> res;
        //res.push_back("JFK");
		dfs(ms, res, "JFK");
		reverse(res.begin(), res.end());
		return res;
    }
	
	void dfs(map<string, vector<string>> & ms, vector<string> & res, string from) {
		auto & vps = ms[from];
        //cout << from << " " << vps.size() <<endl;
        
        //if(res.size() == Len + 1) return;
		//for(int i = 0; i < vps.size(); ++i) {
            //cout << i << " " << vps[0] << endl;
        while(!vps.empty()) {
			string tmp = vps[0];
            vps.erase(vps.begin());
            dfs(ms, res, tmp);
		} 
        res.push_back(from);
	}
	
private:
	int Len;
};