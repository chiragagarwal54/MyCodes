#include<bits/stdc++.h>
using namespace std;

//RecursiveSolution
int PairingRecursive(int n)
{
    if(n==1)
        return 1;
    else if(n==2)
        return 2;
    else
        return PairingRecursive(n-1) + (n-1)*PairingRecursive(n-2);
}

//Dynamic Programming based solution
int PairingDP(int n)
{
    int arr[n+1];
    for(int i=0; i<=n; i++)
    {
        if(i<=2)
            arr[i]=i;
        else
            arr[i]=arr[i-1]+(i-1)*arr[i-2];
    }
    return arr[n];
}

int main()
{
    int n;
    cin>>n;
    cout<<PairingDP(n);
    return 0;
}
