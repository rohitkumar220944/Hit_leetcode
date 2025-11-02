class Solution {
public:

int f(int ind, int n, vector<int>& arr, int k, vector<int>&dp)
{   
    if(ind==n)return 0;
    int len=0;
    int maxi=0;
    int maxsum=0;
    if(dp[ind]!=-1)return dp[ind];
    for(int j=ind;j<min(n,ind+k);j++)
    {
       len++;
       maxi=max(maxi,arr[j]);
       int sum=maxi*len + f(j+1,n,arr,k,dp); 
       maxsum=max(maxsum,sum);
    }
    return dp[ind]=maxsum;
}
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
      int n =arr.size();
      vector<int>dp(n,-1);
      return f(0,n,arr,k,dp);  
    }
};