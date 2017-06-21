#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class MonoQueue {
public:
	void push(int x) {
		data.push_back(x);
		while(!aux.empty() && x > aux.back()) {
			aux.pop_back();
		}
		aux.push_back(x);
	}
	
	int max() {
		return aux.front();
	}
	
	void pop() {
		int tmp = data.front();
		data.pop_front();
		if(tmp == aux.front()) {
			aux.pop_front();
		}
	}
	
private:
	deque<int> data, aux;
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> ret;
        for(int i = 0; i < k - 1; ++i) {
			mq.push(nums[i]);
		}
		for(int i = k - 1; i < nums.size(); ++i) {
			mq.push(nums[i]);
			ret.push_back(mq.max());
			mq.pop();
		}
		return ret;
    }
private:
	MonoQueue mq;
};

int main() {
	Solution sol;
	vector<int> v = {1,3,1,2,0,5};
	vector<int> r = sol.maxSlidingWindow(v, 3);
	
	for(int i = 0; i < r.size(); ++i) {
		cout << r[i] << " ";
	}
	cout << endl;
	return 0;
}