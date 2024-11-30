
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define loop(N) for(ll i{0}; i < N; ++i)

ll N = 1;

int main()
{
   
    std::cin >> N;
    if(N == 1)
        std::cout << 1;
    else if(N >= 2 && N <= 3)
    {
        std::cout << "NO SOLUTION";
    }
    else
    {
        for(ll i = 2; i < N+1; i += 2)
            std::cout << i << " ";
        for(ll i = 1; i < N+1; i += 2)
            std::cout << i << " ";
    }
    
    return 0;
}
