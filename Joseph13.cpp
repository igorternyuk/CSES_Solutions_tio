#include <bits/stdc++.h>

#define ll long long

int main()
{
    int n = 7, k = 2;
    std::cin >> n >> k; //3 6 2 7 5 1 4
    // 1 2 3 4 5 6 7 -> 7 1 2 4 5 -> 4 5 7 1 -> 1 4 5 -> 1 4

    //6 5 7 2 1 4 3

    //1 2 3 4 5 6 7 -> 7 1 2 3 4 5 -> 7 1 2 3 4 -> 1 2 3 4 -> 3 4 1
    std::deque<int> v;
    for(int i = 1; i <= n; ++i)
        v.push_back(i);
    while(!v.empty())
    {
        std::deque<int> s;
        int rem = 0;
        if(int(v.size()) > k)
        {
            for(int i = 1; i <= int(v.size()); ++i)
            {
                if(i > 0 && i % (k+1) == 0)
                {
                    std::cout << v[i-1] << " ";
                }
                else
                {
                    s.push_back(v[i-1]);
                }
            }
            rem = v.size() % (k+1);
            if(rem == 0)
                v = s;
            else
            {
                v.clear();
                for(int j = 0; j < rem && !s.empty(); ++j)
                {
                    v.push_front(s.back());
                    s.pop_back();
                }

                for(int i: s)
                    v.push_back(i);
            }
        }
        else // v.size() < = k => 1 2 3 4 -> 3 4 1
        {
            int index = k % v.size();
            std::cout << v[index] << " ";
            rem = v.size() - 1 - index;
            for(int i = index + 1; i < int(v.size()); ++i)
                 s.push_front(v[i]);
            for(int i = 0; i < index; ++i)
                s.push_back(v[i]);
            v = s;
        }


    }

    return 0;
}
