class Solution {
public:
    int minAddToMakeValid(string s) {
     int left=0;
     int curr=0;
     for(char c:s){
        cout<<curr;
        if(c=='(') {
            if(curr<=0) curr=1;
            else curr+=1;
        }
        else if(c==')') {
            if(curr<=0) left+=1;
            curr-=1;
        }
     }   
    // cout<<left;
    // return left;
    int right=0;
    curr=0;
for(int i=s.size()-1;i>=0;i--){
    char c=s[i];
      if(c==')') {
            if(curr<=0) curr=1;
            else curr+=1;
        }
        else if(c=='(') {
            if(curr<=0) right+=1;
            curr-=1;
        }
}
return left+right;
    }
};