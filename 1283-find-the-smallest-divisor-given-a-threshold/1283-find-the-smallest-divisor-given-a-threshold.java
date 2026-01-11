class Solution {
    public boolean f(int[] nums, int threshold,int d)
    {
        int n=nums.length;
        int sum=0;
        for(int i=0;i<n;i++)
        {
           // sum+=nums[i]/d+1;(7/3=2) but i need(7/3=3)
          
           sum += (nums[i] + d - 1) / d;
        }
        if(sum<=threshold)
        {
            return true;
        }
        else{
            return false;
        }
    }
    public int smallestDivisor(int[] nums, int threshold) {
        int n=nums.length;
        
        int mini=Integer.MAX_VALUE;
        int maxi=Integer.MIN_VALUE;
        for(int i=0;i<n;i++)
        {
           
            maxi=Math.max(maxi,nums[i]);
        }

        int s=0;
        int e=maxi;
        int ans=-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(f(nums,threshold,mid))
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