/****************
*PID:uva12545
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100+10;
char s[maxn],t[maxn];

int main()
{
    int i,j,k,n,T,kcase=1;
    scanf("%d",&T);
    while(T--){
        scanf("%s%s",s,t);
        n=strlen(s);
        int zero_one=0,one_zero=0,q_one=0,q_zero=0,res=0;
        for(i=0;i<n;i++){       //ͳ��0-1��1-0��?-1��?-0
            if(s[i]=='0' && t[i]=='1')
                zero_one++;
            else if(s[i]=='1' && t[i]=='0')
                one_zero++;
            else if(s[i]=='?' && t[i]=='0')
                q_zero++;
            else if(s[i]=='?' && t[i]=='1')
                q_one++;
        }
        while(one_zero && zero_one){    //��ͨ��0-1��1-0�����õ�0-0,1-1�Ե���
            one_zero--;zero_one--;
            res++;
        }
        while(one_zero && q_one){   //�������1-0����ô����?-1���0-1,Ȼ����0-1��1-0����������������
            one_zero--;q_one--;
            res+=2;
        }
        if(one_zero)    //�����Ҫ1-0�����޽���
            res=-1;
        else
            res+=zero_one+q_zero+q_one; //0-1,?-1,?-0������ͨ��һ���任��
        printf("Case %d: %d\n",kcase++,res);
    }
    return 0;
}
