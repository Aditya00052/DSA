// Time complexity = O(n*2^n)
class Solution {
private:
    vector<vector<int>> res;  // created this a data member for easy acces by all functions

    void backtrack(int i, vector<int> subset, vector<int> nums){
        // base case
        if(i == nums.size()){
            res.push_back(subset);
            return;
        }

        // decision to include ith element
        subset.push_back(nums[i]);
        backtrack(i+1, subset, nums);

        // Decision to not include ith element or it's duplicates
        subset.pop_back();
        while(i+1 < nums.size() && nums[i] == nums[i+1]){
            i++;
        }
        backtrack(i+1, subset, nums);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        backtrack(0, {}, nums);
        return res;    
    }
};