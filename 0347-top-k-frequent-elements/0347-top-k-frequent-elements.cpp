class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //bucket sort//inseriton 
        //nice quesiton 
        unordered_map<int,int>mp;
        for(int n:nums){
            mp[n]++;
        }
        vector<vector<int>>bucket(nums.size()+1);
        for(auto [n,count]:mp){
            bucket[count].push_back(n);
        }
        vector<int>result;
        for(int f=bucket.size()-1;f>=0&&result.size()<=k;f--){
            for(int n:bucket[f]){
                result.push_back(n);
                if(result.size()==k) return result;
            }

        }
        

return {};
    }
};