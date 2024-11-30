#include <bits/stdc++.h>

#define ll long long
#define ld long double

int main()
{
    std::vector<int> ans;
    ll n;
    std::cin >> n;
    ll N = 1 << n; //2^n
    for(int i =0; i<N; i++)
        ans.push_back(i^(i>>1));
    
    for(auto i : ans)
    {
        std::bitset<16> s(i);
        std::string perm = s.to_string();
        std::cout << perm.substr(16-n,n) << std::endl;
    }        
      
    return 0;
}

