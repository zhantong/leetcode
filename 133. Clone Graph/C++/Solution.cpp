/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        class Utils {
        public:
            UndirectedGraphNode *clone(UndirectedGraphNode *node, unordered_map<int, UndirectedGraphNode *> &memory) {
                if (memory.find(node->label) == memory.end()) {
                    UndirectedGraphNode *copy = new UndirectedGraphNode(node->label);
                    memory[copy->label] = copy;
                    for (auto &neighbor : node->neighbors) {
                        copy->neighbors.push_back(clone(neighbor, memory));
                    }
                }
                return memory[node->label];
            }
        };
        if (node == nullptr) {
            return node;
        }
        Utils utils;
        unordered_map<int, UndirectedGraphNode *> memory;
        return utils.clone(node, memory);
    }
};