class LRUCache {
public:
    LRUCache(int capacity) {
		root = new ListNode(-1, -1);
		root->next = root;
		root->prev = root;
		cap = capacity;
		cnt = 0;        
    }
    
    int get(int key) {
        //ListNode * tmp = Lru[key]; // 这会导致在Lru中插入(key, NULL)
		if(Lru.find(key) != Lru.end()) {
		    ListNode * tmp = Lru[key];
		    
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
			
			tmp->next = root->next;
			tmp->next->prev = tmp;
			root->next = tmp;	
			tmp->prev = root;
			
			return tmp->val;
		} else {
			return -1;
		}
    }
    
    void put(int key, int value) {
        if(Lru.find(key) != Lru.end()) {
			ListNode * tmp = Lru[key];
			
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
			
			tmp->next = root->next;
			tmp->next->prev = tmp;
			root->next = tmp;	
			tmp->prev = root;
			
			tmp->val = value;
			
		} else {
			ListNode * tmp = nullptr;
			if(cnt == cap) {
				tmp = root->prev;
				Lru.erase(tmp->key);
				tmp->key = key;
				tmp->val = value;
				tmp->prev->next = root;
				root->prev = tmp->prev;
			} else {
				tmp = new ListNode(key, value);
				++cnt;
			}
			
			tmp->next = root->next;
			tmp->next->prev = tmp;
			root->next = tmp;	
			tmp->prev = root;
			Lru[key] = tmp;
		}
    }
private:
	struct ListNode {
		int key, val;
		ListNode *next;
		ListNode *prev;
		ListNode(int _key, int _val) : key(_key), val(_val), next(NULL), prev(NULL) {}
	};
	unordered_map<int, ListNode *> Lru;
	
	ListNode * root;
	int cap;
	int cnt;
	
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */