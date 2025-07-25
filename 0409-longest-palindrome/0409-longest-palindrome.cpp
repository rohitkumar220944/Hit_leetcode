class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mp;
        int oddcount=0;
        for(auto c:s)
        {
            mp[c]++;
            if(mp[c]%2==1)oddcount++;
            else   // even char 
            oddcount--;

        }
        if(oddcount>1)
        return s.length()-oddcount+1;
        return s.length();


//  Dry Run Example:
// Let’s take s = "abccccdd"

// Initialize:

// oddCount = 0

// ump = {} (unordered map)

// 1st Iteration: 'a'
//    ump['a'] = 1

//    1 % 2 == 1 → oddCount = 1

// 2nd Iteration: 'b'
//   ump['b'] = 1

// 1 % 2 == 1 → oddCount = 2

// 3rd Iteration: 'c'
//      ump['c'] = 1

// 1 % 2 == 1 → oddCount = 3

// 4th Iteration: 'c'
//     ump['c'] = 2

// 2 % 2 == 0 → oddCount = 2

// 5th Iteration: 'c'
// ump['c'] = 3

// 3 % 2 == 1 → oddCount = 3

// 6th Iteration: 'c'
// ump['c'] = 4

// 4 % 2 == 0 → oddCount = 2

// 7th Iteration: 'd'
// ump['d'] = 1

// 1 % 2 == 1 → oddCount = 3

// 8th Iteration: 'd'
// ump['d'] = 2

// 2 % 2 == 0 → oddCount = 2

    }
};