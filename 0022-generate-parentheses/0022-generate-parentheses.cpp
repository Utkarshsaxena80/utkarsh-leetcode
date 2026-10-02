class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>result;
        auto backtrack=[&](auto &&self,int left,int right,string curr)->void{
            if(curr.length()==2*n){
                result.push_back(curr);
                return ;
            }
            if(left<n) self(self,left+1,right,curr+'(');
            if(right<left) self(self,left,right+1,curr+')');
        };
        backtrack(backtrack,0,0,"");
        return result;
    }
};