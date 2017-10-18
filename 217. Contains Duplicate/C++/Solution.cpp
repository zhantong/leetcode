class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        set<int> contains;
        for (int num : nums) {
            if (contains.find(num) != contains.end()) {
                return true;
            }
            contains.insert(num);
        }
        return false;
    }
};