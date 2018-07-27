/****************
*PID:634a div1
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=200000+4;
vector<int> a,aa,b,bb;

bool check(vector<int>& x,vector<int>& y){
    int i;
    for(i=0;i<x.size();i++)
        if(x[i]!=y[i]) return false;
    return true;
}

int main()
{
    int i,j,n,x;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&x);
        if(x==0) continue;
        a.push_back(x);
    }
    for(i=0;i<n;i++){
        scanf("%d",&x);
        if(x==0) continue;
        b.push_back(x);
    }
    for(i=0;i<b.size();i++)
        if(b[i]==a[0]) break;
    int cnt=0;
    j=i;i=0;
    while(cnt<n-1){
        if(b[j]!=a[i]) break;
        j++;i++;
        cnt++;
        i%=(n-1);j%=(n-1);
    }
    if(cnt>=n-1){
        puts("YES");
    }else
        puts("NO");
    return 0;
}
