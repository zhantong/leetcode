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
    vector<double> averageOfLevels(TreeNode *root) {
        if (root == nullptr) {
            return vector<double>();
        }
        queue<TreeNode *> que;
        vector<double> result;
        que.push(root);
        while (!que.empty()) {
            long sumCurrentLevel = 0;
            int countCurrentLevel = que.size();
            for (int i = 0; i < countCurrentLevel; i++) {
                TreeNode *current = que.front();
                que.pop();
                sumCurrentLevel += current->val;
                if (current->left != nullptr) {
                    que.push(current->left);
                }
                if (current->right != nullptr) {
                    que.push(current->right);
                }
            }
            if (countCurrentLevel != 0) {
                result.push_back((double) sumCurrentLevel / countCurrentLevel);
            }
        }
        return result;
    }
};