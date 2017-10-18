class Solution {
public:
    string originalDigits(string s) {
        vector<int> letters('z' + 1);
        for (auto letter : s) {
            letters[letter]++;
        }
        vector<int> nums(10);
        nums[0] = letters['z'];
        nums[2] = letters['w'];
        nums[4] = letters['u'];
        nums[6] = letters['x'];
        nums[8] = letters['g'];
        nums[1] = letters['o'] - nums[0] - nums[2] - nums[4];
        nums[3] = letters['h'] - nums[8];
        nums[5] = letters['f'] - nums[4];
        nums[7] = letters['v'] - nums[5];
        nums[9] = letters['i'] - nums[5] - nums[6] - nums[8];
        string result = "";
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < nums[i]; j++) {
                result += (char)('0' + i);
            }
        }
        return result;
    }
};