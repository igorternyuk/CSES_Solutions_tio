#include <bits/stdc++.h>

#define ll long long
#define ld long double
const int N = 2e5;

int main()
{
    int n = 10;
    std::cin >> n;
    std::pair<int,int> movies[N];
    
    for(int i = 0; i < n; ++i)
    {
        std::cin >> movies[i].second >> movies[i].first;
    }

	std::sort(movies, movies + n);
	int ans = 0, last = 0;
	for(int i = 0; i < n; ++i)
	{
		if(movies[i].second >= last)
		{
            ++ans;
            last = movies[i].first;
		}		
	}

    std::cout << ans << std::endl;
    
    return 0;
}

