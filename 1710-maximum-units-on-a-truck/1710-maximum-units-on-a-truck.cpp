bool comp(vector<int>&a,vector<int>&b)
{
    return a[1]>b[1];
}
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),comp);
        int n=boxTypes.size();
        int maxunit=0;
        for(int i=0;i<n;i++)
        {
            if(boxTypes[i][0]<=truckSize)
            {
                maxunit+=boxTypes[i][0]*boxTypes[i][1];
                truckSize-=boxTypes[i][0];
            }
            else{
                int take=min(boxTypes[i][0],truckSize);
                maxunit+=take*boxTypes[i][1];
                break;
            }
        }
        return maxunit;
    }
};