/****************
*PID:493a div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=110;
int card[2][maxn];
int resn[maxn],resm[maxn];
string team[maxn];

int main()
{
    int i,j,n;
    string home,away;
    cin>>home>>away;
    scanf("%d",&n);
    memset(card,0,sizeof(card));
    int num,m,k=0;
    string a,b,now;
    for(i=1;i<=n;i++){
        cin>>m>>a>>num>>b;
        int t;
        if(a[0]=='h'){
            now=home;t=0;
        }
        else {
            now=away;t=1;
        }
        if(b[0]=='y'){
            if(card[t][num]==1){
                team[k]=now;resn[k]=num;resm[k++]=m;
            }
            card[t][num]++;
        }else {
            if(card[t][num]<=1){
                team[k]=now;resn[k]=num;resm[k++]=m;
            }
            card[t][num]=2;
        }
    }
    for(i=0;i<k;i++)
        cout<<team[i]<<" "<<resn[i]<<" "<<resm[i]<<endl;
    return 0;
}
