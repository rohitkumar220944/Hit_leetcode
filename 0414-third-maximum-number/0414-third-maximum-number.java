// class Solution {
//     public int thirdMax(int[] nums) {

//         int first=Integer.MIN_VALUE;
//         int second=Integer.MIN_VALUE;
//         int third=Integer.MIN_VALUE;

//         for(int i=0;i<nums.length;i++)
//         {
//            if(nums[i]>first)
//            {
//             third=second;
//             second=first;
//             first=nums[i];
//            }
//            else if(first>nums[i] && nums[i]>second)
//            {
//             third=second;
//             second=nums[i];
//            }
//            else if(second>nums[i] && nums[i]>third){
//                   third=nums[i];
//            }
//         }
//      if(third==Integer.MIN_VALUE)
//      {
//         return first;
//      }
//      else{
//         return third;
//      }
        
//     }
// }

class Solution {
    public int thirdMax(int[] nums) {
      int n=nums.length;
      int cnt=1;
      Arrays.sort(nums);

      for(int i=n-2;i>=0;i--)
      {
          if(nums[i]!=nums[i+1])
          {
            cnt++;
            if(cnt==3)
            {
                return nums[i];
            }
          }
      }
      return nums[n-1];
        
    }
}