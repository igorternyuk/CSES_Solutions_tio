#include <bits/stdc++.h>

#define ll long long
#define ld long double
const int N = 2e5;

int main()
{
    int n, x;
    std::cin >> n >> x;
    
	std::map<int,int> mapa;
	bool solutionFound = false;
    for(int i = 0; i < n; ++i)
    {
		int a;	
        std::cin >> a;
				
		if(mapa.find(x-a) != mapa.end())
		{
            std::cout << mapa[x-a] + 1 << " " << i + 1 << std::endl;
			solutionFound = true;
			break;
		}
		mapa[a] = i;
    }

	if(!solutionFound)
		std::cout << "IMPOSSIBLE" << std::endl;    
    return 0;
}

