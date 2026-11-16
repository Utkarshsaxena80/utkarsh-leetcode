class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int p=0;
        int i=0,j=0;
        while(j<prices.size()){
            p=max(p,prices[j]-prices[i]);
            if(prices[j]<prices[i]) i=j;
            j++;
        }
        return p;
    }
};