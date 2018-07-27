/*http://www.cnblogs.com/dolphin0520/archive/2011/10/15/2213752.html
存在前缀的序列的性质：
引用：存在若干个字符串序列，对于两个
字符串序列X[1....n]，Y[1....m]，如果X是Y的前缀，
则在对所有的字符串序列按字典顺序排序后，
X[1..n]和Y[1....m]在位置上必然是直接相邻或者
间接相邻的。间接相邻指存在字符串序列Z[1....t]，
使得X是Z的前缀(X和Z直接相邻)，Z是Y的前缀(Z和Y
直接相邻)，则X和Y也被认为是相邻的。
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=500000+10;

struct Str{
    int len;
    char ss[11];
}s[10005];

int cmp(const Str &x,const Str &y){
    return strcmp(x.ss,y.ss)<0;
}

int Strcmp(char *a,char *b){    //查看a是否是b的前缀，如果是返回0
    int i,n=strlen(a);
    for(i=0;i<n;i++)
        if(a[i]!=b[i]) return 1;
    return 0;
}

int main()
{
    int i,n,t;
    char str[11];
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%s",s[i].ss);
            s[i].len=strlen(s[i].ss);
        }
        sort(s,s+n,cmp);
        for(i=0;i<n-1;i++){
            int len1=s[i].len,len2=s[i+1].len;
            if(len1<=len2 && Strcmp(s[i].ss,s[i+1].ss)==0)
                break;
        }
        if(i==n-1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
