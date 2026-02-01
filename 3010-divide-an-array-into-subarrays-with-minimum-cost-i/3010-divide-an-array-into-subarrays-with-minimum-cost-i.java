// class Solution {
//     public int minimumCost(int[] nums) {
//         int n=nums.length;
//         int ans=Integer.MAX_VALUE;

//         for(int i=1;i<=n-2;i++)
//         {
//             for(int j=i+1;j<=n-1;j++)
//             {
//                 int cost=nums[0]+nums[i]+nums[j];
//                 ans=Math.min(cost,ans);
//             }
//         }
//         return ans;
//     }
// }


             
             //Optimal
             
class Solution {
    public int minimumCost(int[] nums) {
        int first=Integer.MAX_VALUE;
        int second=Integer.MAX_VALUE;
        int n=nums.length;

        for(int i=1;i<n;i++)
        {
            if(nums[i]<first)
            {
                second=first;
                first=nums[i];
            }
            else if(nums[i]<second)
            {
                second=nums[i];
            }
        }
        return nums[0]+first+second;
    }
}