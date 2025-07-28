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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (subRoot == NULL){
            return true;
        }
        if (root == NULL && subRoot != NULL){
            return false;
        }

        if (isSametree(root, subRoot)){         // if both are not NULL
            return true; 
        }

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);    // check if subtree is in either half of the root node
    }

    bool isSametree(TreeNode *root, TreeNode *subRoot) {
        if (root == NULL && subRoot == NULL) {
            return true;
        }

        if (root != NULL && subRoot != NULL && root->val == subRoot->val){
            return isSametree(root->left, subRoot->left) && isSametree(root->right, subRoot->right);
        }

        return false;    // if only one of them exists
    }
};