#include <bits/stdc++.h>

#define ll long long
#define ld long double
const int N = 2e5;

int main()
{
    ll n;
    std::cin >> n;
	ll p[N];

   	for(int i = 0; i < n; ++i)
	{
		int pi;
		std::cin >> pi;
		p[i] = pi;
	}

	std::sort(p, p + n);
	ll cost = 0;
	ll mediana = p[n / 2];
	for(int i = 0; i < n; ++i)
		cost += abs(p[i] - mediana);

	std::cout << cost << std::endl;
    return 0;
}
