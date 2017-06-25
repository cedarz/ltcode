class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
		int L = citations.size();
		int H = 0;
		for(int i = 0; i < L; ++i) {
			int tmp = min(citations[i], L - i);
			if(tmp > H) H = tmp;
		}
		return H;
    }
};