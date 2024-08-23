// chuong1_bai6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using  namespace std;
int extendedGDC(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int gcd = extendedGDC(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}
int main()
{
    int a, b, c;
    cout << "Nhap a, b, c :";
    cin >> a >> b >> c;
    int x, y;
    int gcd = extendedGDC(a, b, x, y);
    if (c % gcd != 0)
    {
        cout << "Phuong trinh vo nghiem" << endl;
    }
    else
    {
        x *= c / gcd;
        y *= c / gcd;
        cout << "Phuong trinh co nghiem x = " << x << " va y= " << y << endl;
    }
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
