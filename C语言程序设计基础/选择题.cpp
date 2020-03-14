struct sk
{
	int a;
	float b;
}data,*p=&data;
int main() {
	(*p).a;
}


