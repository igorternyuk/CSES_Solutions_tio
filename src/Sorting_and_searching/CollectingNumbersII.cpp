#include <bits/stdc++.h>

#define ll long long
#define ld long double
const int N = 2e5;

int a[N] = {0};

int main()
{
    int n = 5, m = 3;
    std::cin >> n >> m;
    std::vector<int> test;// = {4, 2, 1, 5, 3};
	test.reserve(n);
    //std::vector<std::pair<int,int>> perm {{2,3}, {1,5}, {2,3}};
    for(int j = 0; j < n; ++j)
    {
         int c;
         std::cin >> c;
         test.push_back(c);
    }

    for(int k = 0; k < m; ++k)
    {
        //int p1 = perm[j].first - 1;
        //int p2 = perm[j].second - 1;
        int p1, p2;
		std::cin >> p1 >> p2;
        int buf = test[p1-1];
        test[p1-1] = test[p2-1];
        test[p2-1] = buf;
        for(int j = 0; j < n; ++j)
        {
            int c = test[j];
           // std::cin >> c;
            a[c] = j;
        }

        ll ans = 1;
        for(int i = 1; i <= n; ++i)
        {
            if(i < n && a[i+1] < a[i])
                ++ans;
        }
        std::cout << ans << std::endl;
    }


    return 0;
}

