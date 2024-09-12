// Chuong2_bai2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

vector<double> Giaihephuongtrinh(vector<vector<double>>& matrix, int n) {
   
    
    for (int i = 0; i < n; i++) {
        // Tìm hàng có giá trị lớn nhất tại cột i (pivot)
        int maxRow = i;
        for (int k = i + 1; k < n; k++) {
            if (abs(matrix[k][i]) > abs(matrix[maxRow][i])) {
                maxRow = k;
            }
        }
        // Đổi chỗ hàng hiện tại với hàng maxRow
        swap(matrix[i], matrix[maxRow]);

        // Đảm bảo rằng phần tử trên đường chéo chính không bằng 0
        if (matrix[i][i] == 0) {
            cout << "Không có nghiệm duy nhất!" << endl;
            return {};
        }

        // Khử các phần tử dưới đường chéo chính
        for (int k = i + 1; k < n; k++) {
            double factor = matrix[k][i] / matrix[i][i];
            for (int j = i; j <= n; j++) {
                matrix[k][j] -= factor * matrix[i][j];
            }
        }
    }

    //Thế ngược - Tìm nghiệm
    vector<double> x(n);
    for (int i = n - 1; i >= 0; i--) {
        x[i] = matrix[i][n] / matrix[i][i];
        for (int k = i - 1; k >= 0; k--) {
            matrix[k][n] -= matrix[k][i] * x[i];
        }
    }
    return x;
}
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

//tính định thức của ma trận 
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

//tinh tich hai vector
vector<vector<double>> Multiply(vector<vector<double>> a, vector<vector<double>> b)
{
    int m = a.size();//số hàng cảu ma trận a
    int n = a[0].size();//số cột của ma trận a, cũng là số hàng của ma trận b
    int p = b[0].size();//số cột của ma trận b
    vector<vector<double>> newMatrix(m, vector<double>(p,0));
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

//tính giá trị của biểu thức f(x)
double f(double x, vector<double> a)
{
    int n = a.size();
    double T = 0;
    for (int i = 0; i < n; i++)
    {
        T += a[i] * pow(x,n - 1-i);
    }
    return T;
}

//Tìm nghiệm của phương trình 
void timNghiem(double k,vector<double> a, vector<double> b,vector<double> &r)
{
    double y = 0, x = k;
    do
    {
        y = x;
        x = y - f(y, a) / f(y, b);
    } while (abs(x - y) > 1e-5);

    r.push_back(x);
}

//Giải phương trình
void solveTheEquation(vector<double> a,vector<double> &r)
{
    int n = a.size();
    double m1 = abs(a[1]), m2 = abs(a[0]);
    for (int i = 1; i < n - 1; i++)
    {
        if (m1 < abs(a[i + 1]))
            m1 =abs(a[i + 1]);
        if (m2 < abs(a[i]))
            m2 = abs(a[i]);
    }
    double x1 = (abs(a[n - 1])) / (m2 + abs(a[n - 1]));
    double x2 = 1 + m1 / (abs(a[0]));
    vector<double> b(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        b[i] = a[i] * (n-i-1);
    }
  
    double i = -x2;
    do
    {
        if (f(i, a) * f(i + 0.3,a) < 0)
        {
            timNghiem(i,a,b,r);  
        }
        i+=0.3;
    } while (i<x2);
    return;
}
//tìm vector riêng của ma trận 
void matrixPrivate(vector<vector<double>> a)
{
    int n = a.size();
    int m =n-1;
    vector<double> x(m,0);
    vector<vector<double>> b(m, vector<double>(n));
    int index = 0;
   
    int h = 0;
    for (int i = 0; i < n; i++)
    {
        int k = 0;
        for (int j = 0; j < n - 1; j++)
        {
            if (a[i][j] != 0)
            {
                break;
            }
            k++;    
        }
        if (k != m)
        {
            k = 0;
            for (int j = 0; j < n; j++)
            {
                if (j == n - 1)
                {
                    b[h][k] = -a[i][j];
                }
                else
                {
                    b[h][k] = a[i][j];
                }
                k++;
                index++;
            }
            h++;
        }
        if (index == m * n)
            break;
    }
    x = Giaihephuongtrinh(b, m);
    x.push_back(1);
    cout << "Vector rieng" << endl;
    cout << "[";
    for (int i = 0; i < n; i++)
    {
        if (x[i] == -0)
        {
            cout << 0 << " ";
        }
        else
        {
            cout << x[i] << " ";
        }
        
    }
    cout << "]";
    cout << endl;
}
int main()
{
    vector<vector<double>> matrix = {
        {2,0,0},
        {1,2,-1},
        {1,3,-2}
        };
    int n = matrix.size();
    double det = determinant(matrix, n);
    if (det == 0)
    {
        cout << "Ma tran det = 0";
        return 0;
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
            for (int j = 0; j<n; j++)
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
                a[i] += S[j]*(i==j?1:a[i-j-1]);
                
            }
            a[i] =a[i]* (-1.0) / (i + 1);
        }
        x[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            x[i] = a[i - 1];
        }
        //tinh chỉ so rieng
       vector<double> r;
       solveTheEquation(x,r);
       cout << "Chi so rieng cua Ma tran A: " << endl;
       for (int i = 0; i < r.size(); i++)
       {
           cout <<"r"<< i+1<< " = " <<r[i] <<endl;
       }
       cout << endl;
      ////tính vector rieng
       for (int i = 0; i < r.size(); i++)
       {
           vector<vector<double>> B(n, vector<double>(n));
           vector<vector<double>> C(n, vector<double>(1, 0));
           B = matrix;
          
           for (int j = 0; j < n; j++)
           {
               B[j][j] -= r[i];
               if (abs(B[j][j]) < 1e-3 )
                   B[j][j] = 0;
           }
       //    triangleMatrix(B);
          /* for (int k = 0; k < n; k++)
           {
               for (int j = 0; j < n; j++)
               {
                   cout << B[k][j] <<" ";
               }
               cout <<endl;
           }*/
           matrixPrivate(B);
           cout << endl;
       } 
    return 0;
}


