class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxlen=0;
        int l=0;
        int r=0;
        int zeros=0;
        int n=nums.size();
        while(r<n)
        {
            if(nums[r]==0)zeros=zeros+1;

            if(zeros>k)
            {
                if(nums[l]==0)zeros--;
                l++;
            }
            if(zeros<=k)
            {
                int len=r-l+1;
                maxlen=max(maxlen,len);
            }
            r++;
        }
        return maxlen;
    }
};