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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;

        queue<TreeNode *> q;
        q.push(root);

        while(!q.empty()){
            int qLen = q.size();
            vector<int> curr_lvl_nodes;
            for(int i=0; i<qLen; i++){
                TreeNode *node = q.front();
                q.pop();
                if(node != NULL){
                    curr_lvl_nodes.push_back(node->val);
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            if(curr_lvl_nodes.size() != 0){                     // veryyyy imp condition
                res.push_back(curr_lvl_nodes.back());
            }
        }
        return res;
    }
};