class Solution {
public:
    string nextClosestTime(string time) {
        int nums[] = {time[0] - '0', time[1] - '0', time[3] - '0', time[4] - '0'};
        vector<int> greater(10, -1);
        int minNum = INT_MAX;
        for (int num : nums) {
            minNum = min(minNum, num);
            if (num > 0) {
                greater[num - 1] = num;
            }
        }
        int current = -1;
        for (int i = greater.size() - 1; i >= 0; i--) {
            if (greater[i] != -1) {
                current = greater[i];
            }
            greater[i] = current;
        }
        char minTime = (char)('0' + minNum);
        if (greater[nums[3]] != -1) {
            time[4] = (char)('0' + greater[nums[3]]);
        } else {
            time[4] = minTime;
            if (greater[nums[2]] != -1 && greater[nums[2]] < 6) {
                time[3] = (char)('0' + greater[nums[2]]);
            } else {
                time[3] = minTime;
                if (greater[nums[1]] != -1 && (nums[0] < 2 || greater[nums[1]] < 4)) {
                    time[1] = (char)('0' + greater[nums[1]]);
                } else {
                    time[1] = minTime;
                    if (greater[nums[0]] != -1 && greater[nums[0]] < 2) {
                        time[0] = (char)('0' + greater[nums[0]]);
                    } else {
                        time[0] = minTime;
                    }
                }
            }
        }
        return time;
    }
};