# Time complexity = O(n*2^n)
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()    # O(nlogn)
        
        def backtrack(i, subset):
            if i == len(nums):
                res.append(subset.copy())
                return
            
            # decision to include ith element
            subset.append(nums[i])
            backtrack(i+1, subset)

            # decison to not include ith element or any of it's duplicates
            subset.pop()
            while i+1 < len(nums) and nums[i] == nums[i+1]:
                i += 1
            backtrack(i+1, subset)

        backtrack(0, [])
        return res

