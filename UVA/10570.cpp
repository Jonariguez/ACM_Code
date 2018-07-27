/****************
*PID:
*Auth:Jonariguez
*****************
破环为链，然后得正反两个序列，分别贪心求最少，res更新最少即答案。
破环要枚举每个“破”的位置。
贪心就是直接把1放在位置1，把2放在位置2。。
这证明这样更优，因为这是最直接的。
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=500+10;
int n,a[maxn];
int s1[maxn],s2[maxn];

int solve(int *s){
    int i,j,t,res=0;
    for(i=0;i<n;i++){
        if(s[i]==i+1)
            continue;
        for(j=i;j<n;j++)
            if(s[j]==i+1) break;
        t=s[i];s[i]=s[j];s[j]=t;
        res++;
    }
    return res;
}

int main()
{
    int i,j,p;
    while(scanf("%d",&n),n){
        int p;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        int res=1000;
        for(p=0;p<n;p++){
            int cnt=0;
            for(i=p,j=p;cnt<n;i++,j--,cnt++){
                s1[cnt]=a[i%n];
                s2[cnt]=a[(j%n+n)%n];
            }
            res=min(res,min(solve(s1),solve(s2)));
        }
        printf("%d\n",res);
    }
    return 0;
}
