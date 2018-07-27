/****************
*PID:493b div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=200000+10;
vector<int> s,t;

int check(){
    int i;
    for(i=0;i<s.size() && i<t.size();i++){
        if(s[i]>t[i]) return 1;
        else if(s[i]<t[i]) return -1;
    }
    if(i==s.size() && i==t.size()) return 0;
    if(i==s.size()) return 1;
    return -1;
}

int main()
{
    LL i,j,n,sum;
    while(scanf("%I64d",&n)!=EOF){
        sum=0;
        s.clear();
        t.clear();
        int x;
        for(i=0;i<n;i++){
            scanf("%d",&x);
            sum+=x;
            if(x>0)
                s.push_back(x);
            else t.push_back(-x);
        }
        if(sum>0)
            printf("first\n");
        else if(sum<0)
            printf("second\n");
        else if(check()==1)
            printf("first\n");
        else if(check()==-1)
            printf("second\n");
        else if(x>0)
            printf("first\n");
        else printf("second\n");
    }
    return 0;
}
