/****************
*PID:A
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=200;
map<string,int> Hash;
LL dp[maxn][maxn];
string dict[maxn];

int main()
{
    int i,j,k,t,n;
    while(scanf("%d",&n),n){
        string str,str2,temp;
       // getchar();
        Hash.clear();
        for(i=1;i<=n;i++){
            cin>>str;
            Hash[str]=1;
        }
        getchar();
        int m=0,flag=1;
        while(getline(cin,temp)){
            stringstream ss(temp);
            ss>>str;
            m=0;
            flag=1;
            while(ss>>str2){
                if(Hash[str2]==0)
                    dict[++m]=str2;
                if(str=="LAST" && str2=="CASE"){
                    flag=0;break;
                }
            }
            if(flag==0) break;
          //  printf("m=%d\n",m);
            memset(dp,0,sizeof(dp));
            int len=str.length();
            dp[0][0]=1;
           // for(i=0;i<=m;i++) dp[i][0]=1;
            for(j=1;j<=m;j++){
                temp=dict[j];
                int l=temp.length();//printf("l=%d\n",l);
                for(i=j;i<=len-(m-j);i++){
                    int cnt=0;
                    for(int v=1;v<=l;v++){
                        k=i;t=v;cnt=0;
                        while(t<=l && (temp[t-1]-'a')!=(str[k-1]-'A'))
                            t++;
                        v=t;
                        while(k<=len-(m-j) && t<=l){
                            if((str[k-1]-'A')==(temp[t-1]-'a')){
                                cnt++;
                                dp[j][i+cnt-1]+=dp[j-1][i-1];
                                k++;t++;
                            }else t++;
                        }
                        if(cnt==0) break;
                    }
                }
            }
           // printf("dp=%I64d\n",dp[1][1]);
            cout<<str;
            if(dp[m][len])
                printf(" can be formed in %I64d ways\n",dp[m][len]);
            else printf(" is not a valid abbreviation\n");
        }
    }
    return 0;
}
