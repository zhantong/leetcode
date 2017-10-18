class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        class Pair {
        public:
            int sum;
            int i;
            int j;

            Pair(int sum, int i, int j) {
                this->sum = sum;
                this->i = i;
                this->j = j;
            }
        };
        class Compare {
        public:
            bool operator()(const Pair &p1, const Pair &p2) {
                return p1.sum > p2.sum;
            }
        };
        if (nums1.size() == 0 || nums2.size() == 0 || k == 0) {
            return vector<pair<int, int>>();
        }
        vector<pair<int, int>> result;
        priority_queue<Pair, vector<Pair>, Compare> queue;
        queue.push(Pair(nums1[0] + nums2[0], 0, 0));
        while (!queue.empty() && result.size() < k) {
            Pair item = queue.top();
            queue.pop();
            result.push_back(pair<int, int> {nums1[item.i], nums2[item.j]});
            if (item.j < nums2.size() - 1) {
                queue.push(Pair(nums1[item.i] + nums2[item.j + 1], item.i, item.j + 1));
            }
            if (item.j == 0 && item.i < nums1.size() - 1) {
                queue.push(Pair(nums1[item.i + 1] + nums2[item.j], item.i + 1, item.j));
            }
        }
        return result;
    }
};