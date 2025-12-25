 bool comp(vector<int>&a,vector<int>&b)
    {
        return a[1]<b[1];
    }
class Solution {
public:
   
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()==0)return 0;
        int cnt=1;
        sort(intervals.begin(),intervals.end(),comp);
        int ended=intervals[0][1];
        int n=intervals.size();
        for(int i=1;i<n;i++)
        {
            if(intervals[i][0]>=ended)
            {
                cnt +=1;
                ended=intervals[i][1];
            }
        }
        return n-cnt;
    }
};