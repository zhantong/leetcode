class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int start = gas.size() - 1;
        int end = 0;
        int gain = gas[start] - cost[start];
        while (start > end) {
            if (gain >= 0) {
                gain += gas[end] - cost[end];
                end++;
            } else {
                start--;
                gain += gas[start] - cost[start];
            }
        }
        return gain >= 0 ? start : -1;
    }
};