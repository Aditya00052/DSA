class Solution {
private:
    void dfs(int i, vector<int> temp_nums, vector<int> curr, vector<vector<int>> &res){
        curr.push_back(temp_nums[i]);
        temp_nums.erase(temp_nums.begin() + i);

        if(temp_nums.size() == 0){
            res.push_back(curr);
            return;
        }

        for(int j=0; j<temp_nums.size(); j++){
            dfs(j, temp_nums, curr, res);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;

        for(int i=0; i<nums.size(); i++){
            dfs(i, nums, {}, res);
        }

        return res;
    }
};