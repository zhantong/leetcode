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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.size() == 0 || postorder.size() == 0) {
            return nullptr;
        }
        TreeNode *node = new TreeNode(postorder.back());
        postorder.pop_back();
        int indexInorder;
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == node->val) {
                indexInorder = i;
                break;
            }
        }
        vector<int> right(inorder.begin() + indexInorder + 1, inorder.end());
        node->right = buildTree(right, postorder);
        vector<int> left(inorder.begin(), inorder.begin() + indexInorder);
        node->left = buildTree(left, postorder);
        return node;
    }
};