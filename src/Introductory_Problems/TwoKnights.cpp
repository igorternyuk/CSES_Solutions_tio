#include <bits/stdc++.h>
#define ll long long
#define ld long double

ll TwoKnights(ll N)
{
    if(N == 1)
        return 0;
    ll N2 = N * N;
    ll total = N2 * (N2-1) / 2;
    /*
    Note that when we have two knights threatening each other, it actually forms either a 2×3 or 3×2 board.
    And for each of 2×3 and 3×2 boards, there are 2 ways of placing two knights so that they threaten each other.
    So, what we should do is to count how many 2×3 and 3×2 squares on n×n board.
    */
    ll forb = 4*(N-1)*(N-2);
    return total - forb;
}

int main()
{
    ll N;
    std::cin >> N;
    ll n = 1;
    while(n <= N)
    {
        std::cout << TwoKnights(n) << std::endl;
        ++n;
    }

    return 0;
}
