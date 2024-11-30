#include <bits/stdc++.h>

#define ll long long
#define ld long double

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> a;// = {1, 1, 1, 1, 1, 1, 1, 1, 2, 7};
    a.reserve(n);
                   
    for(int j = 0; j < n; ++j)
    {
        int c;
        std::cin >> c;
        a.push_back(c);
    }

    std::sort(a.begin(), a.end());
    ll ans = 0;
	ll sum = a[0];
    for(int k = 0; k < n - 1; ++k)
    {

        if(k==0 && sum > 1)
        {
            ans = 1;
            break;
        }
        //Can we make sum + 1
        if(sum + 1 < a[k+1])
        {
            ans = sum + 1;
            break;
        }
        else
        {
            sum += a[k+1];
            if(k == n-2)
                ans = sum + 1;
        }
    }

    std::cout << ans << std::endl;
    return 0;
}

