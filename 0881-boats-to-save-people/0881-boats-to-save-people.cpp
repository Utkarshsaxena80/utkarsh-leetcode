class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
    //     int count=0;
    //     int curr=0;
    //     for(int x:people){
    //         int o=curr;
    //         curr+=x;
    //         if(curr>=limit){
    //             count++;
    //             curr-=o;
    //         }
    //     }
    //    // if(curr>0) count++;
    //     return count;
    //this  was wrong because the local choice will not lead to global best 
    sort(people.begin(),people.end());
    int l=0;
    int r=people.size()-1;
    int count=0;
    while(l<=r){
        if(people[l]+people[r]<=limit) l++;
        r--;
        count++;
    }
    return count;
    }
};