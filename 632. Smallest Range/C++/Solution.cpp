class Solution {
public:
    vector<int> smallestRange(vector<vector<int>> &nums) {
        struct comp {
            bool operator()(vector<int> p1, vector<int> p2) {
                return p2[0] < p1[0];
            }
        };
        priority_queue<vector<int>, vector<vector<int>>, comp> heap;
        int end = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i][0];
            end = max(end, num);
            heap.push({num, i, 0});
        }
        int start = heap.top()[0];
        int tempEnd = end;
        while (heap.size() == nums.size()) {
            vector<int> current = heap.top();
            heap.pop();
            if (current[2] + 1 < nums[current[1]].size()) {
                tempEnd = max(tempEnd, nums[current[1]][current[2] + 1]);
                heap.push({nums[current[1]][current[2] + 1], current[1], current[2] + 1});
                if (tempEnd - heap.top()[0] < end - start) {
                    start = heap.top()[0];
                    end = tempEnd;
                }
            }
        }
        return {start, end};
    }
};