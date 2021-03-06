// chuvsudigitmetlagranzh.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
#include <Windows.h>
#include <Psapi.h>

using namespace std;

void howfatly()
{
	PROCESS_MEMORY_COUNTERS_EX pmc;
	GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
	SIZE_T virtualMemUsedByMe = pmc.PrivateUsage;
	SIZE_T physMemUsedByMe = pmc.WorkingSetSize;
	cout << "PrivateUsage (Kb) = " << virtualMemUsedByMe / 1024 << "\n";
	cout << "WorkingSetSize (Kb) = " << physMemUsedByMe / 1024 << "\n";
}

inline double func(double x)
{
	return x * x + 4 * sin(x) - 2;
}

int main()
{
	int start = clock();
	double a = 0, b = 10;
	double xx = 0.5 * (a + b);
	int n = 10;
	double *x = new double[n];
	for (int i = 0; i < n; i++)
	{
		x[i] = 0.5 * ((b - a)*cos((i + 0.5)*3.1415926 / (n + 1)) + b + a);
	}
	double psi = 0;
	cout << "dannye:" << endl;
	for (int i = 0; i < n; i++)
	{
		double fi = func(x[i]);
		cout << "x=" << x[i] << " y=" << fi << endl;
		for (int j = 0; j < n; j++)
		{
			if (i != j) fi *= (xx - x[j]) / (x[i] - x[j]);
		}
		psi += fi;
	}
	cout << "znachenie v tochke " << xx << " : " << endl << psi << endl;
	cout << "proverka:" << endl << func(xx) << endl;
	cout << "zatracheno " << clock() - start << endl;
	howfatly();
	system("pause");
	return 0;
}

