class Solution {
public:
    vector<string>f(int open,int close,string temp,vector<string>&ans)
    {
        if(open==0 && close==0)
        {
            ans.push_back(temp);
            return ans;
        }

        if(open!=0)f(open-1,close,temp+'(',ans);
        if(open<close)f(open,close-1,temp+')',ans);
        return ans;
    }
    vector<string> generateParenthesis(int n) {
        int open=n;
        int close=n;
        string temp="";
        vector<string>ans;
       return f(open,close,temp,ans);
    }
};