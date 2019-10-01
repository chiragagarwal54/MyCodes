#include<bits/stdc++.h>
using namespace std;

int LPS()
{
    string s;
    cin>>s;
    int n=s.length();
    int arr[n][n];

    for(int l=1; l<=n; l++)
    {
        for(int i=0; i<n-l+1; i++)
        {
            if(l==1)
                arr[i][i]=1;
            else
            {
                int j=i+l-1;
                if(s[i]==s[j] && l==2)
                {
                    arr[i][j]=2;
                }
                else if(s[i]==s[j])
                {
                    arr[i][j]=2+arr[i+1][j-1];
                }
                else
                {
                    arr[i][j]=max(arr[i][j-1], arr[i+1][j]);
                }
            }
        }
    }
    return arr[0][n-1];
}

int main()
{
    int ans=LPS();
    cout<<ans<<endl;
    return 0;
}
