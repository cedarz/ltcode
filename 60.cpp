
int a [10];

class Solution {
public:
    string getPermutation(int n, int k) {
        string res(n, '0');
        int base = 1;
        for(int i = 0; i < n; ++i) {
            a[i] = i + 1;
        }
        for(int i = 1; i < n; ++i) {
            base *= i;
        }
        for(int i = 0; i < n - 1; ++i) {
            sort(a, a + n - i);
            cout << base << endl;
            int loc = (k - 1) / base;
            swap(a[n - 1 - i], a[loc]);
            k -= base * loc;
            base /= n - 1 - i;
        }
        for(int i = n - 1; i >= 0; --i) {
            res[n - 1 - i] = '0' + a[i];
        }
        return res;
        
    }
};


