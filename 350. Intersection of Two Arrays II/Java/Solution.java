public class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        Map<Integer, Integer> nums1Map = new HashMap<>();
        for (int num : nums1) {
            nums1Map.put(num, nums1Map.getOrDefault(num, 0) + 1);
        }
        List<Integer> result = new ArrayList<>();
        for (int num : nums2) {
            if (nums1Map.containsKey(num) && nums1Map.get(num) != 0) {
                result.add(num);
                nums1Map.put(num, nums1Map.get(num) - 1);
            }
        }
        int[] resultArray = new int[result.size()];
        int index = 0;
        for (int item : result) {
            resultArray[index++] = item;
        }
        return resultArray;
    }
}