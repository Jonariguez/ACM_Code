/****************
*PID:uva1626
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100+20;
char s[maxn];
int dp[maxn][maxn],n;

bool match(char a,char b){
    return (a=='(' && b==')') || (a=='[' && b==']');
}

void DP(){
    int i,j,k;
    for(i=0;i<=n;i++){
        dp[i+1][i]=0;   //即dp[i][j]出现i>j的情况，这种情况是0
        dp[i][i]=1;
    }
    for(i=n-2;i>=0;i--){
        for(j=i+1;j<n;j++){
            dp[i][j]=n;
            if(match(s[i],s[j]))
               dp[i][j]=min(dp[i][j],dp[i+1][j-1]);
            for(k=i;k<j;k++)
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
        }
    }
}

void print(int i,int j){
    if(i>j) return ;
    if(i==j){
        if(s[i]=='(' || s[i]==')') printf("()");
        else printf("[]");
        return ;
    }
    int &res=dp[i][j];
    if(match(s[i],s[j]) && res==dp[i+1][j-1]){
        printf("%c",s[i]);
        print(i+1,j-1);
        printf("%c",s[j]);
        return ;
    }
    for(int k=i;k<j;k++){
        if(res==dp[i][k]+dp[k+1][j]){
            print(i,k);print(k+1,j);
            return ;
        }
    }
}

void readline(char* S) {
  fgets(S, maxn, stdin);
}

int main() {
  int T;

  readline(s);
  sscanf(s, "%d", &T);
  readline(s);

  while(T--) {
    readline(s);
    n = strlen(s) - 1;
    memset(dp, -1, sizeof(dp));
    DP();
    print(0, n-1);
    printf("\n");
    if(T) printf("\n");
    readline(s);
  }
  return 0;
}

/*
int main()
{
    int i,j,T;
    scanf("%d",&T);
    getchar();
    getchar();
    while(T--){
        gets(s);
        if(s[0]=='\0'){
            printf("\n");getchar();continue;
        }
        n=strlen(s);
        memset(dp,-1,sizeof(dp));
        DP();
        print(0,n-1);
        printf("\n");
        if(T)
            printf("\n");
        getchar();
    }
    return 0;
}*/
