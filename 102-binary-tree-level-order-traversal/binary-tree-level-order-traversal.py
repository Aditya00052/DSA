# Time complexity = O(n) as we have to traverse every node in the tree
# Space complexity  = O(n/2) = O(n); at any point the queue can have upto n/2 elements; as the biggest level of a tree
# can be n/2; this is how binary trees work

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        res = []
        
        q = collections.deque()
        q.append(root)

        while q:              # while queue is not empty
            qLen = len(q)
            level_nodes = []
            for i in range(qLen):
                node = q.popleft()
                if node:                      # if node is not null
                    level_nodes.append(node.val)
                    q.append(node.left)
                    q.append(node.right)
            if level_nodes:                   # to prevent entry of empty list
                res.append(level_nodes)
        
        return res
        