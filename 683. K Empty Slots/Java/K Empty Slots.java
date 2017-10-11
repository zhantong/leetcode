class Solution {
    public int kEmptySlots(int[] flowers, int k) {
        int[] positions = new int[flowers.length + 1];
        for (int i = 0; i < flowers.length; i++) {
            positions[flowers[i]] = i + 1;
        }
        int start = 1;
        int end = start + k + 1;
        if (end >= positions.length) {
            return -1;
        }
        int result = Integer.MAX_VALUE;
        for (int position = 1; position < positions.length; position++) {
            int day = positions[position];
            if (positions[start] > day || positions[end] >= day) {
                if (position == end) {
                    result = Math.min(result, Math.max(positions[start], positions[end]));
                }
                start = position;
                end = start + k + 1;
                if (end >= positions.length) {
                    break;
                }
            }
        }
        return result == Integer.MAX_VALUE ? -1 : result;
    }
}