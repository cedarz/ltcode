class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        vector<int> v(numbers);
        vector<int> res;
        sort(v.begin(), v.end());
        while(v[i] + v[j] != target) {
            if(v[i] + v[j] < target) {
                i++;
            } else {
                j--;
            }
        }
        res.push_back(find_pos_LR(numbers, v[i]) + 1);
        res.push_back(find_pos_RL(numbers, v[j]) + 1);
        if(res[0] > res[1]) {
            swap(res[0], res[1]);
        }
        return res;
    }
    
    int find_pos_LR(vector<int> &numbers, const int &val) {
        for(int i = 0; i != numbers.size(); ++i) {
            if(numbers[i] == val) {
                return i;
            }
        }
    }
    
    int find_pos_RL(vector<int> &numbers, const int &val) {
        for(int i = numbers.size() - 1; i >= 0; --i) {
            if(numbers[i] == val) {
                return i;
            }
        }
    }
};
