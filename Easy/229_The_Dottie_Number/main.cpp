#include <iostream>
#include <cmath>

double bisect(double (*func)(double), double a, double b, double epsilon)
{
    double mid = 0.5 * (a + b);
    while (b - a > epsilon)
    {
        if ((func(a) > 0) == (func(mid) > 0)) {
            a = mid;
        }
        else {
            b = mid;
        }
        mid = 0.5 * (b + a);
    }
    return mid;
}

int main()
{
    auto dottie = [](double x) { return std::cos(x) - x; };
    std::cout << "Dottie number: " << bisect(dottie, 0, 1, 1e-9) << std::endl;

    auto pi = [](double x) { return std::tan(x); };
    std::cout << "Pi: " << bisect(pi, 2, 4, 1e-9) << std::endl;

    auto golden_ratio = [](double x) { return 1 + 1/x - x; };
    std::cout << "Golden ratio: (1 + sqrt(5)) / 2 = " << bisect(golden_ratio, 1.5, 2.5, 1e-9) << std::endl;

    auto logmap = [](double x) { return 4 * x * (1 - x) - x; };
    std::cout << "logistic map (0): " << bisect(logmap, -0.5, 0.5, 1e-9) << std::endl;
    std::cout << "logistic map (3/4): " << bisect(logmap, 0.5, 1.0, 1e-9) << std::endl;

    return 0;
}
