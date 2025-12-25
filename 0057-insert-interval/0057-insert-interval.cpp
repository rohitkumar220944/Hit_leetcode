class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i=0;
        vector<vector<int>>result;
        int n=intervals.size();
        while(i<n && intervals[i][1]<newInterval[0])
        {
            result.push_back(intervals[i]);
            i++;
        }
        while(i<n && intervals[i][0]<=newInterval[1])
        {
            newInterval[0]=min(intervals[i][0],newInterval[0]);
            newInterval[1]=max(intervals[i][1],newInterval[1]);
            i++;
        }
        result.push_back({newInterval[0],newInterval[1]});
        while(i<n)
        {
            result.push_back(intervals[i]);
            i++;
        }
        return result;
    }
};