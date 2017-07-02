class NumArray {
public:
    NumArray(vector<int> nums) {
        int sum = 0;
		for(int i = 0; i < nums.size(); ++i) {
			sum += nums[i];
			rmq.push_back(sum);
		}
    }
    
    int sumRange(int i, int j) {
        return rmp[j] - i > 0 ? rmq[i - 1] : 0;
    }
private:
	vector<int> rmq;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */