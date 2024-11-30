#include <bits/stdc++.h>

#define ll long long
#define ld long double

int main()
{
    int t;
    std::cin >> t;
    while(t--)
    {
        int a, b;
        std::cin >> a >> b;
        auto res = ((a+b)%3==0 && ((b > a && b-a <= a) || (a > b && a-b>= b))/*(2*a>=b && 2*b>=a)*/) ? "YES" : "NO";
        std::cout << res << std::endl;
    }
    return 0;
}

/*b > a && b-a>= a/2 || a > b && a-b>= b/2
a=6         ***     *       *       * 
b=9         ***    **     **     **

a=6         *  *     *      *        *          * 
b=12        **   **   **     **    **     **

y <= 2 * x
2 * y >= x
y >= 0.5 * x*/
