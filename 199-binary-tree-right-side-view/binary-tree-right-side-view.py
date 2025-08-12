# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        res = []

        q = collections.deque()
        q.append(root)

        while q:
            qLen = len(q)
            curr_lvl_nodes = []
            for i in range(qLen):
                node = q.popleft()
                if node:
                    curr_lvl_nodes.append(node.val)
                    q.append(node.left)
                    q.append(node.right)
            if len(curr_lvl_nodes) != 0:
                res.append(curr_lvl_nodes[-1])             # appending the rightmost element
        
        return res

        