// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++
bool check(int a[], int n, int m,int mid)
{
    int curr = 0,i,s=1;
    for(i=0;i<n;++i)
    {
        if(a[i] > mid)
        return false;
        if(curr + a[i] > mid)
        {
            s++;
            curr = a[i]; 
            
            if(s > m)
                return false;
        }
        else
        curr+=a[i];
        
    }
    return true;
}
class Solution 
{
    public:
    //Function to find minimum number of pages.
    int findPages(int a[], int n, int m) 
    {
        //code here
        if(n < m)
            return -1;
        int sum=0,l,r,ans=0;
        for(int i=0;i<n;++i)
        {
            sum+=a[i];
        }
        l=0;
        r=sum;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            if(check(a,n,m,mid) == true)
            {
               ans = mid;
               r = mid -1;
            }
            else
             l = mid+1;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends