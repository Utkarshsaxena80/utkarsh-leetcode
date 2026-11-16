class Solution {
public:
int f(int i,vector<int>&nums,vector<vector<int>>&dp,int sum){
    if(sum<0||i>=nums.size()) return 0;
    if(sum==0) return 1;
    if(dp[i][sum]!=-1) return dp[i][sum];
    int notTake=f(i+1,nums,dp,sum);
    int take=0;
    if(sum>=nums[i]) take=f(i+1,nums,dp,sum-nums[i]);
    return dp[i][sum]=take||notTake;
}
    bool canPartition(vector<int>& nums) {
        //in this i have to find a subsequence such that its sum is equal to the half of original array 
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0) return false;
        sum/=2;
        vector<vector<int>>dp(nums.size(),vector<int>(sum+1,-1));
        return f(0,nums,dp,sum);

    }
};