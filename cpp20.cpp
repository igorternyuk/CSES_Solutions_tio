#include <iostream>
#include <ranges>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>

int main()
{
    std::vector vect { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto result { vect
    | std::views::filter([](const auto& val){ return val % 2 == 0; })
    | std::views::transform([](const auto& val){ return 20 * val; })
    | std::views::drop(2)
    | std::views::reverse
    | std::views::transform([](const auto& i){ return std::to_string(i); })
    };

    for(const auto& v: result)
        std::cout << v << "\t";
    return 0;
}