class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int>stk ;
        for(int i=0;i<num.size();i++){
            while(!stk.empty()&&k>0&&num[i]<stk.top()) {
                stk.pop();
                k--;
            }
            stk.push(num[i]);
           // k--;
        }
        while(k>0&&!stk.empty()){
            stk.pop();
            k--;
        }

        string res="";
        while(!stk.empty()){
            res+=stk.top();
            stk.pop();
        }
        reverse(res.begin(),res.end());
        int i=0;
        while(i<res.size()) {
            if(num[i]==0) i++;
            else break;
        //    i++;
        }
           while(i<res.size()&&res[i]=='0') i++;
            string final=res.substr(i,res.size());
             return final.size()>0?final:"0";
    }
};