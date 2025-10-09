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


// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//         int i = 0;
//         int ans = 0;
//         int n = s.size();
//         unordered_map <char,int>mp;

//         for(int j = 0; j < n ; j++){
//             //calculation
//             mp[s[j]]++;
//             //shrink the window 
//             while(mp.size() == 3){
//                 ans += n - j;
//                 mp[s[i]]--;
//                 if(mp[s[i]] == 0){
//                     mp.erase(s[i]);
//                 }
//                 i++;
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int left = 0;
        int result = 0;
        int arr[3] = {0, 0, 0};

        for (int right = 0; right < n; right++) {
            arr[s[right] - 'a']++;

            // When all a,b,c are present, shrink from the left
            while (arr[0] > 0 && arr[1] > 0 && arr[2] > 0) {
                result += (n - right);  // all substrings from [left...right] to end are valid
                arr[s[left] - 'a']--;
                left++;
            }
        }

        return result;
    }
};
