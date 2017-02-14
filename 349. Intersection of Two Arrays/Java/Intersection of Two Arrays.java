public class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        Set<Integer> nums1Set = new HashSet<>();
        for (int num : nums1) {
            nums1Set.add(num);
        }
        Set<Integer> intersect = new HashSet<>();
        for (int num : nums2) {
            if (nums1Set.contains(num)) {
                intersect.add(num);
            }
        }
        int[] intersectArray = new int[intersect.size()];
        int i = 0;
        for (int num : intersect) {
            intersectArray[i++] = num;
        }
        return intersectArray;
    }
}