class Solution {
public:
    int gcd(int a , int b)
    {
        if(b == 0)
            return a;
        return gcd(b,a%b);
    }
    bool canMeasureWater(int x , int y , int z) 
    {
        if(x == z || y == z)
            return true;
        if(x + y < z)
            return false;
        if(z % gcd(x,y) == 0)
            return true;
        return false;
        
    }
};