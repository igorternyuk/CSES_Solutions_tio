#include <bits/stdc++.h>

#define ll long long
#define ld long double

int main()
{
    ll n;
    std::cin >> n;
    ll ans = 1;
    for(ll i = 1; i <= n; ++i)
        ans = 2*ans%((int)1e9+7);
    std::cout << ans << std::endl;
    return 0;
}
