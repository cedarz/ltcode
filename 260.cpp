class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor_ = 0;
		for(auto n : nums) {
			xor_ ^= n;
		}
		
		int last_bit = (xor_ & (xor_ - 1)) ^ xor_;
		
		int last_bit_1 = 0, last_bit_0 = 0;
		
		for(auto n : nums) {
			if(last_bit & n) {
				last_bit_1 ^= n;
			} else {
				last_bit_0 ^= n;
			}
		}
		
		return vector<int>{last_bit_0, last_bit_1};
    }
};

/*
vector<int> singleNumber(vector<int>& nums) {
    int aXorb = 0;  // the result of a xor b;
    for (auto item : nums) aXorb ^= item;
    int lastBit = (aXorb & (aXorb - 1)) ^ aXorb;  // the last bit that a diffs b
    int intA = 0, intB = 0;
    for (auto item : nums) {
        // based on the last bit, group the items into groupA(include a) and groupB
        if (item & lastBit) intA = intA ^ item;
        else intB = intB ^ item;
    }
    return vector<int>{intA, intB};   
}
*/