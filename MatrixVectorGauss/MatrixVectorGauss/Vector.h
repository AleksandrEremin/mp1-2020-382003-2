#pragma once
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include <iomanip> 

using namespace std;
class vector
{
	double* V;
	int n;
public:
	vector(int n=1);
	void vectorRand();
	void vectorPrint();
	void vectorWrite();
	double& operator[](int i);
	vector& operator=(const vector& v);
	~vector()
	{
	}
};
