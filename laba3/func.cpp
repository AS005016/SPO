#include "pch.h"
#include <utility>
#include <limits.h>
#include "Header.h"
#include<iostream>
using namespace std;

void func(char*s_1, char*s_2,int n) {
	int j = 0;
	for (int i = 1; i < strlen(s_1); i++) {
		if (i % n != 0) {
			s_2[j] = s_1[i];
			j++;
		}
	}
	s_2[j] = '\0';
	cout << s_2 << endl;
}