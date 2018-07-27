/****************
*PID:631b div2
*Auth:Jonariguez
*****************
很明显对于r[i],对于i<j，有r[i]<r[j]，那么r[j]的
效果会覆盖r[i]的效果(即操作)，则此时r[i]是没有必要的，
所以先用stack维护一个r的递减序列，然后依次处理。
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=200000+10;
int a[maxn],r[maxn],t[maxn],ans[maxn];
stack<int> s;
vector<int> res;
deque<int> dq;

int cmp(int x,int y){
    return x>y;
}

int main()
{
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        for(i=1;i<=m;i++){
            scanf("%d%d",&t[i],&r[i]);
            while(!s.empty() && r[s.top()]<=r[i])
                s.pop();
            s.push(i);
        }
        res.clear();
        while(!s.empty()){
            int x=s.top();s.pop();
            res.push_back(x);
        }
        reverse(res.begin(),res.end());
        int cur=n;
        for(i=n;i>r[res[0]];i--)
            ans[cur--]=a[i];
        sort(a+1,a+r[res[0]]+1);
        for(i=1;i<=r[res[0]];i++)
            dq.push_back(a[i]);
        int rev=0,now=r[res[0]];  //down
        if(t[res[0]]==1)
            rev=1;
        for(i=1;i<res.size();i++){
            int cnt=now-r[res[i]];
            now=r[res[i]];
            while(cnt--){
                if(rev){
                    ans[cur--]=dq.back();dq.pop_back();
                }else {
                    ans[cur--]=dq.front();dq.pop_front();
                }
            }
            if(t[res[i]]==1)
                rev=1;
            else rev=0;
        }
        while((int)dq.size()){
            if(rev){
                ans[cur--]=dq.back();dq.pop_back();
            }else {
                ans[cur--]=dq.front();dq.pop_front();
            }
        }
        for(i=1;i<=n;i++)
            printf("%d ",ans[i]);
        puts("");
    }
    return 0;
}

