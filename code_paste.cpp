
/*  98 */
//https://discuss.leetcode.com/topic/18573/c-simple-recursive-solution
bool isValidBST(TreeNode* root) {
    return isValidBST(root, NULL, NULL);
}

bool isValidBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
    if(!root) return true;
    if(minNode && root->val <= minNode->val || maxNode && root->val >= maxNode->val)
        return false;
    return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
}

//https://discuss.leetcode.com/topic/4659/c-in-order-traversal-and-please-do-not-rely-on-buggy-int_max-int_min-solutions-any-more
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return validate(root, prev);
    }
    bool validate(TreeNode* node, TreeNode* &prev) {
        if (node == NULL) return true;
        if (!validate(node->left, prev)) return false;
        if (prev != NULL && prev->val >= node->val) return false;
        prev = node;
        return validate(node->right, prev);
    }
};

/* 123 */
// http://bangbingsyb.blogspot.com/2014/11/leetcode-best-time-to-buy-and-sell.html
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.empty()) return 0;
        int n = prices.size();
        vector<int> leftProfit(n,0);
        
        int maxLeftProfit = 0, minPrice = prices[0];
        for(int i=1; i<n; i++) {
            if(prices[i]<minPrice)
                minPrice = prices[i];
            else
                maxLeftProfit = max(maxLeftProfit, prices[i]-minPrice);
            leftProfit[i] = maxLeftProfit;
        }
        
        int ret = leftProfit[n-1];
        int maxRightProfit = 0, maxPrice = prices[n-1];
        for(int i=n-2; i>=0; i--) {
            if(prices[i]>maxPrice)
                maxPrice = prices[i];
            else
                maxRightProfit = max(maxRightProfit, maxPrice-prices[i]);
            ret = max(ret, maxRightProfit + leftProfit[i]);
        }
        
        return ret;
    }
};
/* 132 */
// http://fisherlei.blogspot.com/2013/03/leetcode-palindrome-partitioning-ii.html