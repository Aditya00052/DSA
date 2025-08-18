# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        def dfs(node):
            if node == None:
                return []
            
            temp = [node.val]
            llst = dfs(node.left)
            rlst = dfs(node.right)
            
            for val  in llst + rlst:
                temp.append(val)
            
            return temp
        
        all_nodes = dfs(root)
        all_nodes_sorted = sorted(all_nodes)         # or : all_nodes.sort() and then return all_nodes[k-1]
        
        return all_nodes_sorted[k-1]
        