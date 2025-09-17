class Solution {
public:
    int f(vector<int>& cost, vector<int>& time, int ind, int tar, vector<vector<int>> &dp)
    {
        if(tar<=0)return 0;
        if(ind<0)return 1e9;

        if(dp[ind][tar]!=-1)return dp[ind][tar];

        int notpick=f(cost,time,ind-1,tar,dp);
        int pick=1e9;
        pick=cost[ind]+f(cost,time,ind-1,tar-(time[ind]+1),dp);

        return dp[ind][tar] = min(pick,notpick);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n=time.size();

        vector<vector<int>>dp(n,vector<int>(n+1,-1));
      
        return f(cost,time,n-1,n,dp);

    }
};