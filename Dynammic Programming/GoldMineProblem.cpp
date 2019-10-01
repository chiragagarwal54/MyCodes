#include<bits/stdc++.h>
using namespace std;

const int a=100;
int GoldMine(int gold[][a], int m, int n)
{
    int arr[m][n];
    memset(arr, 0, sizeof(arr));

    for(int i=n-1; i>=0; i--)
    {
        for(int j=0; j<m; j++)
        {
            int right = (i==n-1)? 0:arr[j][i+1];

            int right_up = (i==n-1 || j==0)? 0:arr[j-1][i+1];

            int right_down = (i==n-1 || j==m-1)? 0:arr[j+1][i+1];

            arr[j][i]=max(right, max(right_up, right_down)) + gold[j][i];
        }
    }
    int q=0;
    for(int i=0; i<m; i++)
    {
        if(arr[i][0]>q)
            q=arr[i][0];
    }
    return q;
}

int main()
{
    int n,m;
    cin>>n>>m;
    int gold[n][a];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>gold[i][j];
        }
    }
    int ans=GoldMine(gold, n, m);
    cout<<ans<<endl;
    return 0;
}
