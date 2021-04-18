#include <iostream>
#include <iomanip>
int main()
{
    float a, b;
    std::cin >> a >> b;
    if (b > 0)
    {
        std::cout << a << "/" << b << "=" << std::setiosflags(std::ios::fixed) << std::setprecision(2) << a / b;
    }
    else if (b < 0)
    {
        std::cout << a << "/(" << b << ")=" << std::setiosflags(std::ios::fixed) << std::setprecision(2) << a / b;
    }
    else
    {
        std::cout << a << "/" << b << "=Error";
    }

    return 0;
}