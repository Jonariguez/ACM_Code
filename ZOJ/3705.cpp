/****************
*PID:zoj3705
*Auth:Jonariguez
*****************
Ä£Äâ
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,s,e) for(i=(s);i<=(e);i++)
#define For(j,s,e) For(j=(s);j<(e);j++)
#define sc(x) scanf("%d",&x)
#define In(x) scanf("%I64d",&x)
#define pf(x) printf("%d",x)
#define pfn(x) printf("%d\n",(x))
#define Pf(x) printf("%I64d",(x))
#define Pfn(x) printf("%I64d\n",(x))
#define Pc printf(" ")
#define PY puts("YES")
#define PN puts("NO")
#include <stdio.h>
#include <string.h>
#include <string>
#include <math.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef int Ll;
Ll quick_pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=1000+10;
int n,m;
int problem[100001];
char Name[maxn][50];
map<string,int> competition;
map<string,int> ID;
pair<double,string> PP;
vector<int> s;
vector<pair<double,string> > res;

struct person{
    double score;
    int id;
}p[maxn];

void Init(){
    competition.clear();
    memset(problem,-1,sizeof(problem));
    res.clear();
    ID.clear();
    s.clear();
}

bool prime_judge(int n){
    if(n<2) return false;
    if(n==2) return true;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}

double Comp(char *str){
    string s=string(str);
    if(!competition.count(s)) return 0.0;
    int t=competition[s];
    if(t==1) return 36.0;
    if(t==2) return 27.0;
    if(t==3) return 18.0;
    return 0.0;
}

int main()
{
    int i,j,T;
    char team[50];
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        Init();
        int k;
        scanf("%d",&k);
        while(k--){
            int x;
            sc(x);
            problem[x]=0;
        }
        scanf("%d",&k);
        while(k--){
            int x;
            sc(x);
            problem[x]=1;
        }
        int Q;
        scanf("%d",&Q);
        while(Q--){
            int Rank;
            scanf("%s%d",team,&Rank);
            competition[string(team)]=Rank;
        }
        char name[50],teamname[50],sex[3];
        int x,c;
        for(i=1;i<=n;i++){
            scanf("%s%s%s",name,teamname,sex);
            memset(Name[i],0,sizeof(Name[i]));
            strcpy(Name[i],name);
            double score=0.0;
            score+=Comp(teamname);
            if(sex[0]=='F')
                score+=33.0;
            scanf("%d%d",&k,&c);
            while(k--){
                sc(x);
                if(problem[x]>=0){
                    if(problem[x]==0) score+=2.5;
                    else score+=1.5;
                }
                else {
                    if(prime_judge(x)) score+=1.0;
                    else
                        score+=0.3;
                }
            }
            x=0;
            s.clear();
            while(c--){
                sc(x);
                s.push_back(x);
            }
            p[i].score=(double)score;p[i].id=i;
            sort(s.begin(),s.end());
            if((int)s.size()>=3){
                double gain=max((double)0,1.0*(s[(int)s.size()-3]-1200)/100*1.5);
                p[i].score+=gain;
            }
        }
        for(i=1;i<=n;i++)
            res.push_back(make_pair(p[i].score*(-1),string(Name[i])));
        sort(res.begin(),res.end());
        for(i=0;i<m;i++){
            cout<<res[i].second<<" ";
            printf("%.3f\n",res[i].first*(-1));
        }
    }
    return 0;
}




