public class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        Set<Integer>[] graph = (HashSet<Integer>[]) new HashSet[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new HashSet<>();
        }
        for (int[] edge : edges) {
            graph[edge[0]].add(edge[1]);
            graph[edge[1]].add(edge[0]);
        }
        Set<Integer> remain = new HashSet<>();
        for (int i = 0; i < n; i++) {
            remain.add(i);
        }
        Set<Integer> toDelete = new HashSet<>();
        for (int i = 0; i < n; i++) {
            if (graph[i].size() == 1) {
                toDelete.add(i);
            }
        }
        while (remain.size() > 2) {
            Set<Integer> temp = new HashSet<>();
            for (int item : toDelete) {
                remain.remove(item);
                for (int neighbor : graph[item]) {
                    graph[neighbor].remove(item);
                    if (graph[neighbor].size() == 1 && remain.contains(neighbor)) {
                        temp.add(neighbor);
                    }
                }
            }
            toDelete = temp;
        }
        return new ArrayList<>(remain);
    }
}