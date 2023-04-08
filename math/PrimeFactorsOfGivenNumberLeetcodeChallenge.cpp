#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int getPrimes(int n, vector<bool> &primes)
{
    int number = 0;
    if (n <= 0)
        return 0;

    while (n % 2 == 0)
    {
        primes[2] = true;
        number += 2;
        n /= 2;
    }

    for (int i = 3; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            number += i;
            primes[i] = true;
            n /= i;
        }
    }
    if (n > 2)
    {
        number += n;
        primes[n] = true;
    }
    return number;
}

int getSmallestPrimeFactor(int n)
{
    vector<bool> primes(n);
    if (n == 4)
        return 4;
    while (!primes[n])
    {
        n = getPrimes(n, primes);
    }

    return n;
}

int main()
{
    int n;
    cout << "Enter the number" << endl;
    cin >> n;
    cout << "The smallest prime factor is:" << getSmallestPrimeFactor(n) << endl;

    return 0;
}