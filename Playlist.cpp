#include <bits/stdc++.h>

#define ll long long
#define ld long double
const ll INF = 1e18;

int main()
{
    int n = 10;
    std::cin >> n;
    //std::vector<int> test {2, 2, 1, 1, 2, 1, 2, 1, 2, 1,};
    std::vector<int> p;
	p.reserve(n);
    for(int i = 0; i < n; ++i)
    {
		int pi;
        std::cin >> pi;
		p.push_back(pi);
    }

    int ans = 0;
	std::map<int,int> mapa; // frequency map
    for(int i = 0, j = 0; i < n; ++i)
    {
        auto val = mapa[p[i]];
		while(j < n && mapa[p[j]] < 1)
		{
		   mapa[p[j]]++;
           ++j;
		}
		int dist = j-i;
        ans = std::max(dist,ans);
        mapa[p[i]]--;
    }
    std::cout << ans << std::endl;
    return 0;
}
