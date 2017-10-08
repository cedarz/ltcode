#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	struct cmp {
		bool operator()(pair<int, int> a, pair<int, int> b) {
			return a.second > b.second;
		}
	};
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
		priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
		
		for(auto n : nums) {
			m[n]++;
		}
		for(auto pp : m) {
			if(q.size() < k) {
				q.push(pp);
			} else {
				cmp cp;
				if(!cp(q.top(), pp)) {
					q.pop();
					q.push(pp);
				}
			}
		}
		vector<int> res;
		while(!q.empty()) {
			res.push_back(q.top().first);
			cout << q.top().first << endl;
			q.pop();
		}
		return res;
    }
};

int main() {
	vector<int> a({1,1,1,2,2,3, 3,4,4,4});
	for(auto i : Solution().topKFrequent(a, 2)) {
		cout << i << " ";
	}cout << endl;
	return 0;
}
