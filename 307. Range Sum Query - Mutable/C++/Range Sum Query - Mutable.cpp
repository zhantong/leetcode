class NumArray {
public:
    class Node {
    public:
        int start;
        int end;
        Node *left = nullptr;
        Node *right = nullptr;
        int sum = 0;

        Node(int start, int end) {
            this->start = start;
            this->end = end;
        }
    };

    Node *root;

    Node *build(vector<int> &nums, int start, int end) {
        if (start > end) {
            return nullptr;
        }
        Node *node = new Node(start, end);
        if (start == end) {
            node->sum = nums[start];
        } else {
            int mid = (start + end) / 2;
            node->left = build(nums, start, mid);
            node->right = build(nums, mid + 1, end);
            node->sum = node->left->sum + node->right->sum;
        }
        return node;
    }

    NumArray(vector<int> nums) {
        root = build(nums, 0, nums.size() - 1);
    }

    void update(Node *node, int i, int val) {
        if (node->start == node->end) {
            node->sum = val;
        } else {
            int mid = (node->start + node->end) / 2;
            if (i <= mid) {
                update(node->left, i, val);
            } else {
                update(node->right, i, val);
            }
            node->sum = node->left->sum + node->right->sum;
        }
    }

    void update(int i, int val) {
        update(root, i, val);
    }

    int sumRange(Node *node, int start, int end) {
        if (node->start == start && node->end == end) {
            return node->sum;
        }
        int mid = (node->start + node->end) / 2;
        if (end <= mid) {
            return sumRange(node->left, start, end);
        }
        if (start > mid) {
            return sumRange(node->right, start, end);
        }
        return sumRange(node->left, start, mid) + sumRange(node->right, mid + 1, end);
    }

    int sumRange(int i, int j) {
        return sumRange(root, i, j);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */