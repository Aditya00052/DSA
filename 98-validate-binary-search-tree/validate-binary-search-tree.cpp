// Time complexity = O(n) ; as we are just making comparisions for every node

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
 #include <limits>

class Solution {
public:
    bool valid(TreeNode *node, long left, long right){        // left = left boundary, right = right boundary
        if(node == NULL){
            return true;
        }

        if(!(node->val < right && node->val > left)){
            return false;
        }

        return valid(node->left, left, node->val) && valid(node->right, node->val, right);  
    }

    bool isValidBST(TreeNode* root) {

        return valid(root, LONG_MIN, LONG_MAX);     // long is used to prevent the edge case where node's cal == int_max's val
    }
};