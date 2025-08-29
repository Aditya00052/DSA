// Time complexity = O(n2^n); n = cause of the coppy and 2^n as we are either including the ith element or we are skipping it for n elements

class Solution {
private:
    void dfs(int i, vector<int> curr, int total, vector<int> &candidates, int target, vector<vector<int>> &res){
        if(total == target){
            res.push_back(curr);
            return;
        }
        if(i >= candidates.size() || total > target){
            return;
        }

        // decision to include candidate[i]
        curr.push_back(candidates[i]);
        dfs(i+1, curr, total + candidates[i], candidates, target, res);

        // decision to skip candidate[i] and/or duplicates
        curr.pop_back();
        while(i+1 < candidates.size() && candidates[i] == candidates[i+1]){
            i = i+1;
        }

        dfs(i+1, curr, total, candidates, target, res);
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(),  candidates.end());   // sorting the input

        dfs(0, vector<int> {}, 0, candidates, target, res);
        return res;
    }
};