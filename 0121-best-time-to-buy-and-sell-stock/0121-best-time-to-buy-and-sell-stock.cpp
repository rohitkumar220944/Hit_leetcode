class Solution {
public:
    void maxprofitfinder(vector<int>& prices,int i,int&minprice,int&maxProfit)
    {   if(i==prices.size())return;
        if(prices[i]< minprice) minprice=prices[i];
        int todayprofit=prices[i]-minprice;
        if(todayprofit>maxProfit)maxProfit=todayprofit;

        maxprofitfinder(prices,i+1,minprice,maxProfit);

    }
    int maxProfit(vector<int>& prices) {
     int minprice=INT_MAX;
     int maxProfit=INT_MIN;
       maxprofitfinder(prices,0,minprice,maxProfit);
       return maxProfit; 
    }
};