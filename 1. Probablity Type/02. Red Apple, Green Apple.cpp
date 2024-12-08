#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
#define int long long
using namespace std;
const int mod = 998244353;

int power(int n, int k, int mod) { 
  int ans = 1 % mod; 
  n %= mod; 
  if (n < 0) n += mod;
  while (k) {
    if (k & 1) {
        ans = ans * n % mod;
    }
    n = n * n % mod;
    k >>= 1;
  }
  return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; //cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for(auto &i: a) cin >> i;
        for(auto &i: b) cin >> i;

        int total = 0;
        int inv_2 = power(2, mod - 2, mod);
        for(int i = 0; i < n; ++i) {
            int cur = (a[i] + b[i]) % mod * inv_2 % mod;
            total = (total + cur) % mod;
        }

        int inv_n = power(n, mod - 2, mod);
        int total_avg = (total * inv_n) % mod;
        
        int ans = total_avg;
        for(int i = 0; i < n; ++i) {
            cout << ans << " \n"[i == n - 1];
            ans = (ans + total_avg) % mod;
        }
    }
    return 0;
}
