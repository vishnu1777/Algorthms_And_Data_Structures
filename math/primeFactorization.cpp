#include <stdio.h>
#include <iostream>
using namespace std;

void primeFactorsSeiveCount(int n)
{
    int SmallestPrimeFactor[100]; // intialize size 100 array with zero values in it
    for (int i = 2; i <= n; i++)
    {
        SmallestPrimeFactor[i] = i; // smallest prime factor for all i's is first i itself
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (SmallestPrimeFactor[i] == i) // if it is not altered that means it is first entry
        {
            for (int j = i * i; j <= n; j += i)
            {

                if (SmallestPrimeFactor[j] == j)
                {
                    // cout << "for j " << j << " the smallest prime factor is:" << i << endl;
                    SmallestPrimeFactor[j] = i;
                }
            }
            cout << endl;
        }
    }

    while (n != 1)
    {
        cout << "prime factors are:" << SmallestPrimeFactor[n] << endl;
        n /= SmallestPrimeFactor[n];
    }
}
void seive(int n)
{
    if (n == 0)
        return;
    bool prime[n];
    for (int i = 2; i < n; i++)
    {
        prime[i] = true;
    }
    for (int i = 2; i * i < n; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j < n; j += i)
            {

                prime[j] = false;
            }
        }
    }
    int count = 0;
    for (int i = 2; i < n; i++)
    {
        if (prime[i])
        {
            cout << i << endl;
            count++;
        }
    }
    cout << "the count of the primes in between " << n << " is " << count << endl;
}

void primeFactorBruteForce(int n)
{
    for (int i = 2; i <= n; i++)
    {
        while (n % i == 0)
        {
            cout << i << " ";
            n /= 2;
        }
    }
}
void primeFactorBetter(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        while (n % 2 == 0)
        {
            cout << i << " ";
            n /= 2;
        }
    }
    if (n > 1)
        cout << n;
}
int main()
{
    int n;
    cout << "enter the number:" << endl;
    cin >> n;
    primeFactorsSeiveCount(n);
    cout << endl;
    seive(n);
    cout << endl;
    primeFactorBruteForce(n);
    cout << endl;
    primeFactorBetter(n);

    return 0;
}