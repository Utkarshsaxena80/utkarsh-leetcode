class Solution {
public:
int f(int i,vector<vector<int>>&dp,int target,vector<int>&coins){
    if(target<0||i>=coins.size()) return 1e9;
    if(target==0) return 0;
    if(dp[i][target]!=-1) return dp[i][target];
    int notTake=f(i+1,dp,target,coins);
      int  take=1+f(i,dp,target-coins[i],coins);
    return dp[i][target]=min(take,notTake);
}
    int coinChange(vector<int>& coins, int amount) {
        //this is unbounded knapsack , why -> i can choose each index infinite number of times  
        // kanpsack is 2d dp 
        // 1 dimesnion for index and one for value 
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
       if(amount==0) return 0;
       int res=f(0,dp,amount,coins);
       if(res==1e9) return -1;
       return res;
    }
};