class LRUCache {
    class Node {
    public:
        int key;
        int value;
        Node *prev;
        Node *next;

        Node(int key, int value) {
            this->key = key;
            this->value = value;
        }
    };

public:
    int capacity;
    unordered_map<int, Node *> memory;
    Node *head;
    Node *tail;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (memory.find(key) == memory.end()) {
            return -1;
        }
        Node *node = memory[key];
        toHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (memory.find(key) == memory.end()) {
            if (memory.size() == capacity) {
                memory.erase(tail->prev->key);
                remove(tail->prev);
            }
            Node *node = new Node(key, value);
            memory[key] = node;
            add(node);
        } else {
            Node *node = memory[key];
            node->value = value;
            toHead(node);
        }
    }

    void toHead(Node *node) {
        remove(node);
        add(node);
    }

    void remove(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void add(Node *node) {
        node->next = head->next;
        head->next = node;
        node->prev = head;
        node->next->prev = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */