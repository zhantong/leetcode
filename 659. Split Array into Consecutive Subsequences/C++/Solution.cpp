class Solution {
public:
    bool isPossible(vector<int> &nums) {
        unordered_map<int, int> counts;
        for (auto num : nums) {
            counts[num]++;
        }
        unordered_map<int, int> needs;
        for (auto num : nums) {
            if (counts[num] == 0) {
                continue;
            }
            if (needs.count(num) != 0 && needs[num] > 0) {
                needs[num]--;
                needs[num + 1]++;
            } else if (counts.count(num + 1) != 0 && counts[num + 1] > 0 && counts.count(num + 2) != 0 &&
                       counts[num + 2] > 0) {
                counts[num + 1]--;
                counts[num + 2]--;
                needs[num + 3]++;
            } else {
                return false;
            }
            counts[num]--;
        }
        return true;
    }
};