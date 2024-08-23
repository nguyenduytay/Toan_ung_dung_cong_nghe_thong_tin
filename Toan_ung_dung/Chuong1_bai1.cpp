#include <iostream>
using namespace std;

void analysis(int n)
{
	int tich = 1; int tamp = n;
	for (int i = 2; i <= sqrt(n); i++)
	{
		int index = 0;
		while (n % i == 0)
		{
			index++;
			n = n / i;
			tich *= i;
		/*	cout<<i;*/
		/*	if (n > 1)
				cout<<"*";*/
		}
		if (index > 0)
		{
			cout << i<<"^"<<index;
		}	
		if ((n > 1 || tich < tamp) && index > 0)
			cout << "*";
	}
	if (n > 1)
	{
		cout<<n;
	}
	return;
}

int main()
{
	int n;
	cout << "Moi ban nhap so n =" << endl;
	cin >> n;
	cout << "Phan tich ta duoc " << endl;
	analysis(n);
	return 0;
}
