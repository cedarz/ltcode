// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
		
		return lower_bound_(n);
		
        int low = 1, high = n;
		int mid = (low + high) / 2;
		
		while(low < mid) {
			mid = (low + high) / 2;
			if(isBadVersion(mid)) {
				high = mid;
			} else {
				low = mid + 1;
			}
		}
		return mid;
    }
	
	int lower_bound_(int n) {
		int lb = 0, ub = n;
		while(ub > lb + 1) {
			int mid = (lb + ub) / 2;
			if(isBadVersion(mid)) {
				ub = mid;
			} else {
				lb = mid;
			}
			return ub;
		}
	}
};