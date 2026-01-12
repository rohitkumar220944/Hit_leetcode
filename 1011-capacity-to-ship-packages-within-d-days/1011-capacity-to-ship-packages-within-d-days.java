class Solution {
    public int f(int[] weights, int cap)
    {
        int day=1;
        int load=0;
        int n=weights.length;
        for(int i=0;i<n;i++)
        {
            if(load + weights[i]>cap)
            {
                day=day+1;
                load=weights[i];
            }
            else{
                load=load+weights[i];
            }
        }
        return day;
    }
    public int shipWithinDays(int[] weights, int days) {
        int n=weights.length;
        int maxi=Integer.MIN_VALUE;
        for(int i=0;i<n;i++)
        {
            maxi=Math.max(maxi,weights[i]);
        }
        
        int total_sum=0;
        for(int i=0;i<n;i++)
        {
            total_sum=total_sum+weights[i];
        }

        int s=maxi;
        int e=total_sum;
        int ans=maxi;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(f(weights,mid)<=days)
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