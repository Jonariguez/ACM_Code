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
        t=n-t;          //��ɹ�����ͬ��
        cnt=0;
        for(i=1;i<=n;i++){
            if(s1[i]==s2[i]){
                cnt++;
            }
        }
        if(cnt>=t){         //������е���ͬ�ĸ�������Ҫ��ģ���ô��ֱ������t����ͬ��������ȫ����ͬ
            cnt=min(cnt,t);
            for(i=1;i<=n;i++){
                if(s1[i]==s2[i] && cnt){
                    printf("%c",s1[i]);cnt--;
                }else printDiff(s1[i],s2[i]);
            }
        }else {
            if((t-cnt)*2>n-cnt){            //��ͬ��С��Ҫ����ͬ�ģ���ô������cnt����ͬ��������2*(t-cnt)����
                printf("-1\n");continue;      //���ֱ��s1��s2��ͬ�ģ������������𰸵��ַ������ã����޽�
            }
            int d=0,c=(t-cnt)*2;
            for(i=1;i<=n;i++){
                if(s1[i]==s2[i])
                    printf("%c",s1[i]);
                else if(c){
                    if(d) printf("%c",s1[i]);   //��s1��ͬ���s2��ͬ������֣�
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
