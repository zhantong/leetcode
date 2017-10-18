class Solution {
public:
    vector<int> countSmaller(vector<int> &nums) {
        class Node {
        public:
            int value;
            int countLeft = 0;
            int countDuplicate = 1;
            Node *left = nullptr;
            Node *right = nullptr;

            Node(int value) {
                this->value = value;
            }
        };
        class Utils {
        public:
            Node *insert(Node *node, int num, vector<int> &result, int i, int count) {
                if (node == nullptr) {
                    node = new Node(num);
                    result[i] = count;
                } else if (node->value == num) {
                    result[i] = count + node->countLeft;
                    node->countDuplicate++;
                } else if (node->value > num) {
                    node->countLeft++;
                    node->left = insert(node->left, num, result, i, count);
                } else {
                    count += node->countLeft + node->countDuplicate;
                    node->right = insert(node->right, num, result, i, count);
                }
                return node;
            }
        };
        vector<int> result(nums.size(), 0);
        Node *root = nullptr;
        Utils utils;
        for (int i = nums.size() - 1; i >= 0; i--) {
            root = utils.insert(root, nums[i], result, i, 0);
        }
        return result;
    }
};