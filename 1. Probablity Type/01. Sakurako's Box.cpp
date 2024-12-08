/*
Explainnation include to be readme file of this folder 
*/

#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
#define int long long
using namespace std;
const int mod = 1e9 + 7;

int power(int n, int k, int mod) { // n^k % mod --> mod <= 10^9 [O(log(k))];
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

int tot(int n) {
    return n * (n - 1);
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        int sum = 0, res = 0;
        for(auto &i: a) {
            cin >> i;
            res += (i * i);
            sum += i;
            res %= mod;
            sum %= mod;
        }
        int cur = (sum * sum % mod - res + mod) % mod;   
        int cnt = power(tot(n), mod - 2, mod);
        cout << (cur * cnt) % mod << '\n';
    }
    return 0;
}
