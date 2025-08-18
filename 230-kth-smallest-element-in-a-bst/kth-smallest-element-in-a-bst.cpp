// Iterative Solution
// Time complexity = O(n) ; as we are traversing every element in the event that k = largest element of the BST

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

 #include <stack>      // could've used vector also

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode *> st;
        TreeNode *curr = root;
        int n = 0;

        while(curr != NULL || st.size() != 0){
            while(curr != NULL){
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();
            n += 1;
            
            if(n == k){
                return curr->val;
            }

            curr = curr->right;
        }
        return 0;
    }
};