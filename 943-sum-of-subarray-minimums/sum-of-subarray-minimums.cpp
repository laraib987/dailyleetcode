class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
       const int MOD = 1e9 + 7;
    int n = arr.size();
    vector<int> left(n), right(n);

    stack<int> st;

    // Find Previous Smaller Element (strictly)
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
        left[i] = st.empty() ? i + 1 : i - st.top();
        st.push(i);
    }

    // Clear stack for Next Smaller Element
    while (!st.empty()) st.pop();

    // Find Next Smaller Element (non-strict)
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
        right[i] = st.empty() ? n - i : st.top() - i;
        st.push(i);
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        long long contrib = (1LL * arr[i] * left[i] * right[i]) % MOD;
        ans = (ans + contrib) % MOD;
    }

    return ans;

        
    }
};