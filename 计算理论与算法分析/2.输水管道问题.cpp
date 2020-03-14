#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;
long long input[4000001];
int main(){
	//FILE* vvv = freopen("input.txt", "r", stdin);
	int count = 0;
	while (scanf("%*lld%*c%lld",&input[count])!=EOF)
		count++;
	nth_element(input, input + (count -1)/ 2 , input + count);
	printf("%lld\n", input[(count -1)/ 2]);
	return 0;
}