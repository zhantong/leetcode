class MyQueue {
    stack<int> stackA;
    stack<int> stackB;
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        stackA.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (stackB.empty()) {
            while (!stackA.empty()) {
                int item = stackA.top();
                stackB.push(item);
                stackA.pop();
            }
        }
        int result = stackB.top();
        stackB.pop();
        return result;
    }

    /** Get the front element. */
    int peek() {
        if (stackB.empty()) {
            while (!stackA.empty()) {
                int item = stackA.top();
                stackB.push(item);
                stackA.pop();
            }
        }
        return stackB.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return stackA.empty() && stackB.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */