public class MyQueue {
    Stack<Integer> stackA;
    Stack<Integer> stackB;

    /**
     * Initialize your data structure here.
     */
    public MyQueue() {
        stackA = new Stack<>();
        stackB = new Stack<>();
    }

    /**
     * Push element x to the back of queue.
     */
    public void push(int x) {
        stackA.add(x);
    }

    /**
     * Removes the element from in front of queue and returns that element.
     */
    public int pop() {
        if (stackB.empty()) {
            while (!stackA.empty()) {
                stackB.add(stackA.pop());
            }
        }
        return stackB.pop();
    }

    /**
     * Get the front element.
     */
    public int peek() {
        if (stackB.empty()) {
            while (!stackA.empty()) {
                stackB.add(stackA.pop());
            }
        }
        return stackB.peek();
    }

    /**
     * Returns whether the queue is empty.
     */
    public boolean empty() {
        return stackA.empty() && stackB.empty();
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */