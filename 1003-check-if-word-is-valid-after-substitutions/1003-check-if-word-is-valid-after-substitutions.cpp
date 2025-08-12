class Solution {
public:
    bool isValid(string s) {
        if(s.size()==0)
        {
            return true;
        }
        int fnd=s.find("abc");
        if(fnd!=string::npos)
        {
            string tleft=s.substr(0,fnd);
            string trigh=s.substr(fnd+3,s.size());
            return isValid(tleft+trigh);
        }
        return false;
    }
};