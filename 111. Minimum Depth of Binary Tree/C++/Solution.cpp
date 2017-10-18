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
    int minDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        queue<TreeNode *> que;
        que.push(root);
        int depth = -1;
        while (!que.empty()) {
            depth++;
            int currentSize = que.size();
            for (int i = 0; i < currentSize; i++) {
                TreeNode *node = que.front();
                que.pop();
                if (node->left == nullptr && node->right == nullptr) {
                    return depth + 1;
                }
                if (node->left != nullptr) {
                    que.push(node->left);
                }
                if (node->right != nullptr) {
                    que.push(node->right);
                }
            }
        }
        return depth + 1;
    }
};