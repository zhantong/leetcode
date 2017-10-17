class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int shortLength = nums1.size();
        int longLength = nums2.size();
        int shortLeft = 0;
        int shortRight = nums1.size();
        while (shortLeft <= shortRight) {
            int shortMid = (shortLeft + shortRight) / 2;
            int longMid = (shortLength + longLength + 1) / 2 - shortMid;
            if (shortMid < shortLength && nums1[shortMid] < nums2[longMid - 1]) {
                shortLeft = shortMid + 1;
            } else if (shortMid > 0 && nums1[shortMid - 1] > nums2[longMid]) {
                shortRight = shortMid - 1;
            } else {
                int maxLeft;
                if (shortMid == 0) {
                    maxLeft = nums2[longMid - 1];
                } else if (longMid == 0) {
                    maxLeft = nums1[shortMid - 1];
                } else {
                    maxLeft = max(nums1[shortMid - 1], nums2[longMid - 1]);
                }
                if ((shortLength + longLength) % 2 == 1) {
                    return maxLeft;
                }
                int minRight;
                if (shortMid == shortLength) {
                    minRight = nums2[longMid];
                } else if (longMid == longLength) {
                    minRight = nums1[shortMid];
                } else {
                    minRight = min(nums1[shortMid], nums2[longMid]);
                }
                return (maxLeft + minRight) / 2.0;
            }
        }
        return 0.0;
    }
};