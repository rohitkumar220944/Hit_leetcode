class Solution {
public:
    bool isPalindrome(string s) {
        string ans="";
        for(auto c:s)
        {
            if(isalnum(c))
            {
                ans+=tolower(c);
            }
        }
        string ansr=ans;
        reverse(ansr.begin(),ansr.end());
        return ans==ansr;
    }
};