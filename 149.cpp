#include <iostream>
#include <unordered_map>
#include <utility>

using namespace std;

/*
struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};*/

template <class T, typename U>
struct PairHash{
	size_t operator()(const std::pair<T, U> &key) const{
		return std::hash<T>()(key.first) ^ std::hash<U>()(key.second);
	}
};

template <class T, typename U>
struct PairEqual{
	bool operator()(const std::pair<T, U> &lhs, const std::pair<T, U> &rhs) const{
		return lhs.first == rhs.first && lhs.second == rhs.second;
	}
};

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
class Solution {
public:
	int maxPoints(vector<Point>& points) {
		unordered_map<pair<int, int>, int, PairHash<int, int>, PairEqual<int, int> > stat;

		if (points.empty()) return 0;
		int res = 0;
		int N = points.size();
		for (int i = 0; i < N; ++i) {
			stat.clear();
			int same_point = 1;
			for (int j = 0; j < N; ++j) {
				if (i == j) continue;
				if (points[i].x == points[j].x && points[i].y == points[j].y) {
					same_point++;
				}
				else { // without i
					int dy = points[i].y - points[j].y;
					int dx = points[i].x - points[j].x;
					int g = gcd(dy < 0 ? -dy : dy, dx < 0 ? -dx : dx);
					dy /= g;
					dx /= g;
					if (dy < 0) {
						dy = -dy;
						dx = -dx;
					}
					pair<int, int> key = (points[i].x == points[j].x) ?
						std::make_pair(INT_MAX, INT_MAX) :
						std::make_pair(dy, dx);

					//double key = (points[i].x == points[j].x) ? INT_MAX : 
					//		(points[i].y - points[j].y) * 1.0 / (points[i].x - points[j].x);

					if (stat.find(key) == stat.end()) stat[key] = 0;
					stat[key]++;
					//cout << i << " " << j << " " << key << " " << stat[key] << endl;
				}

			}
			int tmp = 0;
			for(auto item : stat) {
			if(tmp < item.second) tmp = item.second;
			}
			res = res < tmp + same_point ? tmp + same_point : res;
		}
		return res;
	}
};

