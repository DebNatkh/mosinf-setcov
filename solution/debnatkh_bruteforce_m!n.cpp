#include <bits/stdc++.h>
// #define int long long
#define x first
#define y second
#define hashset unordered_set
#define hashmap unordered_map
#define getbit(x, i) (((x) >> (i)) & 1)
using namespace std;
typedef pair<int, int> pii;
template <typename T>
inline vector<T> readvector(size_t size) {
    vector<T> res(size);
    for (size_t i = 0; i < size; ++i) {
        cin >> res[i];
    }
    return res;
}
template <typename T>
inline void printvector(vector<T> &arr, string sep = " ", string ends = "\n") {
    for (size_t i = 0; i < arr.size(); ++i) {
    }
}
inline int binPow(int x, int deg, int mod) {
    int ans = 1;
    for (int i = sizeof(x) * CHAR_BIT - 1; i >= 0; i--) {
        ans *= ans;
        ans %= mod;
        if (getbit(deg, i)) ans *= x;
        ans %= mod;
    }
    return ans;
}

// =======================


void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> usage(m);
    for (int i = 0; i < m; i++) {
        int k; cin >> k;
        usage[i] = readvector<int>(k);
    }
    vector<int>order(m);
    for (int i = 0; i < m; i++) order[i] = i;
    int ans = 0;
    vector <int> ans_order;
    do {
        vector<bool> used(n + 1, false);
        for (auto i : order) {
            bool flag = true;
            for (auto j : usage[i]) {
                if (used[j]) {
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
            for (auto j : usage[i]) 
                used[j] = 1;
        }
        ans = max(ans, accumulate(used.begin(), used.end(), 1));
        if (ans == accumulate(used.begin(), used.end(), 1)) {
            ans_order = order;
        }
    } while (next_permutation(order.begin(), order.end()));

    int cnt = 0;
    vector<bool> used(n + 1, false);
    vector<int> answer;
    for (auto i : ans_order) {
        bool flag = true;
        for (auto j : usage[i]) {
            if (used[j]) {
                flag = false;
                break;
            }
        }
        if (!flag) break;
        for (auto j : usage[i]) 
            used[j] = 1;
        cnt++;
        answer.push_back(i);
    }
    cout << cnt << endl;
    for (auto e : answer) cout << ++e << " "; cout << endl;

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}