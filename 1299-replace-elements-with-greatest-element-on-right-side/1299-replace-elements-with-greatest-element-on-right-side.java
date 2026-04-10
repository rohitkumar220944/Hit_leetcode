class Solution {
    public int[] replaceElements(int[] arr) {
        int n=arr.length;
        int []ans=new int[n];
        int idx=0;
       
        for(int i=0;i<n;i++)
        {
            int maxi=-1;
            for(int j=i+1;j<n;j++)
            {
                maxi=Math.max(maxi,arr[j]);

            }
            ans[i]=maxi;
            
        }
        return ans;
    }
}