#include <stdio.h>
#include <windows.h>
using namespace std; 
int main(){
//	 freopen("duipai.in","w",stdout);
    int t=100,i = 1;
    while(t--){
        system("data>duipai.in");
        system("chengxu1<duipai.in>force.out");
        system("chengxu2<duipai.in>ceshi.out");
        if(system("fc force.out ceshi.out"))  break;
    } 
    return 0;
}
