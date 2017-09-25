class Solution {
    public int maximumSwap(int num) {
        char[] numStr = String.valueOf(num).toCharArray();
        Map<Character, Integer> lastIndex = new HashMap<>();
        for (int i = 0; i < numStr.length; i++) {
            lastIndex.put(numStr[i], i);
        }
        for (int i = 0; i < numStr.length; i++) {
            for (char digit = '9'; digit > numStr[i]; digit--) {
                if (lastIndex.containsKey(digit) && lastIndex.get(digit) > i) {
                    char temp = numStr[i];
                    numStr[i] = numStr[lastIndex.get(digit)];
                    numStr[lastIndex.get(digit)] = temp;
                    return Integer.parseInt(String.valueOf(numStr));
                }
            }
        }
        return num;
    }
}