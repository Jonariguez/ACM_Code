#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

const int maxcol=60;
const int maxn=100+10;

string res[maxn][maxn];

void print(const string& str,int len,char extra){
    cout<<str;
    for(int i=str.length();i<len;i++)
        cout<<extra;
}

int main()
{
    int n,M,i,j,r;
    while(cin>>n){
        string file[maxn];
        map<string,int> cnt;
        M=0;
        for(i=0;i<n;i++){
            cin>>file[i];
            cnt[file[i]]++;
            M=max(M,(int)file[i].length());
        }
      //  cout<<"------------------------------------------------------------"<<endl;
        print("",60,'-');
        cout<<endl;
        int col=(maxcol-M)/(M+2)+1,row=(n+col-1)/col;
        sort(file,file+n);
        for(i=0;i<n;i++)
            res[i%row][i/row]=file[i];
        int flag=0;
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                int id=j*row+i;
                if(id<n)
                    print(file[id],j==col-1?M:M+2,' ');
            }
            cout<<endl;
        }
  /*      for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                 if(cnt[res[i][j]])   print(res[i][j],j==col-1?M:M+2,' ');
                    if(++cnt==n) {
                            flag=1;break;
                    }
            }
            cout<<endl;
            if(flag) break;
        }*/
    }
    return 0;
}
