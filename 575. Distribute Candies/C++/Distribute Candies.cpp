class Solution {
public:
    int distributeCandies(vector<int> &candies) {
        unordered_set<int> nums = unordered_set<int>(candies.begin(), candies.end());
        int numNums = nums.size();
        int numTarget = candies.size() / 2;
        return numNums >= numTarget ? numTarget : numNums;
    }
};