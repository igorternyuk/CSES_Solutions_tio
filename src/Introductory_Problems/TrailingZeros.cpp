#include <bits/stdc++.h>

#define ll long long
#define ld long double

int main()
{
    ll n;
    std::cin >> n;
    ll ans = 0;
    for(ll i = 5; i <= n; i*=5)
        ans += n/i;
    std::cout << ans << std::endl;
    return 0;
}

