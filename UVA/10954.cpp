/*
Huffman编码
优先队列就是自己实现的
*/
#include <stdio.h>
#include <string.h>
typedef long long ll;

const int maxn=5000+10;

typedef struct PQueue{
    ll heap[maxn],Tot;
    PQueue() { Tot=0; }
    ll size(){ return Tot;}
    ll top() { return heap[1];}
    void push(ll x){
        heap[++Tot]=x;
        ll s=Tot,p=s/2;
        while(p>=1){
            if(heap[p]<=x)  break;
            heap[s]=heap[p];
            s=p;p/=2;
        }
        heap[s]=x;
    }
    void pop(){
        heap[1]=heap[Tot--];
        ll p=1,s=p*2,x=heap[1];
        while(s<=Tot){
            if(s+1<=Tot && heap[s+1]<heap[s])
                s++;
            if(heap[s]>x) break;
            heap[p]=heap[s];
            p=s;s*=2;
        }
        heap[p]=x;
    }
}PQueue;

int main()
{
    int i,j,n,t;
    ll res;
    while(scanf("%d",&n),n){
        PQueue pq;
        for(i=0;i<n;i++){
            scanf("%d",&t);
            pq.push(t);
        }
        res=0;
        while(pq.size()!=1){
            int a=pq.top();pq.pop();
            int b=pq.top();pq.pop();
            res+=a+b;
            pq.push(a+b);
        }
        printf("%lld\n",res);
    }
    return 0;
}
