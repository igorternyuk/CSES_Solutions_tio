#include <bits/stdc++.h>

#define ll long long
#define ld long double
const int N = 2e5;

int main()
{
    int n = 10;
    std::cin >> n;
    std::set<std::pair<int,int>> arrive_leave;
    
    for(int i = 0; i < n; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        arrive_leave.insert({a,+1});
		arrive_leave.insert({b,-1});
    }

	int ans = -N, c = 0;
	for(auto& al: arrive_leave)
	{
		c += al.second; 
		ans = std::max(c, ans);
	} 

    std::cout << ans << std::endl;
    
    return 0;
}

