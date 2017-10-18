class Solution {
public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        class Item {
        public:
            int value;
            int i;
            int j;

            Item(int value, int i, int j) {
                this->value = value;
                this->i = i;
                this->j = j;
            }
        };
        auto compare = [](Item & a, Item & b) -> bool { return a.value > b.value; };
        int m = matrix.size();
        int n = matrix[0].size();
        priority_queue<Item, vector<Item>, decltype(compare)> minHeap(compare);
        for (int j = 0; j < n; j++) {
            minHeap.push(Item(matrix[0][j], 0, j));
        }
        while (!minHeap.empty()) {
            Item item = minHeap.top();
            minHeap.pop();
            if (item.i < m - 1) {
                minHeap.push(Item(matrix[item.i + 1][item.j], item.i + 1, item.j));
            }
            k--;
            if (k == 0) {
                return item.value;
            }
        }
        return 0;
    }
};