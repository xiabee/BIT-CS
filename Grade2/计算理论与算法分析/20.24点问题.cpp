#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int flag[4] = { 0 };
double num[4];
int judge(int count) {
	int i, j;
	double num1, num2;
	//cout<<"count:"<<count<<endl;
	if (count == 4){
		for (i = 0; i < 4; i++)
			if (!flag[i] && fabs(num[i] - 24) <= 1e-6)
				return 1;
		return 0;
	}
	for (i = 0; i < 4; i++){
		if (!flag[i]){
			for (j = i + 1; j < 4; j++){
				if (!flag[j]){
					num1 = num[i];
					num2 = num[j];
					flag[j] = 1;	//a + b && b + a
					num[i] = num1 + num2;
					if (judge(count + 1))
						return 1;	//a * b && b * a
					num[i] = num1 * num2;
					if (judge(count + 1))
						return 1;	//a - b
					num[i] = num1 - num2;
					if (judge(count + 1))
						return 1;	//b - a
					num[i] = num2 - num1;
					if (judge(count + 1))
						return 1;	//a / b

					if (fabs(num2) > 1e-6)
					{
						num[i] = num1 / num2;
						if (judge(count + 1))
						{
							return 1;
						}
					}
					//b / a
					if (fabs(num1) > 1e-6){
						num[i] = num2 / num1;
						if (judge(count + 1))
							return 7;
					}
					flag[j] = 0;
					num[i] = num1;
				}
			}
		}
	}
	return 0;
}
void oper() {
	while (cin >> num[0] >> num[1] >> num[2] >> num[3]) {
		memset(flag, 0, sizeof(flag));
		if (judge(1))
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return;
}
int main() {
	oper();
	return 0;
}
