// class Solution {
// public:
//     int sumSubarrayMins(vector<int>& arr) {
//         int sum=0;
//         int mini=INT_MAX;
//         for(int i=0;i<arr.size();i++)
//         {
//             int mini=arr[i];
//             for(int j=i;j<arr.size();j++)
//             {
//                 mini=min(mini,arr[j]);
//                 sum=sum+mini;
//             }
//         }
//         return sum;
//     }
// };
class Solution {
public:
    vector<int> nextsmall(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, n);  
        stack<int> s;

        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] > arr[i]) {
                s.pop();
            }
            ans[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        return ans;
    }

    vector<int> prevsmall(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1); 
        stack<int> s;

        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            ans[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        return ans;
    }

   int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1e9+7;
        int n = arr.size();
        vector<int> prev = prevsmall(arr);
        vector<int> next = nextsmall(arr);

        long long total = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - prev[i];
            long long right = next[i] - i;
            total = (total + (left * right % MOD) * arr[i]) % MOD;
        }
        return (int)total;
    }
};