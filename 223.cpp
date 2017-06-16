
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        if(A > E) {
			return computeArea(E, F, G, H, A, B, C, D);
		}
		
		int all = (C - A) * (D - B) + (G - E) * (H - F);
		if(B >= F) { // 右下
			if(H < B || E > C) return all;
			return all - min(C - E, G - E) * min(D - B, H - B);
		} else if(D > H){ //包含部分或全部
			if(E > C) return all;
			if(G > C) return all - (H - F) * (C - E);
			else return (C - A) * (D - B);
			//return min(C - E, G - E) * (H - F);
		} else { //右上
			if(E > C || F > D) return all;
			return all - (D - F) * min(C - E, G - E);
		}
    }
};

/* 
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int left = max(A,E), right = max(min(C,G), left);
        int bottom = max(B,F), top = max(min(D,H), bottom);
        return (C-A)*(D-B) - (right-left)*(top-bottom) + (G-E)*(H-F);
    }
*/