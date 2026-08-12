class MinStack {
private:
    std::stack<int> data;
    std::stack<int> minStack;
public:
    MinStack() = default;
    
    void push(int val) {
        data.push(val);
        if (minStack.empty())
            minStack.push(val);
        else
            minStack.push(std::min(val, minStack.top()));
    }
    
    void pop() {
        data.pop();
        minStack.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
