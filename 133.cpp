/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if(node == nullptr) return NULL;
		
		UndirectedGraphNode * ret = new UndirectedGraphNode(node->label);
		origin_labels.insert(node);
		res_labels.insert(ret);
		for(int i = 0; i < node->neighbors.size(); ++i) {
			unordered_set<UndirectedGraphNode *>::iterator tmp = origin_labels.find(node->neighbors[i]);
			if(tmp == origin_labels.end()) {
				ret->neighbors.push_back(cloneGraph(node->neighbors[i]));
			} else {
			    unordered_set<UndirectedGraphNode*>::iterator it = res_labels.begin();
				for(; it != res_labels.end(); ++it) {
					if((*it)->label == node->neighbors[i]->label) break;
				}
				ret->neighbors.push_back(*it);
			}
		}
		
		return ret;
    }
private:
	unordered_set<UndirectedGraphNode*> origin_labels;
	unordered_set<UndirectedGraphNode*> res_labels;
};