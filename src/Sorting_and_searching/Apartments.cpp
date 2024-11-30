#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

#define ll long long
#define ld long double

const ll N = 2e5;

int main()
{
    int n, m, k;
    std::cin >> n >> m >> k;
    int tt = n;
    std::vector<int> va; // desires
    std::vector<int> vb; // apartments
    va.reserve(N);
    vb.reserve(N);
    while(tt--)
    {
        int ai;
        std::cin >> ai;
        va.push_back(ai);        
    }
    tt = m;
    while(tt--)
    {
        int bi;
        std::cin >> bi;
        vb.push_back(bi);        
    }
    
    std::sort(va.begin(), va.end());
    std::sort(vb.begin(), vb.end());
    int ans = 0;
    for(int i = 0, j = 0; i < n; ++i)
    {
        while(j < m && vb[j] < va[i] - k)
            ++j;
        if(j < m && vb[j] <= va[i] + k)
            ++ans, ++j;
    }
    std::cout << ans << std::endl;
    return 0;
}

