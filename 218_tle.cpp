#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <fstream>
#include <ctime>

using namespace std;

#define LEFT(i) (i<<1)
#define RIGHT(i) ((i<<1) + 1)

struct _snode {
	int left, right;
	int height;
};

struct _edge {
	int left, right;
	int height;
	_edge(int _l, int _r, int _h) : left(_l), right(_r), height(_h) {}
	
	bool operator< (_edge b) {
		if(left < b.left) return true;
		else if(left == b.left) {
			return right < b.right;
		} else return false;
	}
	
	bool operator==(_edge b) {
		return left == b.left && right == b.right;
	}
	
	bool operator> (_edge b) {
		return !(*this < b || *this == b);
	}
};

class SegTree {
public:
	SegTree(int num) : tree(num * 4, {0, 0, 0}){
		//
	}
	
	void build(int idx, int left, int right) {
		tree[idx].left = left;
		tree[idx].right = right;
		
		if(left == right) return;
		
		int mid = (left + right) / 2;
		build(LEFT(idx), left, mid);
		build(RIGHT(idx), mid + 1, right);		
	}
	
	void PushDown(int idx) {
		if(tree[idx].left == tree[idx].right) return;
		if(tree[LEFT(idx)].height < tree[idx].height) {
			tree[LEFT(idx)].height = tree[idx].height;
		}
		if(tree[RIGHT(idx)].height < tree[idx].height) {
			tree[RIGHT(idx)].height = tree[idx].height;
		}
		//tree[idx].height = 0; //向下更新
	}
	
	void update(int idx, int left, int right, int height) {
		//printf("%d %d %d %d\n", idx, left, right, height);
		if(left <= tree[idx].left && right >= tree[idx].right) {
			tree[idx].height = max(tree[idx].height, height);
			return;
		}
		//if(tree[idx].left == tree[left].right) return;
		PushDown(idx);
		int mid = (tree[idx].left + tree[idx].right) / 2;
		if(left <= mid) { // <= : !important
			update(LEFT(idx), left, right, height);
		}
		if(right > mid) {
			update(RIGHT(idx), left, right, height);
		}
	}
	
	void query(vector<int> & H, unordered_map<int, int> & M) {
		queue<int> q;
		q.push(1);
		while(!q.empty()) {
			int idx = q.front();
			q.pop();
			PushDown(idx);
			if(tree[idx].left == tree[idx].right) {
				H[tree[idx].left] = tree[idx].height;
				continue;
			}
			q.push(LEFT(idx));
			q.push(RIGHT(idx));
		}
	}
	
private:
	vector<_snode> tree;
};


class Solution {
public:
	vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
		vector<pair<int, int>> ret;
		if(buildings.empty()) return ret;
		
		vector<int> endpoints;
		unordered_map<int, int> hashIdx; // end point -> idx
		unordered_map<int, int> hashPoint; // idx -> end point
		//vector<_edge> edges;
		for(int i = 0; i < buildings.size(); ++i) {
			endpoints.push_back(buildings[i][0]);
			endpoints.push_back(buildings[i][1]);
			//edges.push_back(_edge(buildings[i][0], buildings[i][1], buildings[i][2]));
		}
		sort(endpoints.begin(), endpoints.end());
		//sort(edges.begin(), edges.end());
		int idx = 0;
		//discrete 
		for(auto p : endpoints) {
			if(hashIdx.find(p) == hashIdx.end()) {
				hashIdx[p] = idx;
				hashPoint[idx] = p;
				++idx;
			}
		}
		//cout << hashIdx.size() << endl;
		SegTree seg_tree(hashIdx.size());
		seg_tree.build(1, 0, hashIdx.size() - 1);
		for(auto v : buildings) {
			//cout << hashIdx[v[0]] << " " << hashIdx[v[1]] << " " << v[2] << endl;
			seg_tree.update(1, hashIdx[v[0]], hashIdx[v[1]], v[2]);
		}
		
		vector<int> H(hashIdx.size(), 0);
		
		seg_tree.query(H, hashIdx);
		//return ret;
		for(int i = 0; i < H.size(); ++i) {
			//cout << hashPoint[i] << " " << H[i] << endl;
			if(i == 0) ret.push_back(make_pair(hashPoint[i], H[i]));
			else {
				int tmp = height_of_edge(hashPoint[i - 1], hashPoint[i], buildings);
				//cout << hashPoint[i - 1] << " " << hashPoint[i] << " " << tmp << endl;
				if(tmp < H[i - 1] && tmp < H[i]) {
					//cout << "NO : " << hashPoint[i - 1] << " " << hashPoint[i] << endl;
					ret.push_back(make_pair(hashPoint[i - 1], tmp));
					ret.push_back(make_pair(hashPoint[i], H[i]));
				} else if(H[i] > H[i - 1]) {
					ret.push_back(make_pair(hashPoint[i], H[i]));
				} else if(H[i] < H[i - 1]) {
					ret.push_back(make_pair(hashPoint[i - 1], H[i]));
				} else {
					//
				}
			}
		}
		cout << "..........." << endl;
		ret.push_back(make_pair(hashPoint[H.size() - 1], 0));
		for(auto h : ret) {
			cout << h.first << " " << h.second << endl;
		}
		return ret;
	}
	
	// TLE的瓶颈在这里，无法优化，实现的（离散化中）线段树有缺陷
	int height_of_edge(int left, int right, vector<vector<int>>& buildings) {
		/*int low = 0, high = edges.size() - 1;
		int mid = (low + high) / 2;
		_edge e(left, right, 0);
		while(low < high) {
			mid = (low + high) / 2;
			if(left >= edges[mid].left && right <= edges[mid].right) return edges[mid].height;
			
			if(e < edges[mid]) {
				high = mid - 1;
			} else if(e > edges[mid]){
				low = mid + 1;
			}
		}*/
		int ret = 0;
		for(auto edge : buildings) {
			if(left >= edge[0] && right <= edge[1]) {
				ret = max(ret, edge[2]);
			}
		}
		return ret;
	}
};

int main() {
	vector<vector<int>> vv = { {2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 12}, {19, 24, 8} };
	vector<vector<int>> ww = {{0,5,7},{5,10,7},{5,10,12},{10,15,7},{15,20,7},{15,20,12},{20,25,7}};
	vector<vector<int> > zz;
	fstream fin("error.txt");
	int left, right, height;
	while(fin >> left >> right >> height) {
		vector<int> v;
		v.push_back(left);
		v.push_back(right);
		v.push_back(height);
		zz.push_back(v);
	}
	clock_t start = clock();
	Solution sol;
	sol.getSkyline(zz);
	clock_t end = clock();
	cout << double(end - start) / CLOCKS_PER_SEC << endl;
	//sol.getSkyline(ww);
	return 0;
}
