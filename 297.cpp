/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
		//if(root == nullptr) return "[]";
		string res("[");
        list<TreeNode *> q;
		q.push_back(root);

		int cnt = 0;
		while(!q.empty()) {
			TreeNode * tmp = q.front();
			q.pop_front();
			if(tmp) {
				++cnt;
				res += cnt == 1 ? to_string(tmp->val) : string(",") + to_string(tmp->val);
				q.push_back(tmp->left);
				q.push_back(tmp->right);
			} else {
				list<TreeNode *>::iterator it = q.begin();
				for(; it != q.end(); ++it) {
					if(*it) break;
				}
				if(it != q.end()) {
					++cnt;
					res += string(",null");
				}
			}
			
		}
		res += "]";
        //cout << res << endl;
		return res;		
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        //return nullptr;
		vector<TreeNode *> tree;
		for(int i = 1; i < data.size(); ) {
			if(data[i] == ']') break;
			if(data[i] == ',') {
				++i;
                continue;
			}
			if(data[i] == 'n') {
				tree.push_back(nullptr);
				i += 4;
                continue;
			}
			
			
			int tmp = 0;
			int sign = 1;
			if(data[i] == '-') {
				sign = -1;
				++i;
			}
			while(data[i] <= '9' && data[i] >= '0') {
				tmp = tmp * 10 + data[i] - '0';
				++i;
			}
			tree.push_back(new TreeNode(tmp * sign));
		}
		
		cout << tree.size() << endl;
		if(tree.empty()) return nullptr;
        //TreeNode * root = tree[0];
		int par = 0, child = 1;
		while(par < tree.size() && child < tree.size()) {
			tree[par]->left = tree[child++];
			if(child < tree.size()) tree[par]->right = tree[child++];
			
			++par;
			while(tree[par] == nullptr) ++par;
		}
		return tree[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));