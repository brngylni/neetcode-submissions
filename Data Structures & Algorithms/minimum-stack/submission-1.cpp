class MinStack {

private:
    stack<long> main_stack;
    stack<long> min_stack;
    

public:
    MinStack() {}
    
    void push(int val) {
        main_stack.push(val);
        if(min_stack.empty()){
            min_stack.push(val);
            return;
        }


        if(min_stack.top() > val){
            min_stack.push(val); 
            return;
        }
        min_stack.push(min_stack.top());
    }
    
    void pop() {
        main_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return main_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};
