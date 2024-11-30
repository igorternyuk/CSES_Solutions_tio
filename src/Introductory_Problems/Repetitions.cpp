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
    std::string s;
    std::cin >> s;
    ll maxLength = 1;
    ll currLength = 1;
    for(size_t i {1}; i < s.size(); ++i)
    {
        if(s[i] == s[i-1])
        {
            ++currLength;
            maxLength = std::max(maxLength, currLength);
        }
        else
        {
            currLength = 1;
        }

    }
    std::cout << maxLength;
    return 0;
}
