class LFUCache {
public:
    class Node {
    public:
        int key;
        int value;
        int times;
        Node *prev;
        Node *next;

        Node(int key, int value, int times) {
            this->key = key;
            this->value = value;
            this->times = times;
        }
    };
    int initCapacity;
    int capacity;
    unordered_map<int, Node *> memoryNodes;
    unordered_map<int, Node *> memoryTimes;
    Node *head;
    Node *tail;

    LFUCache(int capacity) {
        initCapacity = capacity;
        this->capacity = capacity;
        head = new Node(-1, -1, -1);
        tail = new Node(-1, -1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (memoryNodes.find(key) == memoryNodes.end()) {
            return -1;
        }
        int value = memoryNodes[key]->value;
        put(key, value);
        return value;
    }

    void put(int key, int value) {
        if (initCapacity == 0) {
            return;
        }
        if (memoryNodes.find(key) != memoryNodes.end()) {
            Node *node = memoryNodes[key];
            node->value = value;
            if (memoryTimes.find(node->times + 1) != memoryTimes.end()) {
                if (memoryTimes[node->times] == node) {
                    if (node->next->times == node->times) {
                        memoryTimes[node->times] = node->next;
                    } else {
                        memoryTimes.erase(node->times);
                    }
                }
                node->prev->next = node->next;
                node->next->prev = node->prev;
                node->prev = memoryTimes[node->times + 1]->prev;
                node->next = memoryTimes[node->times + 1];
                node->next->prev = node;
                node->prev->next = node;
                memoryTimes[node->times + 1] = node;
            } else {
                if (memoryTimes[node->times] != node) {
                    node->prev->next = node->next;
                    node->next->prev = node->prev;
                    node->prev = memoryTimes[node->times]->prev;
                    node->next = memoryTimes[node->times];
                    node->next->prev = node;
                    node->prev->next = node;
                } else {
                    if (node->next->times == node->times) {
                        memoryTimes[node->times] = node->next;
                    } else {
                        memoryTimes.erase(node->times);
                    }
                }
                memoryTimes[node->times + 1] = node;
            }
            node->times++;
        } else {
            Node *node = new Node(key, value, 1);
            memoryNodes[key] = node;
            if (capacity == 0) {
                Node *nodeToRemove = tail->prev;
                if (memoryTimes[nodeToRemove->times] == nodeToRemove) {
                    memoryTimes.erase(nodeToRemove->times);
                }
                nodeToRemove->prev->next = nodeToRemove->next;
                nodeToRemove->next->prev = nodeToRemove->prev;
                memoryNodes.erase(nodeToRemove->key);
                capacity++;
            }
            if (memoryTimes.find(1) != memoryTimes.end()) {
                node->prev = memoryTimes[1]->prev;
                node->next = memoryTimes[1];
            } else {
                node->prev = tail->prev;
                node->next = tail;
            }
            node->prev->next = node;
            node->next->prev = node;
            memoryTimes[1] = node;
            capacity--;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */