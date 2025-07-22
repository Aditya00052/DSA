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
//  Test upload
class Solution {
public:
    int dfs(TreeNode *node){
        if(node == NULL){
            return 0;             //a null node is balanced with a height of 0
        }

        return max(dfs(node->left), dfs(node->right)) + 1;
    }
    
    bool isBalanced(TreeNode* root) {         // kinda like a top down approach
        if(root == NULL){
            return true;
        }

        int left_height = dfs(root->left);
        int right_height = dfs(root->right);

        if(abs(left_height - right_height) > 1){     // if we find/hit any unbalanced node => exit to false
            return false;
        }

        return isBalanced(root->left) && isBalanced(root->right);
    }
};
