// Chuong2_bai3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
//tính ma trận nghịch đảo của ma trận 
vector<vector<double>> InverseMatrix(vector<vector<double>> A)
{
    int n = A.size();
    vector <vector<double>> I(n, vector<double>(n, 0));
    //khởi tạo ma trận đơn vị 
    for (int i = 0; i < n; i++)
    {
        I[i][i] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        double pivot = A[i][i];
        if (pivot == 0)
        {
            cout << "Ma tran khong kha nghich" << endl;
            exit(0);
        }
        for (int j = 0; j < n; j++)
        {
            A[i][j] /= pivot;
            I[i][j] /= pivot;
        }
        for (int k = 0; k < n; k++)
        {
            if (i != k)
            {
                double factor = A[k][i];
                for (int j = 0; j < n; j++) {
                    A[k][j] -= factor * A[i][j];
                    I[k][j] -= factor * I[i][j];
                }
            }
        }
    }
    return I;
}


int main()
{
    int n;
    cout << "Nhap nxn của ma trân A ";
    cin >> n;
    cout << "Nhap cac phan tu cua ma tran " << endl;
    vector<vector<double>> A(n, vector<double>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }
    A = InverseMatrix(A);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
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
