class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> maxreq(26, 0);

        // Step 1: Build maximum letter requirements from words2
        for (auto w : words2) {
            vector<int> freq(26, 0);
            for (auto ch : w) {
                freq[ch - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                maxreq[i] = max(maxreq[i], freq[i]);
            }
        }

        vector<string> ans;

        // Step 2: Check each word in words1
        for (auto w : words1) {
            vector<int> freq(26, 0);
            for (auto ch : w) {
                freq[ch - 'a']++;
            }

            bool valid = true;
            for (int i = 0; i < 26; i++) {
                if (freq[i] < maxreq[i]) {
                    valid = false;
                    break;
                }
            }

            if (valid) ans.push_back(w);
        }

        return ans;
    }
};
