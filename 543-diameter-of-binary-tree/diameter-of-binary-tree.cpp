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
    int max_diameter = 0;   // public data member

    int dfs(TreeNode *node){
            if(node == NULL){
                return 0;
            }

            int left_height = dfs(node->left);
            int right_height = dfs(node->right);

            // Update the max_diameter
            max_diameter = max(max_diameter, left_height + right_height);

            // Return the height of current node
            return max(left_height, right_height) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return max_diameter;
    }
};