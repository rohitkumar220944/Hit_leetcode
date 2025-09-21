// class Solution {
// public:
//     int f(int i,string &s1,int j,string &s2, vector<vector<int>> &dp)
//     {
//         if(i<0||j<0)return 0;

//         if(dp[i][j]!=-1)return dp[i][j];

//         if(s1[i]==s2[j])return dp[i][j]=1+f(i-1,s1,j-1,s2,dp);
//         else
//         return dp[i][j]= max(f(i-1,s1,j,s2,dp),f(i,s1,j-1,s2,dp));
        

//     }
//     int longestCommonSubsequence(string s1, string s2) {
        
//         int n=s1.size();
//         int m=s2.size();

//         vector<vector<int>>dp(n,vector<int>(m,-1));

//         return f(n-1,s1,m-1,s2,dp);
//     }
// };


class Solution {
public:

    int longestCommonSubsequence(string s1, string s2) {
        
        int n=s1.size();
        int m=s2.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int i=0;i<=n;i++) dp[i][0]=0;
        for(int j=0;j<=m;j++) dp[0][j]=0;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                dp[i][j]=1+dp[i-1][j-1];
                else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
       return dp[n][m];

       // for printing longest common subseque..

    //    int len=dp[n][m];
    //    int ind=len-1;
    //    string ans="";
       
    //    for(int i=0;i<len;i++)
    //    {
    //     ans+='$';
    //    }

    //    while(n>0 && m>0)
    //    {
    //     if(s1[n-1]==s2[m-1])
    //     {
    //         ans[ind]=s1[n-1];
    //         ind--;
    //         n--;
    //         m--;
    //     }
    //     else if(s1[n-1]>s1[m-1])
    //     {
    //         n--;
    //     }
    //     else{
    //         m--;
    //     }
    //    }

    //  cout<<ans;
    
        
    }
};





