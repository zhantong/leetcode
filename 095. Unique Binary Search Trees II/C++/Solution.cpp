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
    vector<TreeNode *> generateTrees(int n) {
        class Utils {
        public:
            vector<TreeNode *> generate(int start, int end) {
                vector<TreeNode *> result;
                if (start > end) {
                    result.push_back(nullptr);
                    return result;
                }
                for (int i = start; i <= end; i++) {
                    vector<TreeNode *> lefts = generate(start, i - 1);
                    vector<TreeNode *> rights = generate(i + 1, end);
                    for (TreeNode *left : lefts) {
                        for (TreeNode *right : rights) {
                            TreeNode *root = new TreeNode(i);
                            root->left = left;
                            root->right = right;
                            result.push_back(root);
                        }
                    }
                }
                return result;
            }
        };
        if (n == 0) {
            return vector<TreeNode *>();
        }
        Utils utils;
        return utils.generate(1, n);
    }
};