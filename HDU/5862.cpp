/****************
*PID:
*Auth:Jonariguez
*****************
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,s,e) for(i=(s);i<=(e);i++)
#define For(j,s,e) For(j=(s);j<(e);j++)
#define sc(x) scanf("%d",&x)
#define In(x) scanf("%I64d",&x)
#define SS(x,y) scanf("d",&x,&y)
#define pf(x) printf("%d",x)
#define pfn(x) printf("%d\n",(x))
#define Pf(x) printf("%I64d",(x))
#define Pfn(x) printf("%I64d\n",(x))
#define Pc printf(" ")
#define PY puts("YES")
#define PN puts("NO")
#define MP make_pair
#define X first
#define Y second
#define PI acos(-1.0)
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

const int maxn=100000+10;
const int MOD=1e9+7;

int bit[maxn*2],N;

struct node{
    int v;  //ֵ
    int lft; //lft=1:�����������ĳ���߶ε���˵㣬=0��������һ�����ŵ��߶Σ�-1������ĳ���߶ε��Ҷ˵�,������������������
    int y,y1,y2;
}s[maxn*3];

vector<int> lisan;
map<int,int> mp;

int cmp(const node &a,const node &b){
    if(a.v==b.v)        //������ֶ����x������ͬʱ��Ӧ���ȼ���˵㣬�ٲ�ѯ���ٳ����Ҷ˵�
        return a.lft>b.lft;
    return a.v<b.v;
}

//��������״����Ĵ���
void add(int i,int v){
    while(i<=N){
        bit[i]+=v;
        i+=i&(-i);
    }
}

int sum(int i){
    int res=0;
    while(i>0){
        res+=bit[i];
        i-=i&(-i);
    }
    return res;
}

int main()
{
    int i,j,n,m,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int tot=0;
        lisan.clear();
        for(i=1;i<=n;i++){
            int x1,x2,y1,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            if(x1==x2){     //˵������߶������ŵ�
                tot++;
                s[tot].v=x1;
                s[tot].lft=0;
                s[tot].y1=min(y1,y2);   //s[tot].y1����������ŵ��߶ε��¶˵��ֵ��ͬ��y2�����϶˵��ֵ
                s[tot].y2=max(y1,y2);
            }else {         //˵������߶��Ǻ��ŵģ���ô��Ҫ�����Ҷ˵���
                tot++;
                s[tot].v=min(x1,x2);
                s[tot].lft=1;       //���Ǹ���˵�
                s[tot].y=y1;    //s[tot].y=y2Ҳ�ǿ��Եģ���Ϊy1��y2����ȵģ���һ��
                tot++;
                s[tot].v=max(x1,x2);
                s[tot].lft=-1;      //���Ǹ��Ҷ˵�
                s[tot].y=y1;
            }
            lisan.push_back(y1);    //�����г��ֹ���y���ӽ�ȥ��������ɢ��
            lisan.push_back(y2);
        }

        //���������ɢ��
        sort(lisan.begin(),lisan.end());    //ʹ��unique����֮ǰҪ������
        lisan.erase(unique(lisan.begin(),lisan.end()),lisan.end()); //�Ѻ����ظ��Ķ�ɾ��
        mp.clear();
        for(i=0;i<lisan.size();i++)
            mp[lisan[i]]=i+1;       //�����в�ͬ��yֵ��ɢ��Ϊ[1,li.size()]��Χ��

        N=lisan.size();
        sort(s+1,s+tot+1,cmp);
        memset(bit,0,sizeof(bit));
        LL res=0;
        for(i=1;i<=tot;i++){
            if(s[i].lft==1){       //����ĳ���߶ε���˵�,��Ӧ����ɨ�����ϵ��Ǹ���+1
                int temp=mp[s[i].y];    //���������ɢ����Ӧ�ã���������1e9��ô���s[i].yӳ��Ϊ��Χ��С��temp
                add(temp,1);
            }else if(s[i].lft==0){  //��ʱ�����ŵ��߶Σ��ò�ѯ��
                int down=mp[s[i].y1];   //��ɢ�������¶˵�
                int up=mp[s[i].y2];
                res+=sum(up)-sum(down-1);   //Ȼ����[down,up]�����Χ���ж��ٺ��ŵ��߶ξ��ж��ٽ���
            }else if(s[i].lft==-1){  //����ĳ���߶ε��Ҷ˵㣬��Ӧ����ɨ�����ϵ��Ǹ���-1
                int temp=mp[s[i].y];
                add(temp,-1);
            }
        }
        printf("%lld\n",res);
    }
    return 0;
}



