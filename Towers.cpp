#include <bits/stdc++.h>
#define ll long long

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> towers;
	towers.reserve(n);
    for(int i = 0; i < n; ++i)
    {
		int ci;
        std::cin >> ci;
		auto it = std::upper_bound(towers.begin(), towers.end(), ci);
		if(it != towers.end())
			*it = ci;
		else
			towers.push_back(ci);
    }

	
    std::cout << towers.size() << std::endl;
    return 0;
}
