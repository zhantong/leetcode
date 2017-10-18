class Solution {
public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k) {
        struct Min {
            bool operator()(pair<int, int> &p1, pair<int, int> &p2) {
                if (p1.first == p2.first) {
                    return p1.second > p2.second;
                }
                return p1.first > p2.first;
            }
        };
        struct Max {
            bool operator()(pair<int, int> &p1, pair<int, int> &p2) {
                if (p1.first == p2.first) {
                    return p1.second > p2.second;
                }
                return p1.first < p2.first;
            }
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, Min> minHeap;
        priority_queue<pair<int, int>, vector<pair<int, int>>, Max> maxHeap;
        vector<double> result;
        for (int i = 0; i < k; i++) {
            maxHeap.push(pair<int, int>(nums[i], i));
        }
        for (int i = 0; i < (k - k / 2); i++) {
            minHeap.push(pair<int, int>(maxHeap.top().first, maxHeap.top().second));
            maxHeap.pop();
        }

        for (int i = k; i < nums.size(); i++) {
            int num = nums[i];
            result.push_back(
                    k % 2 == 0 ? ((long) minHeap.top().first + maxHeap.top().first) / 2.0 : minHeap.top().first / 1.0);
            if (num >= minHeap.top().first) {
                minHeap.push(pair<int, int>(num, i));
                if (nums[i - k] <= minHeap.top().first) {
                    maxHeap.push(pair<int, int>(minHeap.top().first, minHeap.top().second));
                    minHeap.pop();
                }
            } else {
                maxHeap.push(pair<int, int>(num, i));
                if (nums[i - k] >= minHeap.top().first) {
                    minHeap.push(pair<int, int>(maxHeap.top().first, maxHeap.top().second));
                    maxHeap.pop();
                }
            }
            while (!maxHeap.empty() && maxHeap.top().second <= i - k) {
                maxHeap.pop();
            }
            while (!minHeap.empty() && minHeap.top().second <= i - k) {
                minHeap.pop();
            }
        }
        result.push_back(
                k % 2 == 0 ? ((long) minHeap.top().first + maxHeap.top().first) / 2.0 : minHeap.top().first / 1.0);
        return result;
    }
};