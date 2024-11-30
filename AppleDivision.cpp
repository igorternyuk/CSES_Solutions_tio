#include <bits/stdc++.h>

#define ll long long
#define ld long double

int main()
{
    ll n;
    std::cin >> n;
    std::vector<ll> weights;
    weights.reserve(n);
    ll totalWeight = 0;
    for(ll i = 0; i < n; ++i)
    {
        ll w;
        std::cin >> w;
        totalWeight += w;
        weights.push_back(w);
    }
    
    ll N = 1 << n;
    ll a = 1;
    ll diffMin = a<<60;
    //ll ans = 0;
    for(ll i = 0; i < N; ++i)
    {
        ll leftTotal = 0 , rightTotal = 0;
        for(int j = 0; j < n; ++j)
        {
            ll m = 1 << j;
            if(m & i)
                leftTotal += weights[j];
            else
                rightTotal += weights[j];
        }
        ll diff = leftTotal - rightTotal;
        if(diff < 0)
            diff *= -1;
        if(diff < diffMin)
            diffMin = diff;  
    }
    
    std::cout << diffMin << std::endl;
    return 0;
}

