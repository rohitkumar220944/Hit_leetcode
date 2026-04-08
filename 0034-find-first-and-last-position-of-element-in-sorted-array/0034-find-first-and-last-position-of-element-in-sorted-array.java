// class Solution {
//     public int[] searchRange(int[] nums, int target) {
//         int n=nums.length;
//         int s=-1;
//         int e=-1;
//        for(int i=0;i<n;i++)
//        {
//         if(nums[i]==target)
//         {
//             s=i;
//             break;
//         }
//        }

//        for(int i=n-1;i>=0;i--)
//        {
//         if(nums[i]==target)
//         {
//             e=i;
//             break;
//         }
//        }
//        return new int[]{s,e};
//     }
// }


class Solution {
    public int lowerbound(int []nums, int target){
        int n=nums.length;
        int s=0;
        int e=n-1;
        int ans=-1;
        while(s<=e)
        {
            int m=s+(e-s)/2;
            if(nums[m]==target){
                ans=m;
                e=m-1;
            }
            else if(nums[m]>target)
            {
                e=m-1;
            }
            else{
                s=m+1;
            }
        }
       return ans;
    }

    public int upperbound(int []nums,int target)
    {
        int n=nums.length;
        int s=0;
        int e=n-1;
        int ans=-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(nums[mid]==target){
                ans=mid;
                s=mid+1;
            }
            else if(nums[mid]>target)
            {
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
    public int[] searchRange(int[] nums, int target) {
     return new int[]{lowerbound(nums,target),upperbound(nums,target)};
    }
}