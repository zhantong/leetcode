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
    int findBottomLeftValue(TreeNode *root) {
        queue<TreeNode *> que;
        que.push(root);
        int result = root->val;
        while (!que.empty()) {
            result = que.front()->val;
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode *node = que.front();
                que.pop();
                if (node->left) {
                    que.push(node->left);
                }
                if (node->right) {
                    que.push(node->right);
                }
            }
        }
        return result;
    }
};