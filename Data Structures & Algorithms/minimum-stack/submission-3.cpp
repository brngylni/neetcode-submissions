class MinStack {
private:
    stack<long> min_stack;
    long min;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(min_stack.empty()){
            min_stack.push(0);
            min = val;
            return;
        }
        min_stack.push(val - min);
        if(val < min){
            min = val;
        }

    }
    
    void pop() {
        if(min_stack.empty()) return;
        long pop = min_stack.top();

        min_stack.pop();

        if (pop<0) min = min - pop;


    }
    
    int top() {
        long top = min_stack.top();
        return (top>0) ? (top + min) : (int)min;
    }
    
    int getMin() {
        return (int)min;
    }
};
