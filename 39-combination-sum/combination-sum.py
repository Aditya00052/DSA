# Time complexity = O(2^target); 2 because we are making 2 decisions at every step and target because height of tree will be qual to target
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []

        def dfs(i, curr, total):
            if total == target:
                res.append(curr.copy())
                return
            if total > target or i >= len(candidates):
                return
            
            # decision to include current candidate[i]
            curr.append(candidates[i])
            dfs(i, curr, total + candidates[i])

            # decision to not include candidate[i]
            curr.pop()
            dfs(i + 1, curr, total)

        dfs(0, [], 0)
        return res
