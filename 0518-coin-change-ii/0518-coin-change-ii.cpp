class Solution {
public:
int f(int i,vector<int>&coins,vector<vector<int>>&dp,int t){
    if(t==0) return 1;
    if(t<0||i>=coins.size()) return 0;
    if(dp[i][t]!=-1) return dp[i][t];
    int notTake=f(i+1,coins,dp,t);
    int take=0;
    if(coins[i]<=t){
        take=f(i,coins,dp,t-coins[i]);
    }
    return dp[i][t]=take+notTake;
}
    int change(int amount, vector<int>& coins) {
        //this is also unbounded , but in this i have to count the total number of ways and not just the min possible variations 
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        return f(0,coins,dp,amount);
    }
};