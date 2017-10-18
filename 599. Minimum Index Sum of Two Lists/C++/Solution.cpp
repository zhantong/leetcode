class Solution {
public:
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2) {
        int minIndexSum = INT_MAX;
        vector<string> result;
        unordered_map<string, int> list1Map;
        for (int i = 0; i < list1.size(); i++) {
            list1Map.insert(pair<string, int>(list1[i], i));
        }
        for (int i = 0; i < list2.size(); i++) {
            if (i > minIndexSum) {
                break;
            }
            string item = list2[i];
            if (list1Map.find(item) != list1Map.end()) {
                int currentIndexSum = i + list1Map[item];
                if (currentIndexSum < minIndexSum) {
                    minIndexSum = currentIndexSum;
                    result.clear();
                }
                if (currentIndexSum == minIndexSum) {
                    result.push_back(item);
                }
            }
        }
        return result;
    }
};