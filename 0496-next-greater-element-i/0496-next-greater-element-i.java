class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        Stack<Integer>st=new Stack<>();
        st.push(-1);
        HashMap<Integer,Integer>map=new HashMap<>();
        

        for(int i=nums2.length-1;i>=0;i--)
        {
              int curr=nums2[i];
              while(st.peek()!=-1 && st.peek()<=curr)
              {
                st.pop();
              }
              map.put(curr ,st.peek());
              st.push(nums2[i]);
        }
        
        int [] result=new int[nums1.length];
        for( int i=0;i<nums1.length;i++)
        {
            result[i]=map.get(nums1[i]);
        }
        return result;
    }
}