/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.size() == 0 || inorder.size() == 0) {
            return nullptr;
        }
        TreeNode *node = new TreeNode(preorder.front());
        preorder.erase(preorder.begin());
        int index;
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == node->val) {
                index = i;
                break;
            }
        }
        vector<int> left(inorder.begin(), inorder.begin() + index);
        node->left = buildTree(preorder, left);
        vector<int> right(inorder.begin() + index + 1, inorder.end());
        node->right = buildTree(preorder, right);
        return node;
    }
};