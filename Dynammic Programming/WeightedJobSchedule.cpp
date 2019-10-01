//Weighted job scheduling
#include<bits/stdc++.h>
using namespace std;

bool compare(const pair<pair<int, int> , int>&i, const pair<pair<int, int> , int>&j)
{
     return i.second < j.second;
}

int main()
{
     int n; //No. of jobs
     cin>>n;
     vector<pair<pair<int, int> , int> > jobs; //An array of pairs for start and finish time
     for(int i=0; i<n; i++)
     {
          int st,ft,value;
          cin>>st>>ft>>value;
          jobs.push_back(make_pair(make_pair(st, value) ,ft)); //Input start and finish time
     }

     sort(jobs.begin(), jobs.end(), compare);

     //Test to see the sorted jobs
     /*
     for(int i=0; i<n; i++)
     {
          cout<<jobs[i].first.first<<" "<<jobs[i].first.second<<" "<<jobs[i].second<<endl;
     }
     */

     int dp[n];
     for(int i=0; i<n; i++)
          dp[i]=jobs[i].first.second;

     for(int i=1; i<n; i++)
     {
          for(int j=0; j<i; j++)
          {
               if(jobs[j].second<=jobs[i].first.first)
               {
                    dp[i]=max(dp[i], dp[j]+jobs[i].first.second);
               }
          }
     }

     int ans=0;
     for(int i=0; i<n; i++)
          if(dp[i]>ans)
               ans=dp[i];

     cout<<ans<<endl;

     return 0;
}
