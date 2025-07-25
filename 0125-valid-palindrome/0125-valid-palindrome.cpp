class Solution {
public:
    // bool isPalindrome(string s) {
    //     string ans="";
    //     for(auto c:s)
    //     {
    //         if(isalnum(c))
    //         {
    //             ans+=tolower(c);
    //         }
    //     }
    //     string ansr=ans;
    //     reverse(ansr.begin(),ansr.end());
    //     return ans==ansr;

    // }



    bool isPalindrome(string s) {
    int left = 0, right = s.size() - 1;

    while (left < right) {
        // Move left forward if not alphanumeric
        while (left < right && !isalnum(s[left])) left++;

        // Move right backward if not alphanumeric
        while (left < right && !isalnum(s[right])) right--;

        // Compare characters in lower case
        if (tolower(s[left]) != tolower(s[right]))
            return false;

        left++;
        right--;
    }

    return true;
}

};