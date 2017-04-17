class Solution {
public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k) {
        class Utils {
            class custom_priority_queue : public std::priority_queue<long, std::vector < long>>

            {
                public:

                bool remove(const long &value) {
                    auto it = std::find(this->c.begin(), this->c.end(), value);
                    if (it != this->c.end()) {
                        this->c.erase(it);
                        std::make_heap(this->c.begin(), this->c.end(), this->comp);
                        return true;
                    } else {
                        return false;
                    }
                }
            };

        public:
            custom_priority_queue minHeap;
            custom_priority_queue maxHeap;

            double getMedian() {
                if (maxHeap.empty() && minHeap.empty()) {
                    return 0;
                }
                if (maxHeap.size() == minHeap.size()) {
                    return ((double) maxHeap.top() - minHeap.top()) / 2.0;
                }
                return -(double) minHeap.top();
            }

            void add(int num) {
                if (num < getMedian()) {
                    maxHeap.push((long) num);
                } else {
                    minHeap.push(-(long) num);
                }
                if (maxHeap.size() > minHeap.size()) {
                    minHeap.push(-maxHeap.top());
                    maxHeap.pop();
                } else if (minHeap.size() > maxHeap.size() + 1) {
                    maxHeap.push(-minHeap.top());
                    minHeap.pop();
                }
            }

            void remove(int num) {
                if (num < getMedian()) {
                    maxHeap.remove((long) num);
                } else {
                    minHeap.remove(-(long) num);
                }
                if (maxHeap.size() > minHeap.size()) {
                    minHeap.push(-maxHeap.top());
                    maxHeap.pop();
                } else if (minHeap.size() > maxHeap.size() + 1) {
                    maxHeap.push(-minHeap.top());
                    minHeap.pop();
                }
            }
        };
        vector<double> result;
        Utils utils;
        for (int i = 0; i <= nums.size(); i++) {
            if (i >= k) {
                double temp = utils.getMedian();
                temp = temp == 0 ? 0 : temp;
                result.push_back(temp);
            }
            if (i < nums.size()) {
                utils.add(nums[i]);
            }
        }
        return result;
    }
};