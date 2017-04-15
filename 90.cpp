#include <map>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
		if(nums.empty()) return vector<vector<int> >();
		
		int sz = nums.size();
        map<int, int> m;
		for(int i = 0; i < sz; ++i) {
			if(m.find(nums[i]) == m.end()) m[nums[i]] = 1;
			else m[nums[i]]++;
		}
		vector<int> num, cnt;
		for(map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
			num.push_back(it->first);
			cnt.push_back(it->second);
		}
		
		//cout << num.size() << endl;
		vector<int> tmp;
		
		dfs(num, cnt, 0, tmp);
		
		return res;
		
    }
    
    void print() {
        for(int i = 0; i < res.size(); ++i) {
            for(int j = 0; j < res[i].size(); ++j) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
    }
	
private:
	vector<vector<int> > res;
	
	void dfs(vector<int> &num, vector<int> &cnt, int loc, vector<int> & tmp) {
		if(loc == num.size()) {
			res.push_back(tmp);
            return;
		}
		
		for(int i = 0; i <= cnt[loc]; ++i) {
            //cout << loc << " " << num[loc] << endl;
			for(int j = 0; j < i; ++j) {
				tmp.push_back(num[loc]);
			}
			dfs(num, cnt, loc + 1, tmp);
			for(int j = 0; j < i; ++j) {
				tmp.pop_back();
			}
		}
	}
	
};

int main() {
    int a[] = {1, 2, 2};
    vector<int> vv(a, a + 3);
    
    Solution s;
    s.subsetsWithDup(vv);
    s.print();
    return 0;
}
