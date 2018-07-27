/****************
*PID:534d div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=200000+10;
vector<int> res;
stack<int> s[maxn];

int main()
{
    int i,j,n;
    scanf("%d",&n);
    int x;
    for(i=1;i<=n;i++){
        scanf("%d",&x);
        s[x].push(i);
    }
    bool yes=true;
    int cnt=1,cur=0;
    while(1){
        if(!s[cur].empty()){
            res.push_back(s[cur].top());s[cur].pop();cur++;
        }else {
            cur-=3;
            if(cur<0)
                break;
        }
    }
    if(res.size()<n)
        printf("Impossible\n");
    else {
        printf("Possible\n");
        for(i=0;i<n;i++)
            printf("%d ",res[i]);
    }
    return 0;
}

