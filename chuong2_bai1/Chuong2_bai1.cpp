// Chuong2_vietchuongtrinhtinhmatrannghichdao.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <algorithm> 
#include <cmath>  
#include <vector>
using namespace std;
//tính định thức ma trận vuông
double determinant(vector<vector<double>> matrix, int n)
{
    double det = 0;

    if (n == 1)
    {
        return matrix[0][0];
    }
    if (n == 2)
    {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }

    vector<vector<double>> subMatrix(n, vector<double>(n));
    for (int x = 0; x < n; x++)
    {
        int sub_i = 0;
        for (int i = 1; i < n; i++)
        {
            int sub_j = 0;
            for (int j = 0; j < n; j++)
            {
                if (j == x)
                {
                    continue;
                }
                subMatrix[sub_i][sub_j] = matrix[i][j];
                sub_j++;
            }
            sub_i++;
        }
        double subDet = determinant(subMatrix, n - 1);
        det += (x % 2 == 0 ? 1 : -1) * matrix[0][x] * subDet;
    }
    return det;
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
    cout << "Dinh thuc cua ma tran A : " << determinant(A, n);
	return 0;
}


// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
