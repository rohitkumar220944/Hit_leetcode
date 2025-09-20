class Solution {
public:
    int f(int i,string &s1,int j,string &s2, vector<vector<int>> &dp)
    {
        if(i<0||j<0)return 0;

        if(dp[i][j]!=-1)return dp[i][j];

        if(s1[i]==s2[j])return dp[i][j]=1+f(i-1,s1,j-1,s2,dp);
        else
        return dp[i][j]= max(f(i-1,s1,j,s2,dp),f(i,s1,j-1,s2,dp));
        

    }
    int longestCommonSubsequence(string s1, string s2) {
        
        int n=s1.size();
        int m=s2.size();

        vector<vector<int>>dp(n,vector<int>(m,-1));

        return f(n-1,s1,m-1,s2,dp);
    }
};