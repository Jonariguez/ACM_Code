/****************
*PID:uva1610
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=1000+10;

struct pp{
    char name[33];
}s[maxn];

int cmp(const pp &x,const pp &y){
    return strcmp(x.name,y.name)<0;
}

int main()
{
    int i,j,n,k;
    char res[33];
    while(scanf("%d",&n),n){
        for(i=1;i<=n;i++)
            scanf("%s",s[i].name);
        sort(s+1,s+n+1,cmp);
        char str1[33],str2[33];
        strcpy(str1,s[n/2].name);
        strcpy(str2,s[n/2+1].name);
        int len1=strlen(str1),len2=strlen(str2);
        k=0;
     /*   if(len1==1)
            strcpy(res,str1);
        else if(len2==1){
            if(str1[0]+1==str2[0])
                strcpy(res,str1);       //这里是不对的
            else{
                res[k++]=str1[0]-'A'+1+'A';res[k++]='\0';
            }
        }
        else {*/
            int l=min(len1,len2);
            k=0;
            for(i=0;i<l;i++){
                if(str1[i]==str2[i])
                    res[k++]=str1[i];
                else break;
            }
            if(i<l){
                if(i==len1-1)
                    res[k++]=str1[i];
                else if(str2[i]-str1[i]>=2)
                    res[k++]=str1[i]-'A'+1+'A';
                else if(str2[i]-str1[i]==1 && i!=len2-1)    //如果str2还没到最后，那么res[k]就可以等于str2[i]
                    res[k++]=str2[i];                       //这样就构造完成了
                else {
                    res[k++]=str1[i];            //这种情况是：str1[i]和str2[i]只差一个，而str2也已经到头了，
                    for(j=i+1;j<len1-1;j++){       //那么只能让res[k]=str1[i],然后按照str1[i+1..len1-1]构造了
                        if(str1[j]=='Z')        //这是构造str1后面是'Z'的情况的
                            res[k++]='Z';
                        else {
                            res[k++]=str1[j]-'A'+1+'A';
                            break;
                        }
                    }
                    if(j==len1-1)     //如果一直到最后都是'Z',那么就直接让res等于str1就行了，不能在后面多构造一个'A'
                        res[k++]=str1[j];
                }
            }
            res[k++]='\0';
      //  }
        printf("%s\n",res);
    }
    return 0;
}
