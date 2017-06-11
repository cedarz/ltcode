class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> m(numCourses, vector<int>(numCourses, 0));
		vector<int> degrees(numCourses, 0);
		vector<int> visited(numCourses, 0);
		
		for(int i = 0; i < prerequisites.size(); ++i) {
			std::pair<int, int> & pr = prerequisites[i];
			m[pr.second][pr.first] = 1;
			degrees[pr.first]++;
		}
		
		topology(m, degrees, visited, numCourses);
		
		for(int i = 0; i < numCourses; ++i) {
			if(visited[i] == 0) return false;
		}
		return true;
    }
	
	void topology(vector<vector<int>> & m, vector<int> & degrees, vector<int> & visited, int n) {
		while(true) {
			bool flag = false;
			for(int i = 0; i < n; ++i) {
				if(degrees[i] == 0 && visited[i] == 0) {
					flag = true;
					visited[i] = 1;
					for(int j = 0; j < n; ++j) {
						if(m[i][j]) {
							m[i][j] = 0;
							--degrees[j];
						}
					}
				}
			}
			if(!flag) break;
		}
	}
};