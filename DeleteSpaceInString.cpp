#include <iostream>
#include <cstring>
using namespace std;
void deleteChar(char a[], int k)
{
	int n = strlen(a);   
	for(int i = k; i < n; i++)
	{
		a[i] = a[i+1];
	}
	a[n-1] = '\0';

}
void process(char str[], char outstr[])
{
	int n = strlen(str);
	while (str[0]==' ')
	{
		deleteChar(str,0);
		n--;
	}
	for(int i = 0; i < n; i++)
	{
		if(str[i]==' ' && str[i+1]==' ')
		{
			deleteChar(str,i);
			n--;
			i--;
		}	
	}
	while(str[n-1]==' ')
	{
		deleteChar(str,n-1);
		n--;
	}
	strcpy(outstr,str);
}
int main()
{
	char str[100], outstr[100];
	cout << " Nhap 1 chuoi: ";
	cin.getline(str, 100);
	process(str, outstr);
	cout << outstr;
	return 0;
}