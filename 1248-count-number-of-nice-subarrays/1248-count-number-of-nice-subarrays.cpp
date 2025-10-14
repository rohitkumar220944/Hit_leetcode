class Solution {
public:
    int f(vector<int>& nums, int k)
    {
        int n=nums.size();
        int l=0;
        int r=0;
        int sum=0;
        int cnt=0;
        if(k<0)return 0;
        while(r<n)
        {
            sum+=nums[r]%2;
           while(sum>k)
            {
                sum=sum-nums[l]%2;
                l=l+1;
            }
            cnt=cnt+(r-l+1);
            r=r+1;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return f(nums,k)-f(nums,k-1);
    }
};