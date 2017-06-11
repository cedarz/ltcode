struct TrieNode {
	bool isEnd;
	vector<TrieNode *> children;
	
	TrieNode() : isEnd(false), children(26, nullptr){
		//
	}
	
	~TrieNode() {
		for(auto tn : children) {
			delete tn;
		}
	}
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
		TrieNode * path = root;
        for(int i = 0; i < word.size(); ++i) {
			if(path->children[word[i] - 'a'] == nullptr) {
				path->children[word[i] - 'a'] = new TrieNode;
			}
			path = path->children[word[i] - 'a'];
		}
		path->isEnd = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        //TrieNode * path = root;
		vector<TrieNode *> v;
		v.push_back(root);
		
        for(int i = 0; i < word.size(); ++i) {
			//if(path[word[i] - 'a'] == nullptr) return false;
			//path = path[word[i] - 'a'];
			vector<TrieNode *> tmp;
			//for(int j = 0; j < v.size(); ++j) {
			for(auto tn : v) {
				//TrieNode * tn = v[j];
				if(word[i] <= 'z' && word[i] >= 'a' && tn->children[word[i] - 'a']) {
					tmp.push_back(tn->children[word[i] - 'a']);
				} else if(word[i] == '.'){
					for(int c = 0; c < 26; ++ c) {
						if(tn->children[c]) {
							tmp.push_back(tn->children[c]);
						}
					}
				}
			}
			swap(v, tmp);
		}
		for(auto tn : v) {
			if(tn->isEnd) return true;
		}
		return false;
    }
	
	~WordDictionary() {
		delete root;
	}
private:
	TrieNode * root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */