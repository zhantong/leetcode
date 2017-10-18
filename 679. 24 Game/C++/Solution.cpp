class Solution {
public:
    bool judgePoint24(vector<int> &nums) {
        class Utils {
            double EPS = 0.001;
        public:
            bool backTrace(vector<double> &nums) {
                if (nums.size() == 1) {
                    return abs(nums[0] - 24) < EPS;
                }
                for (int i = 0; i < nums.size(); i++) {
                    double a = nums[i];
                    for (int j = 0; j < i; j++) {
                        double b = nums[j];
                        vector<double> candidates = {a + b, a - b, b - a, a * b};
                        if (abs(a) > EPS) {
                            candidates.push_back(b / a);
                        }
                        if (abs(b) > EPS) {
                            candidates.push_back(a / b);
                        }
                        nums.erase(nums.begin() + i);
                        nums.erase(nums.begin() + j);
                        for (auto candidate : candidates) {
                            nums.push_back(candidate);
                            if (backTrace(nums)) {
                                return true;
                            }
                            nums.pop_back();
                        }
                        nums.insert(nums.begin() + j, b);
                        nums.insert(nums.begin() + i, a);
                    }
                }
                return false;
            }
        };
        Utils utils;
        vector<double> temp;
        for (int num : nums) {
            temp.push_back((double) num);
        }
        return utils.backTrace(temp);
    }
};