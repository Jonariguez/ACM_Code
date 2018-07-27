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
                strcpy(res,str1);       //�����ǲ��Ե�
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
                else if(str2[i]-str1[i]==1 && i!=len2-1)    //���str2��û�������ôres[k]�Ϳ��Ե���str2[i]
                    res[k++]=str2[i];                       //�����͹��������
                else {
                    res[k++]=str1[i];            //��������ǣ�str1[i]��str2[i]ֻ��һ������str2Ҳ�Ѿ���ͷ�ˣ�
                    for(j=i+1;j<len1-1;j++){       //��ôֻ����res[k]=str1[i],Ȼ����str1[i+1..len1-1]������
                        if(str1[j]=='Z')        //���ǹ���str1������'Z'�������
                            res[k++]='Z';
                        else {
                            res[k++]=str1[j]-'A'+1+'A';
                            break;
                        }
                    }
                    if(j==len1-1)     //���һֱ�������'Z',��ô��ֱ����res����str1�����ˣ������ں���๹��һ��'A'
                        res[k++]=str1[j];
                }
            }
            res[k++]='\0';
      //  }
        printf("%s\n",res);
    }
    return 0;
}
