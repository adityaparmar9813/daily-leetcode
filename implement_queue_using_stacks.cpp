class MyQueue {
    stack<int> s1, s2;
    int front = 0;
public:
    MyQueue() {}
    
    void push(int x) {
        if (s1.empty()) front = x;
        s1.push(x);
    }
    
    int pop() {
        if (s2.empty()) {
            while(!s1.empty()){
                int top = s1.top();
                s1.pop();
                s2.push(top);
            }
        }
        int top = s2.top();
        s2.pop();
        return top;
    }
    
    int peek() {
        if (!s2.empty()){
            return s2.top();
        }
        return front;
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)
