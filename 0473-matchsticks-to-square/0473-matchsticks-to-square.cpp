class Solution {
public:
    bool solve(int i,vector<int>& matchsticks,vector<int>&side,int target){
        if(i==matchsticks.size()){
            for(int j=0;j<4;j++){
                if(side[j]!=target){
                    return false;
                }
            }
            return true;
        }
        for(int j=0;j<4;j++){
            if(side[j]+matchsticks[i]<=target){
                side[j]+=matchsticks[i];
                if(solve(i+1,matchsticks,side,target)){
                    return true;
                }
                side[j]-=matchsticks[i];
            }
            if(side[j]==0){
                break;
            }
        }
        return false;

    }
    bool makesquare(vector<int>& matchsticks) {
        int total=0;
        for(int i :matchsticks){
            total+=i;
        }
        if(total%4!=0){
            return false;
        }
        int target=total/4;
        for(int i=0;i<matchsticks.size();i++){
            if(matchsticks[i]>target){
                return false;
            }
        }
        sort(matchsticks.rbegin(),matchsticks.rend());
        vector<int>side(4, 0);
        return solve(0,matchsticks,side,target);
    }
};