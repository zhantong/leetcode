public class Solution {
    public String[] findRestaurant(String[] list1, String[] list2) {
        int minIndexSum = Integer.MAX_VALUE;
        List<String> resultList = new ArrayList<>();
        Map<String, Integer> list1Map = new HashMap<>();
        for (int i = 0; i < list1.length; i++) {
            list1Map.put(list1[i], i);
        }
        for (int i = 0; i < list2.length; i++) {
            if (i > minIndexSum) {
                break;
            }
            String item = list2[i];
            if (list1Map.containsKey(item)) {
                int currentIndexSum = i + list1Map.get(item);
                if (currentIndexSum < minIndexSum) {
                    minIndexSum = currentIndexSum;
                    resultList.clear();
                }
                if (currentIndexSum == minIndexSum) {
                    resultList.add(item);
                }
            }
        }
        String[] result = new String[resultList.size()];
        return resultList.toArray(result);
    }
}