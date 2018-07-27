/****************
*PID:poj1862
*Auth:Jonariguez
*****************
每次取较大的两个
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

priority_queue<double> que;

int main()
{
    int i,j,n;
    double res;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        double x;
        scanf("%lf",&x);
        que.push(x);
    }
    n--;
    while(n--){
        double x=que.top();que.pop();
        double y=que.top();que.pop();
        que.push(2*sqrt(x*y));
    }
    printf("%.3f\n",que.top());
    return 0;
}
