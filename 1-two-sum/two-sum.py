# Time complexity = O(n); as we are using hash tables for faster lookup

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        hashmap = {}

        for i in range(n):
            hashmap[nums[i]] = i

        for i in range(n):
            complement = target - nums[i]
            if complement in hashmap and hashmap[complement] != i:
                return [i, hashmap[complement]]
        
        return [0, 0]
