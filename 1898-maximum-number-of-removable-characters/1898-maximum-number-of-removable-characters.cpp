class Solution {
public:
     bool isSub(string s, string p){
        int n = s.length();
        int m = p.length();
        int j = 0;
        for(int i = 0; i<n && j<m; i++){
            if(s[i]==p[j])
                 j++;
        }
        return j==m;
    }
    //Check if p is subsequence of s after substituing characters for first k indexes from removable
    bool check(string &s, string &p, int k, vector<int>& removable){
        string temp = s;
        for(int i = 0; i<k; i++){
            temp[removable[i]] = '0';
        }
        return isSub(temp,p);
    }
    int maximumRemovals(string s, string p, vector<int>& removable) {
        string temp = s;
        int K = removable.size();
        int l = 0, r = K,mid,ans;
        //Binary search
        while(l<=r){
            mid = (l+r)/2;
            if(check(s,p,mid,removable)){
                l = mid +1 ;
                ans = mid;
            }else r = mid - 1;
        }
        
        return ans;
    }
};