// chuong1_bai3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void sieveofEratosthenes(long long n)
{
	vector<bool> isprme(n + 1, true);
	isprme[0] = isprme[1] = false;
	for (long long i = 2; i <= sqrt(n); i++)
	{
		if (isprme[i])
		{
			for (long long j = i * i; j < n; j += i)
			{
				isprme[j] = false;
			}
		}
	}
	ofstream outFile("C:\\Users\\NGUYEN DUY TAY\\source\\repos\\Toan_ung_dung\\chuong1_bai3\\save_Eratosthenes.txt");
	if (outFile.is_open())
	{
		outFile << " cac so nguyen to nho hon " << n << " la :\n";
		int index = 0;
		for (long long i = 2; i < n; i++)
		{
			if (isprme[i])
			{
				index++;
				outFile << i << " ";
				if (index % 100 == 0)
					outFile << endl;
			}
		}
		outFile << endl;
		outFile << " so luong phan tu la :" << index;
		outFile.close();
	}
	else
	{
		cout << "Khong the mo file";
	}
	return;
}
int main()
{
	long long n;
	cout << "Nhap so nguyen n :";
	cin >> n;
	sieveofEratosthenes(n);
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
