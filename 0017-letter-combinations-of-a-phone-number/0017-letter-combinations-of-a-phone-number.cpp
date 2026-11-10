class Solution {
public:
vector<string>result;
void f(int i,string digits,string curr,string mapping[]){
    if(i>=digits.size()){
        result.push_back(curr);
        return;
    }
    char ch=digits[i];
    for(char c:mapping[ch-'0']){
        curr.push_back(c);
        f(i+1,digits,curr,mapping);
        curr.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
     if(digits.empty()) return {};
     string mapping[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"}   ;
     f(0,digits,"",mapping);
     return result;
    }
};