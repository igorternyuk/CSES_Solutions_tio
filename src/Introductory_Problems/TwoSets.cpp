#include <bits/stdc++.h>
#include <cassert>
#include <random>

#define ll long long
#define ld long double

int main()
{
    ll N = 8;
    //std::cin >> N;
    ll sum = N*(N+1)/2;
    
    if(sum&1)
    {
        std::cout << "NO" << std::endl;
        return 0;
    }
    
    std::vector<ll> v1;
    std::vector<ll> v2;
    
    //1423
    int num = N%4 ? 3 : 4;
    for(ll i {0}; i < (N-1)/4;++i)
    {
        v1.push_back(4*i+1+num);
        v1.push_back(4*i+4+num);
        v2.push_back(4*i+3+num);
        v2.push_back(4*i+2+num);
    }
    if(N%4)
    {
        v1.push_back(1);
        v1.push_back(2);
        v2.push_back(3);
    }
    else
    {
        v1.push_back(1);
        v1.push_back(4);
        v2.push_back(3);
        v2.push_back(2);
    }
    
    std::cout << "YES" << std::endl;
    std::cout << v1.size() << std::endl;
    for(auto i: v1)
        std::cout << i << " ";
    std::cout << "\n" << v2.size() << std::endl;
    for(auto i: v2)
        std::cout << i << " ";
    return 0;
}
