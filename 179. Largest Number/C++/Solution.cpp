class Solution {
public:
    string largestNumber(vector<int> &nums) {
        vector<string> strs(nums.size());
        for (int i = 0; i < strs.size(); i++) {
            strs[i] = to_string(nums[i]);
        }
        sort(strs.begin(), strs.end(), [](string & a, string & b) {
            return a + b > b + a;
        });
        if (strs[0] == "0") {
            return "0";
        }
        string result = "";
        for (string str : strs) {
            result += str;
        }
        return result;
    }
};