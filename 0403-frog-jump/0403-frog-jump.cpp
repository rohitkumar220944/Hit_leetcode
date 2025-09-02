class Solution {
public:
    unordered_map<int,int> mp; // stone position -> index
    int n;
    map<pair<int,int>, bool> memo; // (curr_index, prev_jump) -> result

    bool solve(vector<int>& s, int curr, int prev) {
        if (curr == n-1) return true; // reached last stone

        if (memo.count({curr, prev})) return memo[{curr, prev}];

        for (int next = prev-1; next <= prev+1; next++) {
            if (next > 0) {
                int next_stone = s[curr] + next;
                if (mp.find(next_stone) != mp.end()) { // stone exists
                    if (solve(s, mp[next_stone], next)) {
                        return memo[{curr, prev}] = true;
                    }
                }
            }
        }
        return memo[{curr, prev}] = false;
    }

    bool canCross(vector<int>& s) {
        n = s.size();
        for (int i = 0; i < n; i++) {
            mp[s[i]] = i;
        }
        return solve(s, 0, 0); // start from first stone, prev_jump=0
    }
};
