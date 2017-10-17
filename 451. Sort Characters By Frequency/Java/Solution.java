public class Solution {
    public String frequencySort(String s) {
        Map<Character, Integer> freqDict = new HashMap<>();
        int maxFreq = -1;
        for (char letter : s.toCharArray()) {
            if (!freqDict.containsKey(letter)) {
                freqDict.put(letter, 0);
            }
            int freq = freqDict.get(letter) + 1;
            freqDict.put(letter, freq);
            maxFreq = Math.max(maxFreq, freq);
        }
        List<Character>[] freqList = new List[maxFreq + 1];
        for (Map.Entry<Character, Integer> entry : freqDict.entrySet()) {
            if (freqList[entry.getValue()] == null) {
                freqList[entry.getValue()] = new ArrayList<>();
            }
            freqList[entry.getValue()].add(entry.getKey());
        }
        StringBuilder builder = new StringBuilder();
        for (int i = freqList.length - 1; i > 0; i--) {
            if (freqList[i] != null) {
                for (Character letter : freqList[i]) {
                    for (int j = 0; j < i; j++) {
                        builder.append(letter);
                    }
                }
            }
        }
        return builder.toString();
    }
}