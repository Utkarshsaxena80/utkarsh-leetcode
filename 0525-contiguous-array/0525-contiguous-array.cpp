class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        //isme 0 ko -1 se place kardo and then find the longest subarray with sum 0
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) nums[i]=-1;
        }
        unordered_map<int,int>mp;
        int len=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
           sum+=nums[i];
           if(sum==0){
            len=max(len,i+1);
           }
           if(mp.find(sum)!=mp.end()){
            len=max(len,i-mp[sum]);
           }
           else if(mp.find(sum)==mp.end()){
            mp[sum]=i;
           }
        }
        return len;
    }
};