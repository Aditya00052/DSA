# Time complexity = O(n2^n); n = cause of the coppy and 2^n as we are either including the ith element or we are skipping it for n elements

class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        res  = []
        candidates.sort()   # O(nlogn)

        def dfs(i, curr, total):
            if total == target:
                res.append(curr.copy())
                return
            if total > target or i >= len(candidates):
                return
            
            # decision to include candidate[i]
            curr.append(candidates[i])
            dfs(i+1, curr, total + candidates[i])

            # decision to skip candidate[i] and/or any of it's duplicates
            curr.pop()
            while i+1 < len(candidates) and candidates[i] == candidates[i+1]:
                i += 1

            dfs(i+1, curr, total)    # selecting the element after last duplicate

        dfs(0, [], 0)
        return res
        