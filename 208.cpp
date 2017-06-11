class Trie {
public:
    /** Initialize your data structure here. */
    Trie() : vtrie(26, nullptr){
        memset(ch, 0, sizeof(ch));
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
		if(word.empty()) return;
		//if(search(word)) return;
		
		// error exists here. when insert one new word, 
		if(vtrie[word[0] - 'a'] == nullptr) vtrie[word[0] - 'a'] = new Trie();
		Trie * tmp = vtrie[word[0] - 'a'];
		
        for(int i = 1; i < word.size(); ++i) {
			if(tmp->vtrie[word[i] - 'a']) tmp->vtrie[word[i] - 'a'] = new Trie();
			tmp = tmp->vtrie[word[i] - 'a'];
		}
		tmp->ch[word.back() - 'a'] = 1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        //cout << " search : " << word << endl;
        if(word.empty()) return false;
		Trie * tmp = vtrie[word[0] - 'a'];
		if(tmp == nullptr) return false;
		for(int i = 1; i < word.size(); ++i) {
			if(tmp->vtrie[word[i] - 'a'] == nullptr) return false;
			tmp = tmp->vtrie[word[i] - 'a'];
		}
		return tmp->ch[word.back() - 'a'] == 1;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if(prefix.empty()) {
			for(int i = 0; i < 26; ++i) {
				if(vtrie[i]) return true;
			}
		}
		
		Trie * tmp = vtrie[prefix[0] - 'a'];
		if(tmp == nullptr) return false;
		for(int i = 1; i < prefix.size(); ++i) {
			if(tmp->vtrie[prefix[i] - 'a'] == nullptr) return false;
			tmp = tmp->vtrie[prefix[i] - 'a'];
		}
		return true;
    }
	
private:
	vector<Trie *> vtrie;
	int ch[26];
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */