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
    vector<int> findMode(TreeNode *root) {
        class Utils {
        public:
            void mode(TreeNode *root, vector<int> &result, int &prev, int &currentCount, int &maxCount) {
                if (!root) {
                    return;
                }
                mode(root->left, result, prev, currentCount, maxCount);
                if (prev == root->val) {
                    currentCount++;
                } else {
                    currentCount = 1;
                }
                prev = root->val;
                if (currentCount > maxCount) {
                    maxCount = currentCount;
                    result.clear();
                    result.push_back(root->val);
                } else if (currentCount == maxCount) {
                    result.push_back(root->val);
                }
                mode(root->right, result, prev, currentCount, maxCount);
            }
        };
        Utils utils;
        vector<int> result;
        int prev;
        int currentCount = 0;
        int maxCount = 0;
        utils.mode(root, result, prev, currentCount, maxCount);
        return result;
    }
};