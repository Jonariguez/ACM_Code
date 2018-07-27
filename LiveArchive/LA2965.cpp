/****************
*PID:la2965
*Auth:Jonariguez
*****************
将每个字符串中A-Z的26个字母出现的次数的奇偶性，把
这个字符压缩成一个26为的整数，然后就是求选取最多的数
异或值等于0.
n=24太大。中途相遇法。
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=26;
int a[maxn];
char str[1000];
//table[x]表示前n1个数^是否有x，cnt[x]:异或值为x的，选的最多个数的数。ans[x]：二进制编码选择哪几个数。
map<int,int> table,cnt,ans;

int main()
{
    int i,j,n,res;
    while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++){
            scanf("%s",str+1);
            a[i]=0;
            for(j=1;str[j]!='\0';j++)
                a[i]^=(1<<(str[j]-'A'));
        }
        table.clear();cnt.clear();ans.clear();
        int n1=n/2,mask;
        for(mask=0;mask<(1<<n1);mask++){
            int x=0,c=0;
            for(j=0;j<n1;j++)
                if((mask>>j)&1){
                    x^=a[j];c++;
                }
            if(!table.count(x)){
                table[x]=1;cnt[x]=c;ans[x]=mask;
            }else {
                if(c>cnt[x]){
                    table[x]=1;cnt[x]=c;ans[x]=mask;
                }
            }
        }
        int n2=n-n1,res=0,now=0;
        for(mask=0;mask<(1<<n2);mask++){
            int x=0,c=0;
            for(j=0;j<n2;j++){
                if((mask>>j)&1){
                    x^=a[j+n1];c++;
                }
            }
            if(table[x]){
                if(now<cnt[x]+c){
                    now=cnt[x]+c;res=((mask<<n1)|ans[x]);
                }
            }else {
                if(x==0 && now<c){
                    now=c;res=mask;
                }
            }
        }
        printf("%d\n",now);
        for(i=0;i<n;i++){
            if((res>>i)&1) printf("%d ",i+1);
        }
        puts("");
    }
    return 0;
}
