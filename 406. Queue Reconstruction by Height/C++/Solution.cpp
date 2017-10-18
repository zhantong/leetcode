class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>> &people) {
        sort(people.begin(), people.end(), [](const pair<int, int> &left, const pair<int, int> &right) {
            if (left.first == right.first) {
                return left.second < right.second;
            }
            return left.first > right.first;
        });
        vector<pair<int, int>> result;
        for (auto &person : people) {
            result.insert(result.begin() + person.second, person);
        }
        return result;
    }
};