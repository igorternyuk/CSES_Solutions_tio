#include <bits/stdc++.h>

#define ll long long
#define ld long double

int main()
{
    ll n;
    std::cin >> n;
    std::set<ll> s;
    while(n--)
    {
        ll i;
        std::cin >> i;
        s.insert(i);
    }
    
    std::cout << s.size() << std::endl;
    return 0;
}
