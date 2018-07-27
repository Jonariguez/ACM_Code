#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=100000+10;
char a[maxn],b[maxn],c[maxn];
int cnt[30],cnta[30],cntb[30],cntc[30];

/*
int main()
{
    int i,j,n;
    while(scanf("%s%s%s",a,b,c)!=EOF){
        memset(cnta,0,sizeof(cnta));
        memset(cntb,0,sizeof(cntb));
        memset(cntc,0,sizeof(cntc));
        memset(cnt,0,sizeof(cnt));
        for(i=0;a[i]!='\0';i++)
            cnta[a[i]-'a']++;
        for(i=0;b[i]!='\0';i++)
            cntb[b[i]-'a']++;
        for(i=0;c[i]!='\0';i++)
            cntc[c[i]-'a']++;
        memcpy(cnt,cnta,sizeof(cnta));
        int r1=1000000+2,r2=1000000+2,b1=1000000+5,b2=1000000+5;
        for(j=0;j<26;j++)
            if(cnta[j]<cntb[j]) break;
        if(j==26){      //b可以
            int flag=1;
            for(i=0;i<26;i++){
                if(cntb[i]){
                    r1=min(r1,cnta[i]/cntb[i]);
                   // cnta[i]%=cntb[i];
                }
            }
            for(i=0;i<26;i++){
                cnta[i]-=cntb[i]*r1;
                if(cnta[i]<cntc[i]) flag=0;
            }
         //   printf("???\n");
            if(flag){   //c可以
                for(i=0;i<26;i++){
                    if(cntc[i]){
                        b1=min(b1,cnta[i]/cntc[i]);
                     //   cnta[i]%=cntc[i];
                    }
                }
                for(i=0;i<26;i++)
                    cnta[i]-=cntc[i]*b1;
            }else
                b1=0;
        }else {     //i<26 b不可以
            r1=0;
            for(i=0;i<26;i++)
                if(cnta[i]<cntc[i]) break;
            if(i==26){  //c可以
                 for(i=0;i<26;i++){
                    if(cntc[i]){
                        b1=min(b1,cnta[i]/cntc[i]);
                      //  cnta[i]%=cntc[i];
                    }
                 }
                 for(i=0;i<26;i++)
                    cnta[i]-=cntc[i]*b1;
            }else b1=0;
        }
        //*****
        for(j=0;j<26;j++)
            if(cnt[j]<cntc[j]) break;
        if(j==26){      //c可以
            int flag=1;
            for(i=0;i<26;i++){
                if(cntc[i]){
                    r2=min(r2,cnt[i]/cntc[i]);
                  //  cnt[i]%=cntc[i];
                }
               // if(cnt[i]<cntb[i]) flag=0;
            }
            for(i=0;i<26;i++){
                cnt[i]-=cntc[i]*r2;
                if(cnt[i]<cntb[i]) flag=0;      //***
            }
            if(flag){   //b也可以
                for(i=0;i<26;i++){
                    if(cntb[i]){
                        b2=min(b2,cnt[i]/cntb[i]);
                       // cnt[i]%=cntb[i];
                    }
                }
                for(i=0;i<26;i++)
                    cnt[i]-=cntb[i]*b2;
            }else
                b2=0;
        }else {     //c不可以
            r2=0;
            for(i=0;i<26;i++)
                if(cnt[i]<cntb[i]) break;
            if(i==26){
                for(i=0;i<26;i++){
                    if(cntb[i]){
                        b2=min(b2,cnt[i]/cntb[i]);
                      //  cnt[i]%=cntb[i];
                    }
                }
                for(i=0;i<26;i++)
                    cnt[i]-=cntb[i]*b2;
            }else
                b2=0;
        }

        if(b1+r1>b2+r2){
         //   printf("b1=%d,r1=%d\n",b1,r1);
         //   printf("b2=%d,r2=%d\n",b2,r2);
            for(i=0;i<r1;i++)
                printf("%s",b);
            for(i=0;i<b1;i++)
                printf("%s",c);
            for(i=0;i<26;i++)
                for(j=0;j<cnta[i];j++)
                    printf("%c",'a'+i);
            printf("\n");
        }else {
         //   printf("b1=%d,r1=%d\n",b1,r1);
         //   printf("b2=%d,r2=%d\n",b2,r2);
            for(i=0;i<r2;i++)
                printf("%s",c);
            for(i=0;i<b2;i++)
                printf("%s",b);
            for(i=0;i<26;i++)
                for(j=0;j<cnt[i];j++)
                    printf("%c",'a'+i);
            printf("\n");
        }
    }
    return 0;
}
*/

int main()
{
    int i,j,n;
     while(scanf("%s%s%s",a,b,c)!=EOF){
        memset(cnta,0,sizeof(cnta));
        memset(cntb,0,sizeof(cntb));
        memset(cntc,0,sizeof(cntc));
        memset(cnt,0,sizeof(cnt));
        for(i=0;a[i]!='\0';i++)
            cnta[a[i]-'a']++;
        for(i=0;b[i]!='\0';i++)
            cntb[b[i]-'a']++;
        for(i=0;c[i]!='\0';i++)
            cntc[c[i]-'a']++;
        int sum=100000+10;
        for(i=0;i<26;i++)
            if(cntb[i])
            sum=min(sum,cnta[i]/cntb[i]);
        int x=0,y=0;
        for(i=0;i<=sum;i++){
            int t=100000+10;
            for(j=0;j<26;j++)
                if(cntc[j])
                    t=min(t,(cnta[j]-i*cntb[j])/cntc[j]);
            if(t+i>x+y)
                x=i,y=t;
        }
        for(i=0;i<x;i++)
            printf("%s",b);
        for(i=0;i<y;i++)
            printf("%s",c);
        for(i=0;i<26;i++){
            cnta[i]-=x*cntb[i]+y*cntc[i];
            while(cnta[i])
                printf("%c",'a'+i),cnta[i]--;
        }
        printf("\n");
     }
     return 0;
}


