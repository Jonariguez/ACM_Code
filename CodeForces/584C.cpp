/****************
*PID:584C div1
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100000+10;
char s1[maxn],s2[maxn];
map<int,char> M;

void printDiff(char a,char b){
    for(int i=0;i<26;i++){
        if(a!=(i+'a') && b!=(i+'a')){
            printf("%c",i+'a');return ;
        }
    }
}

int main()
{
    int i,j,n,cnt,res,t;
    while(scanf("%d%d",&n,&t)!=EOF){
        scanf("%s%s",s1+1,s2+1);
        t=n-t;          //变成构造相同的
        cnt=0;
        for(i=1;i<=n;i++){
            if(s1[i]==s2[i]){
                cnt++;
            }
        }
        if(cnt>=t){         //如果已有的相同的个数大于要求的，那么就直接让这t个相同，其他的全部不同
            cnt=min(cnt,t);
            for(i=1;i<=n;i++){
                if(s1[i]==s2[i] && cnt){
                    printf("%c",s1[i]);cnt--;
                }else printDiff(s1[i],s2[i]);
            }
        }else {
            if((t-cnt)*2>n-cnt){            //相同的小于要求相同的，那么先让这cnt个相同，其他用2*(t-cnt)构造
                printf("-1\n");continue;      //出分别和s1，s2相同的，如果用来构造答案的字符不够用，则无解
            }
            int d=0,c=(t-cnt)*2;
            for(i=1;i<=n;i++){
                if(s1[i]==s2[i])
                    printf("%c",s1[i]);
                else if(c){
                    if(d) printf("%c",s1[i]);   //和s1相同与和s2相同交替出现，
                    else printf("%c",s2[i]);
                    d=!d;c--;
                }else
                    printDiff(s1[i],s2[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
