# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        # if both are None/Null they are same
        if not p and not q:
            return True
        
        # If one is None and other is exists or if both exists and their value is different
        if not p or not q or p.val != q.val:
            return False
        
        # recursively call both their left and right child
        return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
        