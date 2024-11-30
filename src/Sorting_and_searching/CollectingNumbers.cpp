#include <bits/stdc++.h>
 
#define ll long long
#define ld long double
 
int main()
{
    int n = 5;
    std::cin >> n;
    std::map<int,int> a; //{4, 2, 1, 5, 3};
    
    for(int j = 0; j < n; ++j)
    {
        int c;
        std::cin >> c;
        a[c] = j;
    }
 
    ll ans = 1;
    for(auto it = a.begin(); it != a.end(); ++it)
	{
	 	auto next = std::next(it,1);		
		if(next != a.end() && next->second < it->second)
			++ans;
	}
    std::cout << ans << std::endl;
    return 0;
}