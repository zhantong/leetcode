class Solution {
    public List<int[]> getSkyline(int[][] buildings) {
        class Utils {
            LinkedList<int[]> merge(int[][] buildings, int low, int high) {
                LinkedList<int[]> result = new LinkedList<>();
                if (low == high) {
                    result.add(new int[] {buildings[low][0], buildings[low][2]});
                    result.add(new int[] {buildings[low][1], 0});
                } else if (low < high) {
                    int mid = (low + high) / 2;
                    LinkedList<int[]> lefts = merge(buildings, low, mid);
                    LinkedList<int[]> rights = merge(buildings, mid + 1, high);
                    int heightLeft = 0;
                    int heightRight = 0;
                    while (!lefts.isEmpty() || !rights.isEmpty()) {
                        long currentLeft = lefts.isEmpty() ? Long.MAX_VALUE : lefts.peekFirst()[0];
                        long currentRight = rights.isEmpty() ? Long.MAX_VALUE : rights.peekFirst()[0];
                        long current = 0;
                        if (currentLeft < currentRight) {
                            int[] temp = lefts.pollFirst();
                            current = temp[0];
                            heightLeft = temp[1];
                        } else if (currentLeft > currentRight) {
                            int[] temp = rights.pollFirst();
                            current = temp[0];
                            heightRight = temp[1];
                        } else {
                            int[] temp = lefts.pollFirst();
                            current = temp[0];
                            heightLeft = temp[1];
                            heightRight = rights.pollFirst()[1];
                        }
                        int height = Math.max(heightLeft, heightRight);
                        if (result.isEmpty() || result.peekLast()[1] != height) {
                            result.add(new int[] {(int) current, height});
                        }
                    }
                }
                return result;
            }
        }
        Utils utils = new Utils();
        return utils.merge(buildings, 0, buildings.length - 1);
    }
}