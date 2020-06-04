//3. Write a class, KeepString, which is satisfied with function call in main.  
// You should define appropriate member variables and member functions respectively.
#include<iostream>
using namespace std;

class KeepString
{  
private:
	const char* name;
public:
	KeepString(const char* s)
	{
		name = s;
	}
	const char* GetString()
	{
		const char* p = name;
		return p;
	}
};


int main()
{
	KeepString  KS("Internal String");
	const char* p = KS.GetString();
	cout << p << endl;    // Output is:  Internal String
}
