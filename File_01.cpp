//Program to input marks of 5 subjects and print the total and percentage using arrays 

#include <iostream>
using namespace std;

void enterMarks(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Enter your marks for Student " << i + 1 << ": ";
        cin >> arr[i];
    }
}

int calculateSum(int arr[], int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

void calculateAverage(float sum, int n) {

        float average = sum / n;
        cout << "The average is: " << average << endl;
}

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    int arr[n];

    enterMarks(arr, n);
    int sum = calculateSum(arr, n);
    calculateAverage(sum, n);

    return 0;
}
