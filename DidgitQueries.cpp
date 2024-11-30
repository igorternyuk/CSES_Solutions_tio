#include <bits/stdc++.h>

#define ll long long
#define ld long double
int main()
{
    ll q = 1;
    std::cin >> q;
    while(q--)
    {
        ll pos = 1;
        std::cin >> pos;
        if(pos <= 9)
        {
            std::cout << pos << std::endl;
            continue;
        }
        ll low = 0;
        ll prev = low;
        ll prevD = prev;
        ll numDigits = 0;
        ll lowDigit = 0;
        while(low <= pos)
        {
            ++numDigits;
            ll a = 1;
            for(int j = 0; j < numDigits - 1; ++j)
                a *= 10;
            prev = low;
            low += 9 * numDigits * a;
            prevD = lowDigit;
            lowDigit += 9 * a;
        }

        ll div = (pos-prev) / numDigits;
        ll rem = (pos-prev) % numDigits;
        ll num = prevD + div + !!rem;
        

        ll tt = num;
        std::vector<int> digits;
        while(tt)
        {
            digits.push_back(tt % 10);
            tt /= 10;
        }
        std::reverse(digits.begin(), digits.end());
        ll idx = rem == 0 ? digits.size() - 1 : rem - 1;
        int res = digits[idx];
        std::cout << res << std::endl;
    }
    return 0;
}
