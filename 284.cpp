// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
		next_flag = Iterator::hasNext();
		if(next_flag) curr = Iterator::next();
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if(next_flag) return curr;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
		int tmp = curr;
	    if(Iterator::hasNext()) {
			next_flag = true;
			curr = Iterator::next();
		} else {
		    next_flag = false;
		}
		return tmp;
	}

	bool hasNext() const {
	    return next_flag;
	}
	
private:
	int curr;
	int next_flag;
};