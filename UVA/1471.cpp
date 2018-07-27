/****************
*PID:uva1471
*Auth:Jonariguez
*****************
ö��j,i����(j,i)ɾ����Ȼ����ǰ����j��������i���������O(n^3)
Ԥ����L[],R[i]  O(n^2)
ֻö��i��j��logά��   O(nlogn)
*/
#include <stdio.h>
#include <string.h>
#include <set>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=200000+10;
const int INF=1e9+5;
int a[maxn],L[maxn],R[maxn];
struct Node{
    int v,g;
    Node(int v,int g):v(v),g(g){}
    bool operator < (const Node &r) const {
        return v<r.v;
    }
};

set<Node> s;

int main()
{
    int i,j,n,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        if(n==1){
            printf("1\n");continue;
        }
        int cnt=0;
        L[0]=0;a[0]=0;
        for(i=1;i<=n;i++){
            if(a[i]>a[i-1])
                L[i]=L[i-1]+1;
            else L[i]=1;
        }
        R[n+1]=0;a[n+1]=INF;
        for(i=n;i>=1;i--){
            if(a[i]<a[i+1])
                R[i]=R[i+1]+1;
            else R[i]=1;
        }
        s.clear();
        int res=1;
        s.insert(Node(a[1],L[1]));
        for(i=2;i<=n;i++){
            Node u=Node(a[i],L[i]);
            set<Node>::iterator it=s.lower_bound(u);
            int keep=1;
            if(it!=s.begin()){
                Node t=*(--it);
                int len=R[i]+t.g;
                res=max(res,len);
                if(t.g>=u.g)
                    keep=0;
            }
            if(keep){
                s.erase(u);     //�����˴�ʱ��u��û�в��룬���s���Ѿ��к�u��ȵ�(��v���),��ôһ��ɾ����Ϊ�¼ӵ�gһ����>=old g
                s.insert(u);
                it=s.find(u);
                it++;
                while(it!=s.end() && it->v > u.v && it->g<=u.g)
                    s.erase(it++);
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
