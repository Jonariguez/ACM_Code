/****************
*PID:451d div2
*Auth:Jonariguez
*****************
从前往后扫一遍，对于当前str[i],分别在前面位置
中找奇数位或者偶数位上的str[i]有几个，分别累加到
答案even，odd中，分类讨论一下。
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=100000+10;
map<char,LL> mp1,mp2;
char str[maxn];

int main()
{
    LL i,j,n,odd,even;
    while(scanf("%s",str+1)!=EOF){
        n=strlen(str+1);
        mp1.clear();mp2.clear();
        odd=even=0;
        for(i=1;i<=n;i++){
            if(i&1){
                mp1[str[i]]++;
                odd+=mp1[str[i]];
                even+=mp2[str[i]];
            }else {
                mp2[str[i]]++;
                odd+=mp2[str[i]];
                even+=mp1[str[i]];
            }
        }
        printf("%I64d %I64d\n",even,odd);
    }
    return 0;
}
