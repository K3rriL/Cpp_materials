#include <iostream>
#include <vector>
#include <algorithm>

void procedure(int x)
{
    std::cout << x << " ";
}

int main()
{
    std::vector <int> A = {1, 2, 3, 4, 5};
    std::vector <int>::iterator it1 = A.begin();
    
    // 1st variant
    while (it1 != A.end())
    {
        std::cout << *it1 << " "; 
        ++it1; // or it++
    }
    std::cout << "\n";
    
    // 2nd variant
    for (std::vector <int>::iterator it2 = A.begin(); it2 != A.end(); ++it2)
    {
        std::cout << *it2 << " ";
    }
    std::cout << "\n";

    // 3rd variant
    for (auto it3 = A.begin(); it3 != A.end(); ++it3)
    {
        std::cout << *it3 << " ";
    }
    std::cout << "\n";
    
    // 4th variant
    for (auto it4 : A)
    {
        std::cout << it4 << " ";
    }
    std::cout << "\n";
    
    // 5th variant
    for_each(A.begin(), A.end(), procedure);

    return 0;
}