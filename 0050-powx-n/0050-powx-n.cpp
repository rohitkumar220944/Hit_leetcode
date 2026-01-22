class Solution {
public:
    double myPow(double x, int n) {
        if(n<0)
        {
            x=1/x;
            n=-n;
        }
        double result=1;
        double current_pro=x;
        while(n>0)
        {
            if(n%2==1)
            {
                result=result*current_pro;
            }
            current_pro=current_pro*current_pro;
            n=n/2;
        }
        return result;
    }
};