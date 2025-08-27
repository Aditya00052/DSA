// Time complexity = O(2^target); 2 because we are making 2 decisions at every step and target because height of tree will be qual to target

class Solution {
private:
    void  dfs(int i, vector<int> curr, int total, vector<vector<int>> &res, vector<int> candidates, int target){    // i = index of current candiate in focus
        if(total == target){
            res.push_back(curr);
            return;
        }
        if(total > target || i >= candidates.size()){
            return;
        }

        // decision to include candidate[i]
        curr.push_back(candidates[i]);
        dfs(i, curr, total + candidates[i], res, candidates, target);

        // decision to not include candidates[i]
        curr.pop_back();
        dfs(i + 1, curr, total, res, candidates, target);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;

        dfs(0, {}, 0, res, candidates, target);
        return res;
    }
};