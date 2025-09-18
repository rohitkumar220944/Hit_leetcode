class Solution {
public:

    int f(int tar, vector<int> &arr, int ind, vector<vector<int>> &dp)
    {
        if(ind == 0) {
            return (tar % arr[0] == 0); // either 1 way or 0 ways
        }

        if(dp[ind][tar]!=-1)return dp[ind][tar];

        int notTake=f(tar,arr,ind-1,dp);
        int Take=0;
        if(arr[ind]<=tar)Take=f(tar-arr[ind],arr,ind,dp);

        return dp[ind][tar]=notTake+Take;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return f(amount,coins,n-1,dp);
    }
};