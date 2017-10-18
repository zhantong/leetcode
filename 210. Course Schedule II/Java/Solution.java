public class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        class Utils {
            boolean dfs(Map<Integer, List<Integer>> graph, int i, List<Integer> order, boolean[] visiting, boolean[] visited) {
                visiting[i] = true;
                visited[i] = true;
                for (int neighbor : graph.get(i)) {
                    if (visiting[neighbor]) {
                        return false;
                    }
                    if (!visited[neighbor]) {
                        if (!dfs(graph, neighbor, order, visiting, visited)) {
                            return false;
                        }
                    }
                }
                order.add(i);
                visiting[i] = false;
                return true;
            }
        }
        List<Integer> order = new ArrayList<>();
        boolean[] visiting = new boolean[numCourses];
        boolean[] visited = new boolean[numCourses];
        Map<Integer, List<Integer>> graph = new HashMap<>();
        for (int i = 0; i < numCourses; i++) {
            graph.put(i, new ArrayList<>());
        }
        for (int[] line : prerequisites) {
            graph.get(line[1]).add(line[0]);
        }
        Utils utils = new Utils();
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (!utils.dfs(graph, i, order, visiting, visited)) {
                    return new int[] {};
                }
            }
        }
        Collections.reverse(order);
        int[] result = new int[order.size()];
        for (int i = 0; i < result.length; i++) {
            result[i] = order.get(i);
        }
        return result;
    }
}