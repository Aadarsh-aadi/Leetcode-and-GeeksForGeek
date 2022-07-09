class MinStack {
public:
    stack<int> realS;
    stack<int> temp;
    MinStack() 
    {
        
    }
    
    void push(int val) 
    {
        realS.push(val);
        if(temp.empty() == true)
        {
            temp.push(val);
        }
        else
        {
            temp.push(min(val,temp.top()));
        }
    }
    
    void pop() 
    {
        realS.pop();
        temp.pop();
    }
    
    int top() 
    {
       return realS.top(); 
    }
    
    int getMin() 
    {
        return temp.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */