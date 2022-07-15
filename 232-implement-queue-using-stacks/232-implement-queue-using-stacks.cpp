class MyQueue {
    stack<int> input , output;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        int res;
        if(output.empty() == false)
        {
            res = output.top();
            output.pop();
            return res;
        }
        while(input.empty() == false)
        {
            res = input.top();
            input.pop();
            output.push(res);
        }
       res = output.top();
       output.pop();
       return res;   
    }
    
    int peek() 
    {
         int res;
        if(output.empty() == false)
        {
            res = output.top();
            return res;
        }
        while(input.empty() == false)
        {
            res = input.top();
            input.pop();
            output.push(res);
        }
       res = output.top();
       return res;   
    }
    
    bool empty() 
    {
        return input.empty() && output.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */