#include<bits/stdc++.h>
using namespace std;

int main()
{
     int n;
     cin>>n;
     //n indicated nth ugly number
     int arr[n];
     arr[0]=1;
     int i2=0,i3=0,i5=0;
     for(int i=1; i<n; i++)
     {
          if(arr[i2]*2<=arr[i3]*3 && arr[i2]*2<=arr[i5]*5)
          {
               arr[i]=arr[i2]*2;
               i2++;
          }
          else if(arr[i3]*3<=arr[i2]*2 && arr[i3]*3<=arr[i5]*5)
          {
               arr[i]=arr[i3]*3;
               i3++;
          }
          else
          {
               arr[i]=arr[i5]*5;
               i5++;
          }
     }
     cout<<arr[n-1]<<endl;
     return 0;
}
