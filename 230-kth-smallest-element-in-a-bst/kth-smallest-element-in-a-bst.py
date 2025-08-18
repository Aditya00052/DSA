# Iterative Solution
# Time complexity = O(n) ; as we are traversing every element in the event that k = largest element of the BST

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        stack = []
        curr = root
        n = 0          # will be used to compare with k 

        while curr or stack:
            while curr:
                stack.append(curr)
                curr = curr.left
            
            curr = stack.pop()
            n += 1

            if n == k:
                return curr.val
            
            curr = curr.right
        
        