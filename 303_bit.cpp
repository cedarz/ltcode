class NumArray {
public:
    NumArray(vector<int> nums) {
        maxIdx = nums.size();
		bit = vector<int>(maxIdx + 1, 0);
		
		for(int i = 0; i < maxIdx; ++i) {
			update(i + 1, nums[i]);
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
	int maxIdx;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */