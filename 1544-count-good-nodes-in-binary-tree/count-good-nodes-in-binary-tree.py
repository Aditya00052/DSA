# Time Complesxity = O(n); as we have to traverse every node
# Space Complexity = O(height of tree); log(n) <= height of tree <= n

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        
        def dfs(node, curr_max):                     # preorder traversal
            if node == None:
                return 0
            
            res = 1 if node.val >= curr_max else 0
            curr_max = max(curr_max, node.val)
            res += dfs(node.left, curr_max)          # will return the number of good nodes in the left subtree
            res += dfs(node.right, curr_max)         # will return the number of good nodes in the right subtree

            return res
        
        return dfs(root, root.val)
