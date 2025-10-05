class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int leftsum=0;
        int rightsum=0;
        int maxsum=0;
        for(int i=0;i<k;i++)
        {
            leftsum=leftsum+cardPoints[i];
        
        }
        maxsum=leftsum;
        int rightlen=cardPoints.size()-1;
        for(int i=k-1;i>=0;i--)
        {
           leftsum=leftsum-cardPoints[i];
           rightsum=rightsum+cardPoints[rightlen];
           rightlen=rightlen-1;
           
            maxsum=max(maxsum,leftsum+rightsum);
        }
         return maxsum;
        
    }
   
};