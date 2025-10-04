#include <iostream>
using namespace std;

int main()
{
    // Dynamic 1D Array
    int i = 0;
    int *Arr = new int[i];

    // Static 2D array
    int Arr1[5][5];

    int rows, cols;
    cout << "Enter values of Rows: " << endl;
    cin >> rows;

    cout << "Enter values of Cols: " << endl;
    cin >> cols;

    // Dynamic 2D Array
    int **Arr2 = new int*[rows];
    for (int i = 0; i < rows; i++){
        Arr2[i] = new int[cols];
    }

    // Taking 2D Array Input
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            cin >> Arr2[i][j];
        }
    }
    
    // Output
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
           cout << Arr2[i][j] << " ";
        }
        cout << endl;
    }

    // Relesing Memory
    for (int i = 0; i < rows; i++){
        delete [] Arr2[i];
    }

    delete []Arr2;
    
    return 0;
}