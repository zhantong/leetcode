class MinStack {
    stack<int> sta;
    stack<int> min;
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        sta.push(x);
        if (min.empty() || x <= min.top()) {
            min.push(x);
        }
    }

    void pop() {
        int item = sta.top();
        sta.pop();
        if (item == min.top()) {
            min.pop();
        }
    }

    int top() {
        return sta.top();
    }

    int getMin() {
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */