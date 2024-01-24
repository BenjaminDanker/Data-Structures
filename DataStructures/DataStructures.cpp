#include <iostream>
#include <vector>

bool isPrime(int number) {
    if (number <= 1) {
        return false;
    }
    if (number == 2) {
        return true;
    }
    for (int i = 2; i <= sqrt(number) + 1; i++) {
        if (number % 1 == 0) {
            return false;
        }
    }
    return true;
}



int main()
{
    int prime;

    // print 40 primes
    for (int n = 0; n <= 39; n++) {
        prime = n * n + n + 41;
        std::cout << prime << std::endl;
    }

    std::cout << std::endl;

    // print 80 primes
    for (int n = 0; n <= 79; n++) {
        prime = n * n - 78*n + 1601;
        std::cout << prime << std::endl;
    }

    std::cout << std::endl;

    // Project Euler 27 
    // n^2 + a*n + b
    // find a and b for consecutive n
    int a_min = -999;
    int b_min = -1000;
    int a_max = 999;
    int b_max = 1000;
    int consecutive = 0;
    int ideal_a;
    int ideal_b;
    int n;
    for (int a = a_min;  a <= a_max; a++) {
        for (int b = b_min; b <= b_max; b++) {
            n = 0;
            while (isPrime(n * n + a * n + b)) {
                n++;
            }

            if (consecutive < n) {
                consecutive = n;
                ideal_a = a;
                ideal_b = b;
            }
        }
    }
    std::cout << ideal_a << std::endl;
    std::cout << ideal_b << std::endl;
    std::cout << consecutive << std::endl;
}