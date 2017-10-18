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
    int widthOfBinaryTree(TreeNode *root) {
        int result = 0;
        queue<pair<TreeNode *, int>> que;
        if (root != nullptr) {
            que.push(pair<TreeNode *, int>(root, 1));
        }
        while (!que.empty()) {
            result = max(result, que.back().second - que.front().second + 1);
            int size = que.size();
            for (int i = 0; i < size; i++) {
                pair<TreeNode *, int> &current = que.front();
                que.pop();
                if (current.first->left != nullptr) {
                    que.push(pair<TreeNode *, int>(current.first->left, 2 * current.second));
                }
                if (current.first->right != nullptr) {
                    que.push(pair<TreeNode *, int>(current.first->right, 2 * current.second + 1));
                }
            }
        }
        return result;
    }
};