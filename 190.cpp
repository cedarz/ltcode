class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> x(n);
		//x.flip();
		for(int i = 0; i < 16; ++i) {
			//swap(x[i], x[31 - i]);
			int tmp = x[i];
			x[i] = x[31 - i];
			x[31- i] = tmp;
		}
		return x.to_ulong();
    }
};