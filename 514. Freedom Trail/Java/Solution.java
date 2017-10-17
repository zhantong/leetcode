public class Solution {
    public int findRotateSteps(String ring, String key) {
        int ringLength = ring.length();
        int keyLength = key.length();
        int[][] dp = new int[keyLength + 1][ringLength];
        Map<Character, List<Integer>> indexSame = new HashMap<>();
        for (char item : key.toCharArray()) {
            if (!indexSame.containsKey(item)) {
                List<Integer> list = new ArrayList<>();
                for (int i = 0; i < ringLength; i++) {
                    if (item == ring.charAt(i)) {
                        list.add(i);
                    }
                }
                indexSame.put(item, list);
            }
        }
        for (int keyIndex = keyLength - 1; keyIndex >= 0; keyIndex--) {
            for (int ringIndex = 0; ringIndex < ringLength; ringIndex++) {
                dp[keyIndex][ringIndex] = Integer.MAX_VALUE;
                for (int i : indexSame.get(key.charAt(keyIndex))) {
                    int clockStep = Math.abs(ringIndex - i);
                    int minStep = Math.min(clockStep, ringLength - clockStep);
                    dp[keyIndex][ringIndex] = Math.min(dp[keyIndex][ringIndex], minStep + dp[keyIndex + 1][i]);
                }
            }
        }
        return dp[0][0] + keyLength;
    }
}