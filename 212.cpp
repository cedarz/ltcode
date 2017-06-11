#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>
#include <cstring>

using namespace std;
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

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode;
    }
    
    /** Adds a word into the data structure. */
    void insert(string word) {
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
        TrieNode * tmp = root;
		
        for(int i = 0; i < word.size(); ++i) {
			if(tmp->children[word[i] - 'a'] == nullptr) return false;
			tmp = tmp->children[word[i] - 'a'];
		}
		return tmp->isEnd;
    }
	
	bool startsWith(string prefix) {
		TrieNode * tmp = root;
		
        for(int i = 0; i < prefix.size(); ++i) {
			if(tmp->children[prefix[i] - 'a'] == nullptr) return false;
			tmp = tmp->children[prefix[i] - 'a'];
		}
		return true;
	}
	~Trie() {
		delete root;
	}
private:
	TrieNode * root;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		Trie * trie = new Trie();
		row = board.size();
		col = board[0].size();
		vector<string> vs;
		
		vector<vector<int>> vis(row, vector<int>(col, 0));
		
		
		for(auto w : words) {
			trie->insert(w);
		}
		
		string curr_word("");
		
		for(int i = 0; i < row; ++i) {
			for(int j = 0; j< col; ++j) {
				dfs(board, vis, trie, i, j, curr_word);
			}
		}
		
		for(auto w : res) {
			vs.push_back(w);
		}
		delete trie;
		return vs;
    }
	
	void dfs(vector<vector<char>>& board, vector<vector<int>>& vis, Trie * trie, int x, int y, string s) {
		if(x < 0 || x >= row || y < 0 || y >= col || vis[x][y] == 1) return;
		
		s += board[x][y];
		if(!trie->startsWith(s)) return;
		if(trie->search(s)) {
			res.insert(s);
		}
		
		vis[x][y] = 1;
		dfs(board, vis, trie, x, y - 1, s);
		dfs(board, vis, trie, x, y + 1, s);
		dfs(board, vis, trie, x - 1, y, s);
		dfs(board, vis, trie, x + 1, y, s);
		vis[x][y] = 0;
	}
	
private:
	int row, col;
	unordered_set<string> res;
};

int main() {
	return 0;
}
