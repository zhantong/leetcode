class AllOne {
public:
    class Node {
    public:
        Node *prev;
        Node *next;
        unordered_set<string> keys;
    };

    unordered_map<string, int> keys;
    unordered_map<int, Node *> times;
    Node *head;
    Node *tail;


    /** Initialize your data structure here. */
    AllOne() {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if (keys.find(key) != keys.end()) {
            int time = keys[key];
            times[time]->keys.erase(key);
            int newTime = time + 1;
            if (times.find(newTime) == times.end()) {
                Node *node = new Node();
                node->prev = times[time]->prev;
                node->next = times[time];
                node->prev->next = node;
                node->next->prev = node;
                times[newTime] = node;
            }
            times[newTime]->keys.insert(key);
            keys[key] = newTime;
            if (times[time]->keys.empty()) {
                Node *node = times[time];
                node->prev->next = node->next;
                node->next->prev = node->prev;
                times.erase(time);
            }
        } else {
            if (times.find(1) == times.end()) {
                Node *node = new Node();
                node->prev = tail->prev;
                node->next = tail;
                node->prev->next = node;
                node->next->prev = node;
                times[1] = node;
            }
            times[1]->keys.insert(key);
            keys[key] = 1;
        }
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (keys.find(key) == keys.end()) {
            return;
        }
        int time = keys[key];
        times[time]->keys.erase(key);
        int newTime = time - 1;
        if (newTime > 0) {
            if (times.find(newTime) == times.end()) {
                Node *node = new Node();
                node->prev = times[time];
                node->next = times[time]->next;
                node->prev->next = node;
                node->next->prev = node;
                times[newTime] = node;
            }
            times[newTime]->keys.insert(key);
            keys[key] = newTime;
        } else {
            keys.erase(key);
        }
        if (times[time]->keys.empty()) {
            Node *node = times[time];
            node->prev->next = node->next;
            node->next->prev = node->prev;
            times.erase(time);
        }
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if (head->next == tail) {
            return "";
        }
        return *(head->next->keys.begin());
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if (tail->prev == head) {
            return "";
        }
        return *(tail->prev->keys.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */