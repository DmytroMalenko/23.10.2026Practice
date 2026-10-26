#include <iostream>
#include <cstdlib>
using namespace std;

void fillArr(int* arr, int size, int min, int max) {
    for (int i = 0; i < size; ++i) {
        int range = max - min + 1;
        arr[i] = rand() % range + min;
    }

}




void printArr(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
}




void print2d(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        printArr(arr[i], cols);
        cout << endl;
    }
}




void addRow(int**& arr, int& rows, int cols) {
    int** newArr = new int* [rows + 1];

    for (int i = 0; i < rows; ++i) {
        newArr[i] = arr[i];
    }

    newArr[rows] = new int[cols];
    fillArr(newArr[rows], cols, 0, 20);

    delete[] arr;
    arr = newArr;
    rows++;
}








void addRowtoBeginn(int**& arr, int& rows, int cols) {
    int** newArr = new int* [rows + 1];

    for (int i = 0; i < rows; ++i) {
        newArr[i + 1] = arr[i];      
    }

    newArr[0] = new int[cols];    
    fillArr(newArr[0], cols, 0, 20);

    delete[] arr;
    arr = newArr;
    rows++;
}




void addrandRow(int**& arr, int& rows, int cols, int position) {
    int** newArr = new int* [rows + 1];
    int j = 0;  
    for (int i = 0; i < rows + 1; ++i) {
        if (i == position) {
            newArr[i] = new int[cols];  
            fillArr(newArr[i], cols, 0, 20);
        }
        else {
            newArr[i] = arr[j];            
            j++;
        }
    }

    delete[] arr;
    arr = newArr;
    rows++;
}



bool ZeroinRows(int* row, int cols) {
    for (int i = 0; i < cols; ++i) {
        if (row[i] == 0) return true;
    }
    return false;
}



void removeZeroRows(int**& arr, int& rows, int cols) {
    int count = 0;
    for (int i = 0; i < rows; ++i) {
        if (!ZeroinRows(arr[i], cols)) count++;
    }

    int** newArr = new int* [count];
    int j = 0;

    for (int i = 0; i < rows; ++i) {
        if (!ZeroinRows(arr[i], cols)) {
            newArr[j] = arr[i];
            j++;
        }
        else {
            delete[] arr[i];
        }
    }
    delete[] arr;
    arr = newArr;
    rows = count;
}



int** create2d(int rows, int cols, bool fill) {
    int** arr = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        arr[i] = new int[cols];
        if (fill) fillArr(arr[i], cols, 0, 20);
    }
    return arr;
}

void delete2d(int** arr, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
}


int** multiply(int** A, int** B, int C, int D, int E) {
    int** F = create2d(C, E, false);

    for (int i = 0; i < C; ++i) {
        for (int j = 0; j < E; ++j) {
            F[i][j] = 0;
            for (int t = 0; t < D; ++t) {
                F[i][j] += A[i][t] * B[t][j];
            }
        }
    }
    return F;
}


void printRows(int size) {
    cout << "All rows: ";
    for (int r = 1; r <= size; ++r) {
        if (size % r == 0) {
            cout << r << " ";
        }
    }
    cout << endl;
}


int** change2d(int* arr, int size, int rows, int& cols) {
    if (rows <= 0 || size % rows != 0) {
        cout << "Wrong number of rows!" << endl;
        return nullptr;
    }

    cols = size / rows;
    int** arr2d = create2d(rows, cols, false);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            arr2d[i][j] = arr[i * cols + j];
        }
    }
    return arr2d;
}






int main(){
    srand(time(0));

    /* Task 1

    int rows = 6;
    int cols = 4;

    int** arr = new int* [rows];         

    for (int i = 0; i < rows; ++i) {
        arr[i] = new int[cols];           
        fillArr(arr[i], cols, 0, 20);  
    }

    print2d(arr, rows, cols);  

    cout << endl;  
    addRow(arr, rows, cols);

    cout << endl;
    print2d(arr, rows, cols);

    for (int i = 0; i < rows; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
    */


    /* Task 2 
    int rows = 6;
    int cols = 4;

    int** arr = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        arr[i] = new int[cols];
        fillArr(arr[i], cols, 0, 20);
    }

    cout << endl;
    print2d(arr, rows, cols);

    addRowtoBeginn(arr, rows, cols);

    cout << endl;
    print2d(arr, rows, cols);

    for (int i = 0; i < rows; ++i) {
        delete[] arr[i];
    }
    delete[] arr;

    */


    /* Task 3 

    int rows = 6;
    int cols = 4;

    int** arr = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        arr[i] = new int[cols];
        fillArr(arr[i], cols, 0, 20);
    }

    cout << endl;
    print2d(arr, rows, cols);

    addrandRow(arr, rows, cols, 2);

    cout << endl;
    print2d(arr, rows, cols);

    for (int i = 0; i < rows; ++i) {
        delete[] arr[i];
    }
    delete[] arr;

    */



    /* Task 4 

    int rows = 6;
    int cols = 4;

    int** arr = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        arr[i] = new int[cols];
        fillArr(arr[i], cols, 0, 9);
    }
    cout << endl;
    print2d(arr, rows, cols);

    removeZeroRows(arr, rows, cols);
    cout << "New Array without zero: \n" << endl;
    print2d(arr, rows, cols);

    for (int i = 0; i < rows; ++i) {
        delete[] arr[i];
    }
    delete[] arr;

    */



    /* Task 5 

    int rows, cols;
    cout << "Enter rows and cols: ";
    cin >> rows >> cols;

    int** A = create2d(rows, cols, true);    
    int** B = create2d(rows, cols, true);    
    int** C = create2d(rows, cols, false);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    cout << "A: " << endl;   
    print2d(A, rows, cols);
    cout << "B: " << endl;   
    print2d(B, rows, cols);
    cout << "A + B: " << endl; 
    print2d(C, rows, cols);

    delete2d(A, rows);
    delete2d(B, rows);
    delete2d(C, rows);

    */


    /* Task 6 

    int G, H, I;
    cout << "A size (G * H): ";
    cin >> G >> H;
    cout << "B size: " << H << " * I, enter I: ";
    cin >> I;

    int** A = create2d(G, H, true);
    int** B = create2d(H, I, true);

    int** C = multiply(A, B, G, H, I);

    cout << "A: " << endl;
    print2d(A, G, H);
    cout << "B: " << endl;
    print2d(B, H, I);
    cout << "A * B: " << endl;
    print2d(C, G, I);

    delete2d(A, G);
    delete2d(B, H);
    delete2d(C, G);

    */

    /* Task 7 */

    int size;
    cout << "Enter array size: ";
    cin >> size;

    int* arr = new int[size];
    fillArr(arr, size, 0, 20);

    cout << "Array: ";
    printArr(arr, size);
    cout << endl;

    printRows(size);

    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;

    int** arr2d = change2d(arr, size, rows, cols);

    if (arr2d != nullptr) {
        cout << "2D array " << rows << " x " << cols << ":" << endl;
        print2d(arr2d, rows, cols);
        delete2d(arr2d, rows);
    }

    delete[] arr;





}

