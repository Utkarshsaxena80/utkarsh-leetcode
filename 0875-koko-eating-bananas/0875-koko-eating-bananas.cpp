class Solution {
public:
bool isokay(vector<int>&piles,int mid,int h){
    int curr=0;
    for(int n:piles){
        curr+=n/mid;
        if(n%mid!=0) curr++;
    }
    return curr<=h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=*max_element(piles.begin(),piles.end());
        while(l<r){
            int mid=l+(r-l)/2;
            if(isokay(piles,mid,h))r=mid;
            else l=mid+1;
        }
        return l;
    }
};