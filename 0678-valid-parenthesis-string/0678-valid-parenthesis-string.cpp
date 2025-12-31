

// class Solution {
// public:
//     bool f(int ind,int cnt, string s)
//     {
//         if(cnt<0)return false;
//          int n=s.size();
//         if(ind==n)
//         {
//             if(cnt==0)
//             return true;
//             else
//             return false;
//         }

//         if(s[ind]=='(')
//         return f(ind+1,cnt+1,s);

//         if(s[ind]==')')return f(ind+1,cnt-1,s);

//         if(s[ind]=='*')
//         {
//             if(f(ind+1,cnt+1,s)||f(ind+1,cnt-1,s)||f(ind+1,cnt,s))
//             {
//                 return true;
//             }
//             else 
//             return false;
//         }
//         else 
//         return false;

//     }
//     bool checkValidString(string s) {
//         return f(0,0,s);
//     }
// };


class Solution {
public:
    bool checkValidString(string s) {
      int min=0;
      int max=0;
      for(int i=0;i<s.size();i++)
      {
        if(s[i]=='(')
        {
            min+=1;
            max+=1;
        }
        else if(s[i]==')')
        {
            min-=1;
            max+=1;
        }
        else{
            min-=1;
            max+=1;
        }
        if(min<0)
        {
            min=0;
        }
        if(max<0)return false;
      }
      return (min==0);
    }
};