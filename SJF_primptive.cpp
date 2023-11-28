#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

#define nl '\n' 
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define mod 1000000007
#define pi 3.1415926535897932384626433832795
#define lpz(i, a, b) for (int i=a; i<b; i++)
#define lp(i, a, b) for (int i=a; i<=b; i++)
#define test() int t; cin>>t; while(t--)
#define ull unsigned long long



void solve()
{
    int pro;
    cin >> pro;
    int n;
    cin >> n;
    vector<int>bt;
    for(int i = 0; i < n;i++)
    {
        int x;
        cin >> x;
        bt.pb(x);
    }
    sort(bt.begin() , bt.end());

    cout << "Brust time : " << nl;
    for(auto i : bt)
    {
        cout << i << "\t";
    }
    cout << nl;

    vector<int>wt(n);
    
    int sum = 0;
    wt[0] = 0;
    //prefix sum
    for(int i = 0;i < n -1 ;i++)
    {
        sum += bt[i];
        wt[i+1] = sum;
    }
    cout << "Waiting time : " << nl;
    for(auto it : wt)
    {
        cout << it << "\t";
    }
    cout << nl;
    vector<int>tnt;
    // tnt = bt + wt
    for(int i = 0; i < n;i++)
    {
        tnt.pb(bt[i] + wt[i]);
    }
    cout << "Turn around time : " << nl;
    for(auto it : tnt)
    {
        cout << it << "\t";
    }
    cout << nl;
    int total_wt = accumulate(wt.begin() , wt.end() , 0);
    int total_tnt = accumulate(tnt.begin() , tnt.end() , 0);

    double res_wt = (double)total_wt/n;
    double res_tnt = (double)total_tnt/n;
    cout << "avg waiting time : " << fixed << setprecision(4) << res_wt << nl;
    cout << "avg Turn araound time :  " << fixed << setprecision(4) <<  res_tnt << nl;


}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

   solve();

    return 0;
}