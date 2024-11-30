#include <iostream>
#include <vector>

using namespace std;

int josephus(int n, int k) {
    if (n == 1)
        return 1;
    else
        return (josephus(n - 1, k) + k - 1) % n + 1;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> order;
    for (int i = 1; i <= n; i++)
        order.push_back(i);

    int idx = 0;
    while (n > 0) {
        idx = (idx + k - 1) % n;
        cout << order[idx] << " ";
        order.erase(order.begin() + idx);
        n--;
    }

    return 0;
}
