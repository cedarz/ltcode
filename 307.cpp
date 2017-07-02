class NumArray {
public:
    NumArray(vector<int> nums) {
        maxIdx = nums.size();
		bit = vector<int>(maxIdx + 1, 0);
        n = vector<int>(maxIdx + 1, 0);
		
		for(int i = 0; i < maxIdx; ++i) {
			update(i, nums[i]);
		}
    }
    
    int sumRange(int i, int j) {
        //return rmp[j] - i > 0 ? rmq[i - 1] : 0;
		return read(j + 1) - (i > 0 ? read(i) : 0);
    }
	
	int read(int idx) {
		int sum = 0;
		while(idx > 0) {
			sum += bit[idx];
			idx -= lowbit(idx);
		}
		return sum;
	}
	void update(int idx, int k) {
        ++idx;
        swap(k, n[idx]);
        k = n[idx] - k;
        cout << idx << " " << k << endl;
		while(idx <= maxIdx) {
			bit[idx] += k;
			idx += lowbit(idx);
		}
	}
	
	int lowbit(int x) {
		return x & (-x);
	}
private:
	vector<int> bit;
    vector<int> n;
	int maxIdx;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
