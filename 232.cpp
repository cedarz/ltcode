class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        q.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while(!q.empty()) {
			tmp.push(q.top());
			q.pop();
		}
		
		int ret = tmp.top();
		tmp.pop();
		while(!tmp.empty()) {
			q.push(tmp.top());
			tmp.pop();
		}
		return ret;
    }
    
    /** Get the front element. */
    int peek() {
        while(!q.empty()) {
			tmp.push(q.top());
			q.pop();
		}
		
		int ret = tmp.top();
		while(!tmp.empty()) {
			q.push(tmp.top());
			tmp.pop();
		}
		return ret;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return q.empty();
    }
private:
	stack<int> q;
	stack<int> tmp;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */