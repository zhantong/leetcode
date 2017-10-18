/**
 * Definition for undirected graph.
 * class UndirectedGraphNode {
 *     int label;
 *     List<UndirectedGraphNode> neighbors;
 *     UndirectedGraphNode(int x) { label = x; neighbors = new ArrayList<UndirectedGraphNode>(); }
 * };
 */
public class Solution {
    public UndirectedGraphNode cloneGraph(UndirectedGraphNode node) {
        class Utils {
            UndirectedGraphNode clone(UndirectedGraphNode node, Map<Integer, UndirectedGraphNode> memory) {
                if (!memory.containsKey(node.label)) {
                    UndirectedGraphNode copy = new UndirectedGraphNode(node.label);
                    memory.put(copy.label, copy);
                    for (UndirectedGraphNode neighbor : node.neighbors) {
                        copy.neighbors.add(clone(neighbor, memory));
                    }
                }
                return memory.get(node.label);
            }
        }
        if (node == null) {
            return node;
        }
        Utils utils = new Utils();
        Map<Integer, UndirectedGraphNode> memory = new HashMap<>();
        return utils.clone(node, memory);
    }
}