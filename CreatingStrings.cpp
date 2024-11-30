#include <bits/stdc++.h>

#define ll long long

int main()
{
    std::string s;
    std::cin >> s;
    std::sort(s.begin(), s.end());
    ll k = 0;
    std::vector<std::string> v;
    do
    {
        ++k;
        v.push_back(s);        
    } while(std::next_permutation(s.begin(), s.end()));
    
    std::cout << k << std::endl;
    for(auto p: v)
        std::cout << p << std::endl;
    return 0;
}

