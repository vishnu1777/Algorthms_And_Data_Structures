#include<stdio.h>
#include<iostream>
using namespace std;


void func(int n)
{
    if(n == 10)return;
    // try printing this
    func(n+1);
    cout<<n<<endl;
}

void func2(int n)
{
    if(n == 10)return;
    // try printing this
    cout<<n<<endl;
    func2(n+1);
}


int main()
{
    func(1);
    func2(1);
    return 0;

}
