// class Solution {
// public:
//     int numberOfSubstrings(string s) {
        
//         int n=s.size();
//         int count=0;
//         unordered_map<char,int>mp;

//         for(int i=0;i<n;i++)
//         {  
//              unordered_map<char,int>mp;
//             for(int j=i;j<n;j++)
//             {
//                 mp[s[j]]++;
//                 if (mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0) {
//                     count += (n - j);
//                     break;
//                 }
//             }
//         }
//         return count ;
//     }
// };


class Solution {
public:
    int numberOfSubstrings(string s) {
        int i = 0;
        int ans = 0;
        int n = s.size();
        unordered_map <char,int>mp;

        for(int j = 0; j < n ; j++){
            //calculation
            mp[s[j]]++;
            //shrink the window 
            while(mp.size() == 3){
                ans += n - j;
                mp[s[i]]--;
                if(mp[s[i]] == 0){
                    mp.erase(s[i]);
                }
                i++;
            }
        }
        return ans;
    }
};