/****************
*PID:uva11491
*Auth:Jonariguez
*****************
贪心策略：
从左往右找第一个递增区间，然后删掉该区间首个数字，
然后找不到这样的区间，就是整个区间都是不增的，那么就
删最后一个数字。
如果像这样模拟的话，肯定超时。
我们可以从左向右一个一个看，从第一个数开始，看第二个数，
如果第一个<第二个，那么第一个肯定要删的，那么就拿第二个当
第一个和后面的比；
如果第一个>第二个，说明现在都还不能删，要看第三个。
相等时和>一样。
这不就是栈吗~
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100000+10;
char str[maxn];
int a[maxn],b[maxn],tot;
stack<int> s;

void print(){
    if(s.empty()) return ;
    int x=s.top();s.pop();
    print();
    b[++tot]=x;
}

int main()
{
    int i,j,n,d;
    while(scanf("%d%d",&n,&d)){
        if(n==0 && d==0) break;
        scanf("%s",str+1);
        for(i=1;i<=n;i++)
            a[i]=str[i]-'0';
        for(i=1;i<=n && d;i++){
            if(s.empty())
                s.push(a[i]);
            else {
                while(!s.empty() && d){
                    int x=s.top();
                    if(x<a[i]){
                        s.pop();d--;
                    }else
                        break;
                }
                s.push(a[i]);
            }
        }
        tot=0;
        print();
        for(;i<=n;i++)
            b[++tot]=a[i];
        for(i=1;i<=tot-d;i++)       //如果通过上面的方式没删够d个，说明目前整个序列已经是全部不增的了，
            printf("%d",b[i]);      //那就抛弃最后d位
        printf("\n");
    }
    return 0;
}

