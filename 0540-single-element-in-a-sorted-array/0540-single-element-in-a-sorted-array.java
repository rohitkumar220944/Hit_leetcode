// class Solution {
//     public int singleNonDuplicate(int[] nums) {
//         int n=nums.length;
//         if(n==1)return nums[0];
//        for(int i=0;i<n;i++)
//        {
//         if(i==0)
//         {
//             if(nums[i]!=nums[i+1])return nums[i];
//         }
//         else if(i==n-1)
//         {
//             if(nums[i]!=nums[i-1])return nums[i];
//         }
         
//         else if(nums[i]!=nums[i-1] && nums[i]!=nums[i+1])
//         {
//             return nums[i];
//         }
//        } 
//        return -1;
//     }
// }


class Solution {
    public int singleNonDuplicate(int[] nums) {
        int n=nums.length;
        if(n==1)return nums[0];
        int s=1;
        int e=n-2;
        if(nums[0]!=nums[1])return nums[0];
        if(nums[n-1]!=nums[n-2])return nums[n-1];
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(nums[mid-1]!=nums[mid] && nums[mid]!=nums[mid+1])
            {
                return nums[mid];
            }
            else if(mid%2==1 && nums[mid]==nums[mid-1] || mid%2==0 && nums[mid]==nums[mid+1])
            {
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return -1;
    }
}