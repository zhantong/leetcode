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
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
        class Utils {
        public:
            string duplicate(TreeNode *root, unordered_map<string, int> &memory, vector<TreeNode *> &result) {
                if (root == nullptr) {
                    return "#";
                }
                string key =
                        duplicate(root->left, memory, result) + "," + duplicate(root->right, memory, result) + "," +
                        to_string(root->val);
                if (!memory.count(key)) {
                    memory[key] = 0;
                }
                if (memory[key] == 1) {
                    result.push_back(root);
                }
                memory[key]++;
                return key;
            }
        };
        Utils utils;
        vector<TreeNode *> result;
        unordered_map<string, int> memory;
        utils.duplicate(root, memory, result);
        return result;
    }
};