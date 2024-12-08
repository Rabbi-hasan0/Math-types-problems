<div>
  
### Problem: 01
```Sakurako's Box: Sakurako has a box with n balls. Each ball has it's value. She wants to bet with her friend that if the friend randomly picks two balls from the box (it could be two distinct balls, but they may have the same value), the product of their values will be the same as the number that Sakurako guessed.```

solution:
<div align="center">
  <img src="https://raw.githubusercontent.com/Rabbi-hasan0/Math-types-problems/main/1.%20Probablity%20Type/img/expected_value1.png" width="500" height="500">
</div>
Code:

```c++
#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
#define int long long
using namespace std;
const int mod = 1e9 + 7;

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
```
<p align="right">
  <a href="#top">
    <img src="https://img.shields.io/badge/Back%20to%20Top-%E2%86%A5-blue" alt="Back to Top">
  </a>
</p>

</div>

