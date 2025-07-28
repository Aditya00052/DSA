#Complexity = O(height of root tree x height of subRoot tree)

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        if subRoot == None:
            return True
        
        if root == None and subRoot != None:     # no need to "write and subRoot == None"
            return False
        
        if self.isSametree(root, subRoot):
            return True
        
        return self.isSubtree(root.left, subRoot) or self.isSubtree(root.right, subRoot)   # or: we find the subtree wither in the left half or in the right half
        
    def isSametree(self, root, subRoot):
        if root == None and subRoot == None:
            return True
        
        if root and subRoot and root.val == subRoot.val:             # if both exist
            return self.isSametree(root.left, subRoot.left) and self.isSametree(root.right, subRoot.right)

        return False                                                 # if one of them exists