#include <bits/stdc++.h>
using namespace std;

// the number of elements in the input array is 2 <= N 
int main(){
    freopen("input_1.in","r",stdin);
    freopen("output_1.out","w",stdout);
    int n;
    cin >> n;
    vector<int> ve;
    int a;
    for(int i = 0; i < n; i++){
        cin >> a;
        ve.push_back(a);
    }
    // these two variables store the index of the greatest and the second greatest element 
    int firstGreater = 0;
    int secondGreater = -1;
    for(int i = 1; i < n; i++){
        if(ve[firstGreater] <= ve[i]) {
            secondGreater = firstGreater;
            firstGreater = i;
        }
        else if(secondGreater == -1 || ve[secondGreater] < ve[i]) secondGreater = i;

    }
    cout << ve[firstGreater] + ve[secondGreater];
    return 0;
}
