class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        deque<int> que;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            if (!que.empty() && que.front() == i - k) {
                que.pop_front();
            }
            while (!que.empty() && nums[que.back()] < nums[i]) {
                que.pop_back();
            }
            que.push_back(i);
            if (i + 1 >= k) {
                result.push_back(nums[que.front()]);
            }
        }
        return result;
    }
};