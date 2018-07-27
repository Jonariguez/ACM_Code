/****************
*ID:uva1592
*Auth:Jonariguez
*****************
STL ��¼���أ�ID��
*/
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;
typedef pair<int,int> PII;

const int maxr=10000+10;
const int maxc=15;

int n,m,Id;
int db[maxr][maxc];

map<string,int> id;

int ID(const string& str){
    if(!id.count(str)){
        return id[str]=Id++;
    }
    return id[str];
}

void solve(){
    int i,j,k;
    for(i=0;i<m-1;i++){
        for(j=i+1;j<m;j++){
            map<PII,int> d;         //�ж϶�Ԫ���Ƿ���ֹ�,ע�⣬int��������1����ʾ���ֹ���������k��
            for(k=0;k<n;k++){            //�����������ж��Ƿ���ֹ������ܵõ��ڵڼ��г��ֹ�������Ҫ��
                PII p = make_pair(db[k][i],db[k][j]);
                if(d.count(p)){
                    printf("NO\n");
                    int t=d[p];
                    printf("%d %d\n",t+1,k+1);
                    printf("%d %d\n",i+1,j+1);
                    return ;
                }
                d[p]=k;
            }
        }
    }
    printf("YES\n");
}

int main()
{
    int i,j;
    string s;
    while(getline(cin,s)){
        stringstream ss(s);
        if(!(ss>>n>>m)) break;
        Id=0;
        id.clear();
        for(i=0;i<n;i++){
            getline(cin,s);
            int last=-1;
            for(j=0;j<m;j++){
                int p=s.find(',',last+1);
                if(p==string::npos) p=s.length();
                db[i][j]=ID(s.substr(last+1,p-last-1));
                last=p;
            }
        }
        solve();
    }
    return 0;
}

