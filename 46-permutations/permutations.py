class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []

        def dfs(i, temp_nums, curr):
            # insert ith element
            new_curr = curr + [temp_nums[i]]
            new_temp_nums = temp_nums[:i] + temp_nums[i+1:]

            # base case: no elements left
            if len(new_temp_nums) == 0:
                res.append(new_curr)
                return

            for j in range(len(new_temp_nums)):
                dfs(j, new_temp_nums, new_curr)

        # Start recursion with each possible first element
        for i in range(len(nums)):
            dfs(i, nums, [])
        
        return res
