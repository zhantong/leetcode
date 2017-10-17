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
    int findSecondMinimumValue(TreeNode *root) {
        if (root->left == nullptr && root->right == nullptr) {
            return -1;
        }
        int left = root->val == root->left->val ? findSecondMinimumValue(root->left) : root->left->val;
        int right = root->val == root->right->val ? findSecondMinimumValue(root->right) : root->right->val;
        if (left == -1 && right == -1) {
            return -1;
        }
        if (left == -1) {
            return right;
        }
        if (right == -1) {
            return left;
        }
        return min(left, right);
    }
};