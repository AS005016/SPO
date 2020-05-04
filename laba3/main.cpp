#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <string.h>
#include <iostream>

using namespace std;

int main() {
	char* s_1= new char[20];
	int n = 0;
	cout<<"Enter any string: "<< endl;
	cin >> s_1;
	cout << "Enter n: " << endl;
	cin >> n;
	char* s_2 = new char[strlen(s_1)];
	HMODULE hlib = LoadLibrary(TEXT("myDll.dll"));
	if (hlib == NULL) 
		cout << "ERROR_1" << endl;
	typedef void (*function)(char* s_1, char* s_2,int n);
	function func = (function)GetProcAddress(hlib, "func");
	if (func == NULL)
		cout << "ERROR_2" << endl;
	else func(s_1, s_2,n);

	FreeLibrary(hlib);
	system("pause");

}
