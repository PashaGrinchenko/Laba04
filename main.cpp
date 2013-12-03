//Вариант 10. В каждой строке массива A(N,M) найти и удалить максимальный элемент.
#include <iostream>
#include <stdlib.h>
using namespace std;
void EnterMatrix(int cols, int rows);
void OutputMatrix(int **mas, int cols, int rows, int q);
int FindMaxOfString (int rows,int cols, int **mas);
int main()
{
    int rows = 5, cols = 5;
    EnterMatrix(cols,rows);
    return 0;
}

void EnterMatrix(int cols, int rows)
{
    int **p = new int*[rows];
    for(int i=0;i<rows;++i)
    {
        p[i] = new int[cols];
        for(int j=0;j<cols;++j)
        {
            p[i][j] = rand()%10;
        }
    }
    cout<<" Input Matrix : \n\n";
    OutputMatrix(p,cols,rows,1);
}

void OutputMatrix(int **mas, int cols, int rows, int k)
{
    for(int i=0;i<rows;++i)
    {
        for(int j=0;j<cols;++j)
        {
            cout.width(3);
            cout <<mas[i][j];
        }
        cout << endl<<endl;
    }
    cout << "\n";
    if(k==1)
    {
        cout << " Output Matrix : \n\n";
        FindMaxOfString(rows,cols,mas);

    }

}

int FindMaxOfString (int rows,int cols, int **mas)
{
    int maxind, maxelem;
    int c;
    for(int i=0; i<rows; ++i)
    {
        maxelem=mas[i][0];
        maxind=0;
        for (int j=0; j<cols; ++j)
        {
            if (maxelem<mas[i][j])
            {
                maxelem=mas[i][j];
                 maxind=j;

            }

        }
         c = mas[i][maxind];
         for(int k=maxind;k<cols-1;++k)
         {
             mas[i][k] = mas[i][k+1];

         }
         mas[i][cols-1] = mas[i][maxind];


    }
    OutputMatrix(mas,cols-1,rows,2);
}

