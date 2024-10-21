#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);

void SwapMinMaxInOddColumns(int** a, const int rowCount, const int colCount);

int main()
{
    srand((unsigned)time(NULL));
    int Low = 7;
    int High = 65;
    int rowCount, colCount;

    cout << "rowCount = "; cin >> rowCount;
    cout << "colCount = "; cin >> colCount;

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    Create(a, rowCount, colCount, Low, High);
    Print(a, rowCount, colCount);

   

    SwapMinMaxInOddColumns(a, rowCount, colCount);
    Print(a, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int rowCount, const int colCount)
{
    cout << endl;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}



void SwapMinMaxInOddColumns(int** a, const int rowCount, const int colCount)
{
    for (int j = 0; j < colCount; j += 2)  
    {
        int minRow = 0, maxRow = 0;

        
        for (int i = 1; i < rowCount; i++)
        {
            if (a[i][j] < a[minRow][j])
                minRow = i;
            if (a[i][j] > a[maxRow][j])
                maxRow = i;
        }

        
        int temp = a[minRow][j];
        a[minRow][j] = a[maxRow][j];
        a[maxRow][j] = temp;
    }
}
