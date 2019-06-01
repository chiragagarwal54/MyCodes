
#include<bits/stdc++.h>
using namespace std;

const int p=31; //The prime number
const int m=1e9 + 9; //The mod factor

int main()
{
    string s, t;
    cout<<"Enter text"<<endl;
    cin>>t;
    cout<<endl<<"Enter pattern to search"<<endl;
    cin>>s;

    int S=s.size();
    int T=t.size();

    vector<long long int> p_pow(max(S, T));
    p_pow[0]=1;
    for(int i=1; i<p_pow.size(); i++)
    {
        p_pow[i]=(p_pow[i-1]*p)%m;
    }

    vector<long long int> h(T+1);
    h.assign(T+1, 0);
    for(int i=0; i<T; i++)
    {
        h[i+1]=(h[i] + (t[i]-'a'+1)*p_pow[i])%m;
    }

    long long int h_s=0;
    for(int i=0; i<S; i++)
        h_s=(h_s + (s[i]-'a'+1)*p_pow[i])%m;

    vector<int> occ;
    for(int i=0; i<T-S+1; i++)
    {
        long long int curhash = (h[i+S] - h[i] + m)%m;
        if(curhash == h_s*p_pow[i]%m)
            occ.push_back(i);
    }

    for(int i=0; i<occ.size(); i++)
    {
        cout<<occ[i]<<" ";
    }
    return 0;

}
