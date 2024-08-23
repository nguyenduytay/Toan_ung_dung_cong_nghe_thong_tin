// chuong1_bai7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;
int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
//tính gcd mở rộng để tìm nghịch đảo modular
int extendedGCD(int a, int b, int& x, int& y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int gcd = extendedGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return gcd;
}
//hàm tìm nghịch đảo modular
int modInverse(int a, int m)
{
    int x,y;
    int g = extendedGCD(a, m, x, y);
    if (g != 1)
    {
        return -1;
        //nghịch dảo không tồn tại 
    }
    return (x % m + m) % m;
}
int main()
{
    int k;
    int T=1;
    cout << "Nhap k = ";
    cin >> k;
    int* m = new int[k];
    int* a = new int[k];
    int* M = new int[k];
    int* y = new int[k];
    for (int i = 0; i < k; i++)
    {
        cout << "nhap a[" << i +1<< "] va m[" << i + 1 << "] :";
        cin >> a[i] >> m[i];
        cout << endl;
        T *= m[i];
    }
    for (int i = 0; i < k - 1; i++)
    {
        for (int j = i + 1; j < k; j++)
        {
            if (gcd(m[i], m[j]) == 1)
            {
                cout << "Phuong trinh vo nghiem";
                delete[] M;
                delete[] a;
                delete[] m;
                delete[] y;
                return 0;
            }   
        }
    }
    int x = 0;
    for (int i = 0; i < k; i++)
    {
        M[i] = T / m[i];
        y[i] =modInverse(M[i],m[i]);
        x += a[i] * M[i] * y[i];
    }
    x = x % T;
    cout << "Phuong trinh co nghiem : " << x <<"mod("<<T<<")" << endl;
    delete[] M;
    delete[] a;
    delete[] m;
    delete[] y;
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
