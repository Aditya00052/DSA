// Time Complesxity = O(n)
// Space Complexity = O(height of tree); log(n) <= height of tree <= n

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode *node, int curr_max){           // preorder traversal
        if(node == NULL){
            return 0;
        }

        int res = 0;
        if(node->val >= curr_max){
            res += 1;
        }
        
        curr_max = max(curr_max, node->val);
        res += dfs(node->left, curr_max);         // will return the number of good nodes in the left subtree
        res += dfs(node->right, curr_max);        // will return the number of good nodes in the right subtree

        return res;
    }

    int goodNodes(TreeNode* root) {

        return dfs(root, root->val);
    }
};