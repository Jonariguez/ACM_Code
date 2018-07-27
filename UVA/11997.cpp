#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn=800;
int a[maxn][maxn],n;
vector<int> ans;

struct PP{
    int sum,b;
    PP(int sum,int b):sum(sum),b(b){}
    bool operator < (const PP &r) const {
        return sum>r.sum;           //如果想要前n大的数，只需要把>改成<即可
    }
};

//一定把最小的n个再放回到a[0]里，让a[0]和a[1],a[2],...a[n-1]一直合并，最终a[0]就是答案
void merge(int *a,int *b,int *c){
    int i;
    priority_queue<PP> pq;
    for(i=0;i<n;i++)
        pq.push(PP(a[i]+b[0],0));
    for(i=0;i<n;i++){
        PP t=pq.top();pq.pop();
        c[i]=t.sum;
        if(t.b<n-1)
            pq.push(PP(t.sum-b[t.b]+b[t.b+1],t.b+1));
    }
}

int main()
{
    int i,j;
    while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++) scanf("%d",&a[i][j]);
            sort(a[i],a[i]+n);
        }
        for(i=1;i<n;i++)
            merge(a[0],a[i],a[0]);
        for(i=0;i<n;i++)
            printf("%d%c",a[0][i],i==n-1?'\n':' ');
    }
    return 0;
}
