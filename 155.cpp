class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        min_loc = 0;
    }
    
    void push(int x) {
        stk.push_back(x);
		if(x < stk[min_loc]) {
			min_loc = stk.size() - 1;
		}
		min_stk.push_back(min_loc);
    }
    
    void pop() {
        stk.pop_back();
		
		min_stk.pop_back();
		min_loc = min_stk.back();
    }
    
    int top() {
        return stk.back();
    }
    
    int getMin() {
        return stk[min_loc];
    }
private:
	vector<int> stk;
	vector<int> min_stk;
	int min_loc;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */