class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        set<int> nums1Set(nums1.begin(), nums1.end());
        set<int> intersect;
        for (int num : nums2) {
            if (nums1Set.find(num) != nums1Set.end()) {
                intersect.insert(num);
            }
        }
        return vector<int>(intersect.begin(), intersect.end());
    }
};