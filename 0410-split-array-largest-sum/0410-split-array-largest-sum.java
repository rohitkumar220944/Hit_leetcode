class Solution {
    public boolean f(int[] nums, int k, int m) {
    int subarr = 1;
    int currsum = 0;

    for (int i = 0; i < nums.length; i++) {

        if (currsum + nums[i] > m) {
            subarr++;
            currsum = nums[i];

            if (subarr > k) {
                return false;
            }
        } else {
            currsum += nums[i];
        }
    }
    return true;
}

    public int splitArray(int[] nums, int k) {
        int n=nums.length;
        int totsum=0;
        int maxi=Integer.MIN_VALUE;
        for(int i=0;i<n;i++)
        {
            maxi=Math.max(maxi,nums[i]);
            totsum+=nums[i];
        }

        int s=maxi;
        int e=totsum;
        int ans=s;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(f(nums,k,mid))
            {
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
}