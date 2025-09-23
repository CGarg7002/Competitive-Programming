//The numbers greater than the k-1 th smallest element do not matter so first remove them and then just start flaging the ones that are equal to x
//And if you find a situation where either none are equal to x or you removed more than k-1 elements then return "NO" otherwise "YES".
//My Version:

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void Solution(vector<int>& v, int k){
    if(k==1){
        cout<<"YES"<<endl;
        return;
    }
    vector<int> bb=v;
    sort(bb.begin(), bb.end());
    int x=bb[k-2];
    vector<int> b;
    for(auto a:v){
        if(a<=x)
            b.push_back(a);
    }
    int l=0, r=b.size()-1, cnt=0;
    while(l<r){
        if(b[l]==b[r]){
            l++;
            r--;
        }else if(b[l]==x){
            cnt++;
            l++;
        }else if(b[r]==x){
            cnt++;
            r--;
        }else{
            cout<<"NO"<<endl;
            return;
        }
    }
    if((static_cast<int>(b.size())-cnt)>=(k-1)){
        cout<<"YES"<<endl;
        return;
    }else{
        cout<<"NO"<<endl;
        return;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t>0){
        int n, k;
        cin>>n>>k;
        vector<int> v;
        while(n>0){
            int num;
            cin>>num;
            v.push_back(num);
            n--;
        }
        Solution(v, k);
        t--;
    }
    return 0;
}


//A better version:
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void Solution(vector<int>& v, int k){
    if(k==1){
        cout<<"YES"<<endl;
        return;
    }
    vector<int> bb=v;
    sort(bb.begin(), bb.end());
    int x=bb[k-2];
    vector<int> b;
    for(auto a:v){
        if(a<=x)
            b.push_back(a);
    }
    int spare = (int)b.size() - (k - 1);
    if (spare < 0) { cout << "NO\n"; return; }

    int l = 0, r = (int)b.size() - 1;
    while (l < r) {
        if (b[l] == b[r]) { l++; r--; continue; }
        if (b[l] == x && spare > 0) { l++; spare--; continue; }
        if (b[r] == x && spare > 0) { r--; spare--; continue; }
        cout << "NO\n"; 
        return;
    }
    cout << "YES\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t>0){
        int n, k;
        cin>>n>>k;
        vector<int> v;
        while(n>0){
            int num;
            cin>>num;
            v.push_back(num);
            n--;
        }
        Solution(v, k);
        t--;
    }
    return 0;
}


//Editorial version:
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define all(x) x.begin(), x.end()
#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;
#define vecout(v) for (auto _ : v) cout << _ << " "; cout << endl;
 
 
void solve() {
    int n; cin >> n;
    int k; cin >> k;
    vecin(aa, n);
    if (k == 1) {
        cout << "YES" << endl;
        return;
    }
 
    vector<int> bb = aa;
    sort(all(bb));
    int cutoff = bb[k - 2];
    vector<int> cc;
    for (auto a : aa)
        if (a <= cutoff)
            cc.push_back(a);
    int spare = cc.size() - k + 1;
    int L = 0, R = cc.size() - 1;
    bool bad = false;
    while (L < R) {
        if (cc[L] != cc[R]) {
            if (spare == 0) {
                bad = true; break;
            }
            if (cc[L] == cutoff) {
                L ++;
                spare --;
            } else if (cc[R] == cutoff) {
                R --;
                spare --;
            } else {
                bad = true; break;
            }
            continue;
        }
        L ++;
        R --;
    }
    if (bad) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}
 
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;
 
    cin >> tt;
 
    while (tt--) solve();
    return 0;
}
