'''
Given the root node of a binary search tree, 
return the sum of values of all nodes 
with value between L and R (inclusive).

The binary search tree is guaranteed to have unique values.
'''


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rangeSumBST(self, root: TreeNode, L: int, R: int) -> int:
        
        self.count = 0
        self.counter(root, L, R)
        return self.count
    
    def counter(self, root, L, R):
        if root.val is None:
            return None
        
        if (root.val >= L) & (root.val <= R):
            self.count += root.val

        if root.right is not None:
            self.counter(root.right, L, R)

        if root.left is not None:
            self.counter(root.left, L, R)
