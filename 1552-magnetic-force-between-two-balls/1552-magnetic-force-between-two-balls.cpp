class Solution {
public:
    bool ispossible(int mid,vector<int>&position,int m){
        int cnt=1;
        int prev=position[0];
        for(int i=1;i<position.size();i++){
            if((position[i]-prev)>=mid){
                cnt++;
                prev=position[i];
            }
        }
        if(cnt>=m)return true;
        return false;
        
    }
    int maxDistance(vector<int>& position, int m) {
        
        sort(position.begin(),position.end());
        int s=1;
        int ans=1;
        int e=position.back()-position.front();
        while(s<=e){
            int mid=(s+e)/2;
            if(ispossible(mid,position,m)){
                ans=max(ans,mid);
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return ans;
        
    }
};