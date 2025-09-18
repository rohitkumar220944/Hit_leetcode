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


// class Solution {
// public:
//     int change(int amount, vector<int>& coins) {
//         int n = coins.size();
//         vector<vector<int>> dp(n, vector<int>(amount+1, 0));

//         // Base case: only using coins[0]
//         for(int tar=0; tar<=amount; tar++) {
//             if(tar % coins[0] == 0) dp[0][tar] = 1;
//         }

//         for(int ind=1; ind<n; ind++) {
//             for(int tar=0; tar<=amount; tar++) {
//                 int notTake = dp[ind-1][tar];
//                 int Take = 0;
//                 if(coins[ind] <= tar) Take = dp[ind][tar - coins[ind]];

//                 dp[ind][tar] = notTake + Take;
//             }
//         }

//         return dp[n-1][amount];
//     }
// };
