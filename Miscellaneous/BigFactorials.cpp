#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int z=0; z<t; z++)
    {
    int n;
    cin>>n;
    vector<int> fac;
    fac.push_back(1);
    int carry=0;
    for(int i=2; i<=n; i++)
    {
        int temp=0;
        for(int j=0; j<fac.size(); j++)
        {
            temp=fac[j]*i;
            temp=temp+carry;
            fac[j]=temp%10;
            carry=temp/10;
            //fac[j]=temp;
            //carry=0;
        }
        if(carry!=0)
        {
            if(carry<=9)
            {
                fac.push_back(carry);
                carry=0;
            }
            else
            {
                fac.push_back(carry%10);
                fac.push_back(carry/10);
                carry=0;
            }
        }
    }
    //fac.push_back(10);
    //cout<<"Factorial of "<<n<<" is = ";
    for(int i=fac.size()-1; i>=0; i--)
    {
        cout<<fac[i];
    }
    cout<<endl;
    }
    return 0;
}
