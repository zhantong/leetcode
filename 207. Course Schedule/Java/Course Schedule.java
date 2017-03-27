public class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        List<Integer>[] graph = (ArrayList<Integer>[]) new ArrayList[numCourses];
        for (int i = 0; i < numCourses; i++) {
            graph[i] = new ArrayList();
        }
        int[] inDegrees = new int[numCourses];
        for (int[] prerequisite : prerequisites) {
            int before = prerequisite[1];
            int after = prerequisite[0];
            if (!graph[before].contains(after)) {
                inDegrees[after]++;
                graph[before].add(after);
            }
        }
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < numCourses; i++) {
            if (inDegrees[i] == 0) {
                queue.add(i);
            }
        }
        int count = 0;
        while (!queue.isEmpty()) {
            int current = queue.poll();
            count += 1;
            for (int i : graph[current]) {
                inDegrees[i]--;
                if (inDegrees[i] == 0) {
                    queue.add(i);
                }
            }
        }
        return count == numCourses;
    }
}