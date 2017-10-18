public class Solution {
    public int[][] reconstructQueue(int[][] people) {
        if (people.length == 0) {
            return new int[][] {};
        }
        List<int[]> resultList = new ArrayList<>();
        Arrays.sort(people, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                if (o1[0] == o2[0]) {
                    return o1[1] - o2[1];
                }
                return o2[0] - o1[0];
            }
        });
        for (int[] person : people) {
            resultList.add(person[1], person);
        }
        int[][] result = new int[people.length][people[0].length];
        for (int i = 0; i < result.length; i++) {
            result[i] = resultList.get(i);
        }
        return result;
    }
}