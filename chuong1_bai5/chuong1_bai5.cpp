// chuong1_bai5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void count(int a, int m, int n)
{
    //ch??ng trình tính z^m mod n
    int result = 1;
    a = a % n;
    while (m > 0)
    {
        if (m % 2 == 1)
            result = (result * a) % n;
        m = m / 2;
        a = (a * a) % n;
    }
    cout << "Gia tri can tim la : \n";
    cout << result<< endl;
}
int main()
{
    int m, n, a;
    cout << "Nhap gia tri lan luot cho a, m, n : ";
    cin >> a >> m >> n;
    count(a, m, n);
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
