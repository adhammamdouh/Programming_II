#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n;
vector<int>v;               //vector to store data in
int solve(int i){
    if(i>=n-1) return 0;   //base case i bigger than or equal size of array
    int choice1=solve(i+2)+v[i+2];      //jump over the adjacent column
    int choice2=solve(i+1)+v[i+1];      //move to the adjacent column
    return min(choice1,choice2);        //return the minimum between tow types of moves
}
int main()
{
    cin>>n;
    int y;
    for(int i=0;i<n;++i){
        cin>>y;
        v.push_back(y);
    }
    cout<<solve(0)<<endl;

}
