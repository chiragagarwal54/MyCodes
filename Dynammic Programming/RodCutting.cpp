#include<bits/stdc++.h>
using namespace std;

/*Given a rod of length n inches and an array of prices that
 contains prices of all pieces of size smaller than n.
 Determine the maximum value obtainable by cutting up the
  rod and selling the pieces.*/

int CutRod(int n, int price[])
{
    int arr[n+1];
    memset(arr, 0, sizeof(arr));

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(j<=i)
            {
                arr[i]=max(arr[i], price[j-1]+arr[i-j]);
            }
        }
    }
    return arr[n];
}


int main()
{
    int n;
    cin>>n;
    int price[n];
    for(int i=0; i<n; i++)
        cin>>price[i];

    int ans=CutRod(n, price);
    cout<<ans<<endl;
    return 0;
}
