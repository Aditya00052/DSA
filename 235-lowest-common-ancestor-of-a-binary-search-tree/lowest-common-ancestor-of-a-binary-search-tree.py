# Time complexity = Height of BST = Usually O(logn)
# Space complexity = O(1) as we are not using any data structures

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        curr = root

        while curr:
            if p.val < curr.val and q.val < curr.val:     # both in left subtree
                curr = curr.left
            elif p.val > curr.val and q.val > curr.val:   # both in right subtree
                curr = curr.right
            else:                                   # one lies in left and other in right subtree => curr node is LCA
                return curr
        
        