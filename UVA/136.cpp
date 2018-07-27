/****************
*PID:uva136
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long LL;

LL coe[3]={2,3,5};

map<LL,int> mp;
priority_queue<LL,vector<LL>,greater<LL> > pq;

int main()
{
    int i;
    pq.push(1LL);
    int cnt=1;
    while(true){
        LL now=pq.top();pq.pop();
        if(cnt==1500){
            printf("The 1500'th ugly number is %lld.\n",now);break;
        }
        for(i=0;i<3;i++){
            LL x=now*coe[i];
            if(mp[x]==0){
                pq.push(x);
            }
            mp[x]=1;
        }
        cnt++;
    }
    return 0;
}
