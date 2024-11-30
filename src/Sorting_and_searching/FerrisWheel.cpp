#include <bits/stdc++.h>

#define ll long long
#define ld long double
const int N = 2e5;

int main()
{
    int n = 10, x = 15;
    std::cin >> n >> x;
    std::vector<int> a; // {9, 8, 8, 9, 10, 8, 5, 8, 7, 10};
	a.reserve(N);
	for(int i = 0; i < n; ++i)
	{
		int ai;
		std::cin >> ai;
		a.push_back(ai);
	}

	std::sort(a.begin(), a.end());
	int ans = 0;
                  
	for(int i = 0, j = n - 1; i < n; ++i, --j)
	{
		while(i < j && a[i] + a[j] > x) --j;
		if(i >= j)
			break;
		else
			++ans;	
	}
	
	std::cout << n - ans << std::endl;			    
    return 0;
}

