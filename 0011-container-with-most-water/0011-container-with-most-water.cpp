class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int n=height.size();
        int right=n-1;
        int maxi=INT_MIN;

        while(left<right)
        {
           int currArea=min(height[left], height[right]) * (right-left);
           maxi=max(maxi,currArea);

           if(height[left]<height[right])
           {
            left++;
           }
           else{
            right--;
           }

        }
        return maxi;
    }
};