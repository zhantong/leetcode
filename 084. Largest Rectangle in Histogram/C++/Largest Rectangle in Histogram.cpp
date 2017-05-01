class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        stack<int> sta;
        int i = 0;
        int result = 0;
        while (i < heights.size()) {
            while (!sta.empty() && heights[i] < heights[sta.top()]) {
                int index = sta.top();
                sta.pop();
                int current = heights[index] * (i - (sta.empty() ? -1 : sta.top()) - 1);
                result = max(result, current);
            }
            sta.push(i);
            i++;
        }
        while (!sta.empty()) {
            int index = sta.top();
            sta.pop();
            int current = heights[index] * (i - (sta.empty() ? -1 : sta.top()) - 1);
            result = max(result, current);
        }
        return result;
    }
};