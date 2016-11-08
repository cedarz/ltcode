class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        if(!len) return vector<int>();
        
        vector<int> res(len, 0);
        int carry = 1;
        for(int i = len - 1; i >= 0; --i) {
            res[len - 1 - i] = (digits[i] + carry) % 10;
            carry = (digits[i] + carry) / 10;
        }
        if(carry) {
            res.push_back(carry);
        }
        len = res.size();
        for(int i = 0, j = len - 1; i < j; ++i, --j) {
            swap(res[i], res[j]);
        }
        return res;
        
    }
};

