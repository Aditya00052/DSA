// Time Complexity = O(n * 2^n); as we have 2^n subsets and each subset can have n elements

class Solution {
private:
    void dfs(int i, vector<vector<int>> &res, vector<int> &subset, vector<int> &nums){
        if(i >= nums.size()){
            res.push_back(subset);
            return;
        }

        // decision to include the element nums[i]
        subset.push_back(nums[i]);
        dfs(i+1, res, subset, nums);

        // decision to not include the element nums[i[]]
        subset.pop_back();
        dfs(i+1, res, subset, nums);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;

        dfs(0, res, subset, nums);
        
        return res;
    }
};