# https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        # print(preorder, inorder)
        if len(preorder) == 0 or len(inorder) == 0:
            return None
        center = preorder[0]
        root = TreeNode(center)
        center_inx = inorder.index(center)

        if inorder[:center_inx]:
            left_inorder = inorder[:center_inx]
            left_preorder = preorder[1: len(inorder[:center_inx]) + 1 ]
            root.left = self.buildTree(left_preorder, left_inorder)
        if inorder[center_inx+1:]:
            right_inorder = inorder[center_inx+1:]
            right_preorder = preorder[1 + len(inorder[:center_inx]) : ]
            root.right = self.buildTree(right_preorder, right_inorder)

        # print(center_inx)

        # root.left = self.buildTree(preorder[1:], inorder[:center_inx])
        # root.right = self.buildTree(preorder[2:], inorder[center_inx+1:])

        return root
    