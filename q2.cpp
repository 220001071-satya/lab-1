#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& weights, vector<int>& value, int n, int maxWeight){
    if(n == 0 || maxWeight == 0) return 0;
    if(weights[n-1]>maxWeight) return solve(weights, value, n - 1, maxWeight);
    return max(value[n-1] + solve(weights, value, n - 1, maxWeight - weights[n-1]), solve(weights, value, n - 1, maxWeight));
}
// solve is the direct recursive solution we can easily memoize it 
int solve1(vector<int>& weights, vector<int>& value, int n, int maxWeight, map<pair<int,int>,int>& mp){
    if(n == 0 || maxWeight == 0) return 0;
    if(mp.find({n, maxWeight})!=mp.end()) return mp[{n,maxWeight}];
    if(weights[n-1]>maxWeight) mp[{n,maxWeight}] = solve1(weights, value, n - 1, maxWeight,mp);
    else mp[{n,maxWeight}] = max(value[n-1] + solve1(weights, value, n - 1, maxWeight - weights[n-1],mp), solve1(weights, value, n - 1, maxWeight,mp));
    return mp[{n,maxWeight}];
}
int main(){
    freopen("input_2.in","r",stdin);
    freopen("output_2.out","w",stdout);
    int n;
    cin >> n;
    
    vector<int> weights, value;
    int a;
    for(int i = 0; i < n; i++){
        cin >> a;
        weights.push_back(a);
    }
    for(int i = 0; i < n; i++){
        cin >> a;
        value.push_back(a);
    }
    int maxWeight;
    cin >> maxWeight;
    map<pair<int,int>,int> mp;
    int ans = solve1(weights, value,n , maxWeight, mp);
    cout<<ans;
}