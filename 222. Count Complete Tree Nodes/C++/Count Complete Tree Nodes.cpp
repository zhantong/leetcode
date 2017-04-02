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
    int countNodes(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int depthLeft = 0;
        TreeNode *nodeLeft = root;
        while (nodeLeft != nullptr) {
            depthLeft++;
            nodeLeft = nodeLeft->left;
        }
        int depthRight = 0;
        TreeNode *nodeRight = root;
        while (nodeRight != nullptr) {
            depthRight++;
            nodeRight = nodeRight->right;
        }
        if (depthLeft == depthRight) {
            return (1 << depthLeft) - 1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};