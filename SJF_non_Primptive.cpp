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

    vector<int>a;
    for(int i = 0; i < pro;i++)
    {
        int x;
        cin >> x;
        a.pb(x);
    }
    cout << "Arrival time : " << nl;
    for(auto it : a)
    {
        cout << it << " ";
    }
    vector<int>bt;
    for(int i = 0; i < pro;i++)
    {
        int x;
        cin >> x;
        bt.pb(x);
    }
    cout << nl << "Brust time : " << nl;
    for(auto it : bt)
    {
        cout << it << " ";
    }
    vector<pair<int,int>>temp;
    for(int i = 0; i < pro;i++)
    {
        temp.pb(mp(a[i] , bt[i]));
    }
    sort(temp.begin() , temp.end());
    int cnt = 0;
    int val;
    for(auto it : temp)
    {
        val = it.second;
        cnt++;
        if(cnt == 1)break;
    }
    cout << nl;
    vector<int>gc(pro+1);
    gc[0]= 0;
    gc[1] = val;
    int sum = val;
    vector<int>temp1;
    temp1 = bt;
    sort(temp1.begin()+1, temp1.end());
    for(int i = 1;i < pro;i++)
    {
        sum += temp1[i];
        gc[i+1] = sum;
    }
    cout << "Grant chart : " << nl;
    for(int i = 0;i < gc.size();i++)
    {
        cout << gc[i] << " ";
    }
    cout << nl;
    int total_wt = 0;
    for(int i = 0;i < pro;i++)
    {
        total_wt += abs(gc[i] - a[i]);
    }
    
    double avg_wt = (double)total_wt/pro;
    cout << avg_wt << nl;



}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}