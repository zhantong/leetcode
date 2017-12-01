class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        map<int, int> nums1Map;
        for (int num : nums1) {
            nums1Map[num]++;
        }
        vector<int> resultVector;
        for (int num : nums2) {
            if (nums1Map.find(num) != nums1Map.end() && nums1Map[num] != 0) {
                resultVector.push_back(num);
                nums1Map[num]--;
            }
        }
        return resultVector;
    }
};