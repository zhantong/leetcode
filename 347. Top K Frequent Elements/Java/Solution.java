public class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> freqDict = new HashMap<>();
        int maxFreq = -1;
        for (int num : nums) {
            if (!freqDict.containsKey(num)) {
                freqDict.put(num, 0);
            }
            int freq = freqDict.get(num) + 1;
            freqDict.put(num, freq);
            maxFreq = Math.max(maxFreq, freq);
        }
        List<Integer>[] freqList = new List[maxFreq + 1];
        for (Map.Entry<Integer, Integer> entry : freqDict.entrySet()) {
            if (freqList[entry.getValue()] == null) {
                freqList[entry.getValue()] = new ArrayList<>();
            }
            freqList[entry.getValue()].add(entry.getKey());
        }
        List<Integer> result = new ArrayList<>();
        for (int i = freqList.length - 1; i > 0 && result.size() < k; i--) {
            if (freqList[i] != null) {
                result.addAll(freqList[i]);
            }
        }
        return result;
    }
}