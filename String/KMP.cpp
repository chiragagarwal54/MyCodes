#include<bits/stdc++.h>
using namespace std;

vector<int> prefix(string s)
{
    int n=s.length();
    vector<int> pi(n);
    pi[0]=0;
    for(int i=1; i<n; i++)
    {
        int j=pi[i-1];
        while(j>0 && s[i]!=s[j])
            j=pi[j-1];
        if(s[i]==s[j])
            j++;
        pi[i]=j;
    }
    return pi;
}

int main()
{
    string text, pat;
    cout<<"Enter text "<<endl;
    cin>>text;
    cout<<"Enter pattern "<<endl;
    cin>>pat;

    int n=text.size();
    int m=pat.size();

    vector<int> pi = prefix(pat);
    int i=0; //index for text
    int j=0; //index for pat

    while(i<n)
    {
        if(pat[j]==text[i])
        {
            j++;
            i++;
        }
        if(j==m)
        {
            cout<<"Found pattern at index "<<i-j<<endl;
            j=pi[j-1];
        }

        else if(i<n && pat[j]!=text[i])
        {
            if(j!=0)
                j=pi[j-1];
            else
                i++;
        }
    }
    return 0;
}
