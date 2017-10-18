class Solution {
public:
    bool find132pattern(vector<int> &nums) {
        class Pair {
        public:
            int min;
            int max;

            Pair(int min, int max) {
                this->min = min;
                this->max = max;
            }
        };
        if (nums.size() < 3) {
            return false;
        }
        stack<Pair> sta;
        for (int &num : nums) {
            if (sta.empty() || sta.top().min > num) {
                sta.push(Pair(num, num));
            } else if (sta.top().min < num) {
                if (sta.top().max > num) {
                    return true;
                }
                int theMin = sta.top().min;
                sta.pop();
                while (!sta.empty() && sta.top().max <= num) {
                    sta.pop();
                }
                if (!sta.empty() && sta.top().min < num) {
                    return true;
                }
                sta.push(Pair(theMin, num));
            }
        }
        return false;
    }
};