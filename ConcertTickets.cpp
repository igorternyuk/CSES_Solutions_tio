#include <bits/stdc++.h>

#define ll long long
#define ld long double
const int N = 2e5;

int main()
{
    int n = 10, m = 10;
    std::cin >> n >> m;
    std::set<std::pair<int,int>> a;// = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};  // 8, 7, 5, 5, 3
    
    for(int i = 0; i < n; ++i)
    {
        int ai;
        std::cin >> ai;
        a.insert({ai,i});
    }

    //std::vector<int> b;// = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};  // 8, 4, 3
    //b.reserve(m);
    for(int i = 0; i < m; ++i)
    {
        int bi;
		//bi = b[i];
        std::cin >> bi;
		auto it = a.lower_bound({bi+1,0});
		if(it != a.begin())
		{
			--it;
            std::cout << it->first << std::endl;
			a.erase(it);
		}			
		else
			std::cout << "-1" << std::endl;
	}

    
    return 0;
}

