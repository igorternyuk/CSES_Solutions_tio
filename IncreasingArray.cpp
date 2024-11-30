
#include <bits/stdc++.h>
#include <cassert>
#include <random>

#define ll long long
#define ld long double
#define loop(N) for(ll i{0}; i < N; ++i)

/*#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
*/

int main()
{
    ll N = 10;
    std::cin >> N;
    std::vector<ll> a; // {6, 10, 4, 10, 2, 8, 9, 2, 7, 7};
    a.reserve(N);
    ll j;
    loop(N)
    {
    std::cin >> j;
       a.push_back(j);
    }
    if(N == 1)
        std::cout << 0;
    else
    {
        ll total = 0;
        for(ll i{1}; i < N; ++i)
        {
            ll prev = a[i-1];
            if(a[i] < prev)
            {
                total += prev - a[i];
                a[i] = prev;
            }
        }
        std::cout << total;
    }

    return 0;
}
