class Solution {
    public int findKthPositive(int[] arr, int k) {
        int n=arr.length;
        int s=0;
        int e=n-1;

        while(s<=e)
        {
            int mid=s+(e-s)/2;
            int miss=arr[mid]-(mid+1);
            if(miss<k)
            {
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return e+1+k;
    }
}