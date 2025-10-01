// First attempt: Successfully debugged, might get more efficient but would still be O(n logn)
#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    unordered_map<int, int> mp;
    for(int i=0;i<n;++i){
        int temp;
        cin>>temp;
        if(mp.contains(temp)){
            mp[temp]=mp[temp]+1;
        }else{
            mp[temp]=1;
        }
    }
    vector<pair<int, int>> v;
    for(auto pr:mp){
        v.push_back({pr.first, pr.second});
    }
    sort(v.begin(), v.end(), [](const auto a, const auto b){return a.second>b.second;});
    int res=0;
    for(int i=0;i<v.size();++i){
        res=max(res, (i+1)*v[i].second);
    }
    cout<<res<<endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}

// Got an idea from seeing the implementation: The first in the pair(the specific element) does not matter, only the second(the frequency) matters.
// So we can just store the frequencies in a vector and sort it, then do the same logic
// Second attempt: More efficient, still O(n logn) but less constants
#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;++i){
        int temp;
        cin>>temp;
        v[temp-1]++;
    }
    sort(v.begin(), v.end(), [](const int a,const int b){return a>b;});
    int res=0;
    for(int i=0;i<n;++i){
        res=max(res,(i+1)*(v[i]));
    }
    cout<<res<<endl;
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}

// The alternative method in the editorial translated to cpp which is similar but uses the removal instead of keeping method.res=(Total-ans);(Two sides of the same coin).

#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;++i){
        int temp;
        cin>>temp;
        v[temp-1]++;
    }
    sort(v.begin(), v.end());
    int res=n;
    for(int i=0;i<n;++i){
        res=min(res,n-(n-i)*(v[i]));
    }
    cout<<n-res<<endl;
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}
