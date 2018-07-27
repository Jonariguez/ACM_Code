/****************
*PID:uva101
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> pile[30];
int n;

void find(int x,int &p,int &h){
    for(p=0;p<n;p++)
        for(h=0;h<pile[p].size();h++)
            if(pile[p][h]==x) return ;
}

void move(int p,int h){
    for(int i=pile[p].size()-1;i>h;i--){
        int x=pile[p][i];
        pile[x].push_back(x);
        pile[p].pop_back();
    }
}

int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++) pile[i].push_back(i);
    char s[10],t[10];
    while(scanf("%s",s)){
        if(s[0]=='q') break;
        int a,b;
        scanf("%d %s %d",&a,t,&b);
     //   printf("%s %s\n",s,t);
        int pa,ha,pb,hb;
        find(a,pa,ha);
        find(b,pb,hb);

        if(pa==pb) continue;
        if(s[0]=='m'){
            move(pa,ha);// printf("??\n");
            if(t[1]=='n'){
                move(pb,hb);
            }
            pile[pb].push_back(a);
            pile[pa].pop_back();
        }else {
            if(t[1]=='n'){
                move(pb,hb);
            }
            for(i=ha;i<pile[pa].size();i++)
                pile[pb].push_back(pile[pa][i]);
            for(i=pile[pa].size()-1;i>=ha;i--)
                pile[pa].pop_back();
        }
    }
    for(i=0;i<n;i++){
        printf("%d:",i);
        for(j=0;j<pile[i].size();j++) printf(" %d",pile[i][j]);
        printf("\n");
    }
    return 0;
}

