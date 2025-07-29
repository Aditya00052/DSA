// Time complexity = Height of BST = Usually O(logn)
// Space complexity = O(1) as we are not using any data structures


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *curr = root;

        while(curr != NULL){
            if(p->val < curr->val && q->val < curr->val){     // both values in left subtree
                curr = curr->left;
            }
            else if(p->val > curr->val && q->val > curr->val){ // both values in right subtree
                curr = curr->right;
            }
            else{                                           // one lies in left and other in right subtree
                return curr;
            }
        }
        return curr;
    }
};