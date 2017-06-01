class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 1, right = numbers.size();
		while(true) {
			if(numbers[left - 1] + numbers[right - 1] == target) {
				return vector<int> {left, right};
			} else if(numbers[left - 1] + numbers[right - 1] > target) {
				--right;
			} else {
				++left;
			}
		}
    }
};