class Solution {
public:
    int trap(vector<int>& height) {
      int n=height.size();
      int lpos=0;
      int rpos=n-1;
      int lmax=0;
      int rmax=0;
      int ans=0;

      while(lpos<rpos)
      {
        if(height[lpos]<height[rpos])
        {
            if(lmax>height[lpos])
            {
                ans+=lmax-height[lpos];
            }
            else{
                lmax=height[lpos];
            }
            lpos=lpos+1;
        }
        else{
            if(rmax>height[rpos])
            {
                ans+=rmax-height[rpos];
            }
            else{
                rmax=height[rpos];
            }
            rpos=rpos-1;
        }
      }
      return ans;
    }
};