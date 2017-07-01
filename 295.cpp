#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(max_heap.size() == min_heap.size()) {
			if(min_heap.size() == 0) {
				max_heap.push(num);
			} else {
				int tmp = std::min(num, min_heap.top()); 
				if(tmp == num) {
					max_heap.push(num);
				} else {
					min_heap.pop();
					min_heap.push(num);
					max_heap.push(tmp);
				}
				
			}
		} else {
			int tmp = std::max(num, max_heap.top());
			if(tmp == num) {
				min_heap.push(num);
			} else {
				max_heap.pop();
				max_heap.push(num);
				min_heap.push(tmp);
			}
		}
    }
    
    double findMedian() {
		
        if(max_heap.size() == min_heap.size()) {
			return min_heap.size() == 0 ? 0.0 : double(max_heap.top() + min_heap.top()) / 2.0;
		} else {
			return max_heap.top();
		}
    }
private:
	priority_queue<int> max_heap;
	priority_queue<int, vector<int>, std::greater<int>> min_heap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
 
 int main() {
	 return 0;
 }
