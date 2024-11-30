
#include <bits/stdc++.h>
#include <cassert>
#include <random>

#define ll long long
#define ld long double
#define loop(N) for(ll i{0}; i < N; ++i)

ll john(ll y, ll x)
{
    ll res;
    ll zmax = std::max(x,y);
    ll zmin = std::min(x,y);
    ll z2 = zmax*zmax;
    if(zmax%2==0)
    {
        if(zmax == x)
        {
            /*
            1  2  9  10| 25
            4  3  8  11| 24
            ------------
            5  6  7  12  23
            16 15 14 13  22
            17 18 19 20  21
            */
            res = z2-(x-1)-(zmax-zmin);
        }
        else
        {
            /*
            1  2 |  9  10  25
            4  3 |  8  11  24
            5  6 |  7  12  23
            16 15|  14 13  22
            -----
            17 18 19 20  21
            */
            res = z2-(x-1);
        }
    }
    else
    {
        if(zmax == x)
        {
            /*
            1  2  9| 10 25
            4  3  8| 11 24
            --------
            5  6  7  12  23
            16 15 14 13  22
            17 18 19 20  21
            */
            res = z2-(y-1);
        }
        else
        {
            /*
            1  2 | 9  10  25
            4  3 | 8  11  24
            5  6 | 7  12  23
            -----
            16 15 14 13  22
            17 18  19  20  21
            */
            res = z2-(y-1)-(zmax-zmin);
        }
    }
    return res;
}

int main()
{
    ll N;
    std::cin >> N;
    std::stringstream ss;
    for(ll i = 0; i < N; ++i)
    {
        ll x, y;
        std::cin >> y >> x;
        ll res = john(y,x);
        std::cout << res << std::endl;
    }

    /*ll res1 = john(2,3);
    ll res2 = john(2,4);
    ll res3 = john(3,4);
    ll res4 = john(5,2);
    ll res5 = john(3,2);*/
    return 0;
}

