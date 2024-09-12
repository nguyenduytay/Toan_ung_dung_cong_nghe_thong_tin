// Chuong2_bai4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

//tinh tich hai vector
vector<vector<double>> Multiply(vector<vector<double>> a, vector<vector<double>> b)
{
    int m = a.size();//số hàng cảu ma trận a
    int n = a[0].size();//số cột của ma trận a, cũng là số hàng của ma trận b
    int p = b[0].size();//số cột của ma trận b
    vector<vector<double>> newMatrix(m, vector<double>(p, 0));
    for (int i = 0; i < m; i++)
    {
        for (int k = 0; k < n; k++)
        {
            double temp = a[i][k];
            for (int j = 0; j < p; j++)
            {
                newMatrix[i][j] += temp * b[k][j];
            }
        }
    }
    return newMatrix;
}
//tinhs giá trị của biểu thức f(x)
double f(double x, vector<double> a)
{
    int n = a.size();
    double T = 0;
    for (int i = 0; i < n; i++)
    {
        T += a[i] * pow(x, n - 1 - i);
    }
    return T;
}

//Timf nghiệm cuar phương trình 
void timNghiem(double k, vector<double> a, vector<double> b, vector<double>& r)
{
    double y = 0, x = k;
    do
    {
        y = x;
        x = y - f(y, a) / f(y, b);
    } while (abs(x - y) > 1e-5);

    r.push_back(x);
}

//Giai phuong trinh
void solveTheEquation(vector<double> a, vector<double>& r)
{
    int n = a.size();
    double m1 = abs(a[1]), m2 = abs(a[0]);
    for (int i = 1; i < n - 1; i++)
    {
        if (m1 < abs(a[i + 1]))
            m1 = abs(a[i + 1]);
        if (m2 < abs(a[i]))
            m2 = abs(a[i]);
    }
    double x1 = (abs(a[n - 1])) / (m2 + abs(a[n - 1]));
    double x2 = 1 + m1 / (abs(a[0]));
    vector<double> b(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        b[i] = a[i] * (n - i - 1);
    }

    double i = -x2;
    do
    {

        if (f(i, a) * f(i + 0.3, a) < 0)
        {
            timNghiem(i, a, b, r);
        }
        i += 0.3;
    } while (i < x2);
    return;
}
bool Kiemtradoixung(vector<vector<double>> a)
{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <=i; j++)
        {
            if (i != j)
            {
                if (a[i][j] != a[j][i])
                    return true;
            }
        }
    }
    return false;
}
//Phân rã Cholesky
void cholesky(vector<vector<double>> A,vector<vector<double>> &L)
{
    int n = A.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            double sum = 0;
            if (j==i)
            {
                for (int k = 0; k < j; k++)
                    sum += L[j][k] * L[j][k];
                L[j][j] = sqrt(A[j][j] - sum);
            }
            else
            {
                for (int k = 0; k < j; k++)
                    sum += L[i][k] * L[j][k];
                L[i][j] = (A[i][j] - sum) / L[j][j];

            }
        }
    }
}
int main()
{
    cout << "Nhap n (Ma tran A nxn) : ";
    int n;
    cin >> n;
    vector<vector<double>> matrix(n, vector<double>(n));
    cout << "Nhap ma tran " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    //-----
    vector<vector<double>> A(n, vector<double>(n));
    vector<double> S(n);
    vector<double> a(n);
    vector<double> x(n + 1);
    A = matrix;
    for (int i = 0; i < n; i++)
    {
        S[i] = 0;
        for (int j = 0; j < n; j++)
        {
            S[i] += A[j][j];
        }
        A = Multiply(matrix, A);
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = 0;
        for (int j = 0; j <= i; j++)
        {
            a[i] += S[j] * (i == j ? 1 : a[i - j - 1]);

        }
        a[i] = a[i] * (-1.0) / (i + 1);
    }
    x[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        x[i] = a[i - 1];
    }
    //tinh chỉ so rieng
    vector<double> r;
    solveTheEquation(x, r);
    //điều kiện kiểm tra 
    if (Kiemtradoixung(A) == true)
    {
        cout << "Dieu kien cua ma tran khong phu hơp phan ra boi Cholesky";
         return 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (r[i] < 0)
        {
            cout << "Dieu kien cua ma tran khong phu hơp phan ra boi Cholesky";
            return 0;
        }
    }
    vector<vector<double>> b(n, vector<double>(n,0));
    vector<vector<double>> c(n, vector<double>(n, 0));
    cholesky(matrix, b);
    cout << "Ma tran tam giac duoi la" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <n; j++)
        {
                cout << b[i][j] << " ";
                c[j][i] = b[i][j];
        }
        cout << endl;
    }
    cout << endl;
    cout << "Ma tran tam giac tren la" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

                cout << c[i][j] << " ";
        
        }
        cout << endl;
    }
    return 0;
}

