#include <bits/stdc++.h>
#define ll long long

int main()
{
    int n, x;
    std::cin >> x >> n;
    std::set<int> s;
	s.insert(0);
	s.insert(x);
	std::map<int,int> mp_dst;
	mp_dst[x] = 1;
    for(int i = 0; i < n; ++i)
	{
		int pi;
		std::cin >> pi;
		//auto left = std::upper_bound(p.begin(), p.end(), pi);
		auto right = s.lower_bound(pi);
		auto left = std::next(right,-1);
		auto span = *right - *left;
		--mp_dst[span];
		if(!mp_dst[span])
			mp_dst.erase(span);
		auto spanL = pi-*left;
		auto spanR = *right-pi;
		s.insert(pi);
		++mp_dst[spanL];
		++mp_dst[spanR];
                      
		int ans = mp_dst.rbegin()->first;
    	std::cout << ans << " ";	
	}

	
    return 0;
}
