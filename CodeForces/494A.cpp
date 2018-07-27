/****************
*PID:494a div1
*Auth:Jonariguez
*****************
贪心，前面的都补一个），最后一个补全（补全即使两者个数相等）
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100000+10;

char s[maxn];

int main()
{
    int i,j,left,right,n,sum,cnt;
    while(scanf("%s",s+1)!=EOF){
        n=strlen(s+1);
        left=0;right=cnt=0;
        int yes=1;
        for(i=1;i<=n;i++){
            if(s[i]=='(')
                left++;
            else if(s[i]==')')
                right++;
            else cnt++;
            if(right>left){
                yes=0;break;
            }
        }
        if(yes==0 || right+cnt>left){
            printf("-1\n");continue;
        }
        vector<int> res;
        int d=left-right,t=cnt;
        left=right=0;yes=1;
        for(i=1;i<=n;i++){
            if(s[i]=='(') left++;
            else if(s[i]==')') right++;
            else {
                if(cnt!=1){
                    res.push_back(1);right++;d--;
                }else if(cnt==1){
                    res.push_back(d);right+=d;d=0;
                }
                cnt--;
            }
            if(right>left){
                yes=0;break;
            }
        }
        if(yes==0)
            printf("-1\n");
        else
            for(i=0;i<res.size();i++)
                printf("%d\n",res[i]);
    }
    return 0;
}
