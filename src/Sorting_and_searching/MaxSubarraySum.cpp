#include <bits/stdc++.h>

#define ll long long
#define ld long double
const ll INF = 1e18;

int main()
{
    int n;
    std::cin >> n;
    
	ll msf = -INF;
	ll ans = -INF;
    for(int i = 0; i < n; ++i)
    {
		ll a;	
        std::cin >> a;
		msf = std::max(a, msf + a);
		ans = std::max(msf, ans);
    }

	std::cout << ans << std::endl;    
    return 0;
}

