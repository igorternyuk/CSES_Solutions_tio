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
    ll N;
    std::cin >> N;
    std::vector<ll> a;
    a.reserve(N-1);
    ll j;
    loop(N-1)
    {
        std::cin >> j; 
        a.push_back(j);
    }
    ///a.push_back(1);
    std::sort(a.begin(), a.end());
    bool found = false;
    for(ll i{1}; i < N; ++i)
    {
        if(a[i]-a[i-1] == 2)
        {
            std::cout<<a[i-1]+1;
            found = true;
            break;
        }
    }
    if(!found)
    {
        if(a[0] == 1)
            std::cout<<a[N-2]+1;
        else
            std::cout<<a[0] - 1;
    }
    return 0;
}
