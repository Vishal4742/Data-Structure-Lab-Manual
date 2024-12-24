#include<iostream>
using namespace std;
int main(){

    int m, n, i, j;
    cout<<"Enter the number of rows:";
    cin>>m;
    cout<<"Enter the number of columns:";
    cin>>n;

    int matrix_a[m][n], matrix_b[m][n],  sum_matrix[m][n];

    cout<<"Enter the elements of Matrix_1:"<<endl;
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            cout<<"Enter Elements of a"<<i+1<<j+1<<":";
            cin>>matrix_a[i][j];
        }
    }
    cout<<"Enter the elements of Matrix_2:"<<endl;
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            cout<<"Enter Elements of b"<<i+1<<j+1<<":";
            cin>>matrix_b[i][j];
        }
    }
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            sum_matrix[i][j]=matrix_a[i][j]+matrix_b[i][j];
        }
    }

    cout<<"Sum of martix_a and matrix_b is "<<endl;
    for(i=0;  i<m; i++){
        for(j=0; j<n; j++){
            cout<<sum_matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
