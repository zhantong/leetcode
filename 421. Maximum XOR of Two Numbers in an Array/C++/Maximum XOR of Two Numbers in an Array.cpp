class Solution {
public:
    int findMaximumXOR(vector<int> &nums) {
        int result = 0;
        int mask = 0;
        for (int i = 31; i >= 0; i--) {
            mask |= 1 << i;
            unordered_set<int> numsSet;
            for (auto num : nums) {
                numsSet.insert(num & mask);
            }
            int current = result | (1 << i);
            for (auto num : numsSet) {
                if (numsSet.find(num ^ current) != numsSet.end()) {
                    result = current;
                    break;
                }
            }
        }
        return result;
    }
};