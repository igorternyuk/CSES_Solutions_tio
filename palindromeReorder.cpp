#include <bits/stdc++.h>
#define ll long long

int main()
{
    std::string s;
    std::cin >> s;
    
    std::map<char,int> freq;
    
    for(size_t i{0}; i < s.size(); ++i)
        ++freq[s[i]];
    
    size_t numOddFreq = 0;
    char odd;
    size_t oddFreq;
    for(auto it = freq.begin(); it != freq.end(); ++it)
    {
        if((it->second)&1)
        {
            ++numOddFreq;
            odd = it->first;
            oddFreq = it->second;
        }
    }

    if(numOddFreq > 1)
    {
        std::cout << "NO SOLUTION" << std::endl;
        return 0;
    }
    
    std::string ansL;
    for(auto it = freq.begin(); it != freq.end(); ++it)
    {
        auto f = it->second;
        if(f%2==0)
            for(int i {0}; i < f / 2; ++i)
                ansL += it->first;       
    }
    
    std::string ansR = ansL;
    std::reverse(ansR.begin(), ansR.end());
    if(numOddFreq)
        for(size_t i {0}; i < oddFreq; ++i)
            ansL += odd;
    ansL += ansR;
    std::cout << ansL;
    
    
    return 0;
}

