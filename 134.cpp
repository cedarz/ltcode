class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len = gas.size();
        int tmp = 0;
		int loc = 0;
		int sum = 0;
		for(int i = 0; i < len; ++i) {
			tmp += gas[i] - cost[i];
			sum += gas[i] - cost[i];
			//if(tmp < 0 && tmp + gas[(i + 1) % len] - cost[(i + 1) % len] >= 0) loc = i;
			if(sum < 0) {
				sum = 0;
				loc = i + 1;
			}
		}
		if(tmp < 0) return -1;
		else return loc;
		
    }
};