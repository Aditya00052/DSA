// Time complexity = O(n) as we have to traverse every node in the tree
// Space complexity  = O(n/2) = O(n); at any point the queue can have upto n/2 elements; as the biggest level of a tree
// can be n/2; this is how binary trees work


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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;

        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int qLen = q.size();
            vector<int> level_nodes;

            for(int i=0; i<qLen; i++){
                TreeNode *node = q.front();
                q.pop();
                if(node){
                    level_nodes.push_back(node->val);
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            if(level_nodes.size() != 0){
                res.push_back(level_nodes);
            }
        }
        return res;

    }
};