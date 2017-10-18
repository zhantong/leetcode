/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        string result;
        stack<TreeNode *> sta;
        while (root != nullptr || !sta.empty()) {
            if (root != nullptr) {
                result += to_string(root->val) + " ";
                sta.push(root);
                root = root->left;
            } else {
                root = sta.top()->right;
                sta.pop();
            }
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        class Utils {
        public:
            TreeNode *construct(vector<int> data, int i, int j) {
                if (i == j) {
                    return nullptr;
                }
                TreeNode *node = new TreeNode(data[i]);
                int splitIndex = i + 1;
                while (splitIndex < j && data[splitIndex] < data[i]) {
                    splitIndex++;
                }
                node->left = construct(data, i + 1, splitIndex);
                node->right = construct(data, splitIndex, j);
                return node;
            }
        };
        istringstream sstream(data);
        string temp;
        vector<int> dataInInt;
        while (getline(sstream, temp, ' ')) {
            dataInInt.push_back(stoi(temp));
        }
        Utils utils;
        return utils.construct(dataInInt, 0, dataInInt.size());
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));