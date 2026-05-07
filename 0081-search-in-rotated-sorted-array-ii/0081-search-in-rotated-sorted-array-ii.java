class Solution {
    public boolean search(int[] arr, int key) {
         int n=arr.length;
        int s=0;
        int e=n-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            
            if(arr[mid]==key)
            {
                return true;
                
            }
            else if(arr[s]==arr[mid])
            {
                s++;
                continue;
            }
            else if(arr[s]<=arr[mid])
            {
                if(arr[s]<=key && key<=arr[mid])
                {
                    e=mid-1;
                }
                else{
                    s=mid+1;
                }
            }
            else{
                if(arr[mid]<=key && key<=arr[e])
                {
                    s=mid+1;
                }
                else{
                    e=mid-1;
                }
            }
        }
        return false;
    }
}