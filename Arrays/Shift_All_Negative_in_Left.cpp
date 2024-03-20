#include<iostream>
using namespace std;

void shiftNegativeOneSide(int arr[], int n){
    int j = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] < 0){
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

int main(){
    int arr[] = {23,-7,12,-10,-11,40,60};
    int n = 7;
    shiftNegativeOneSide(arr, n);
    cout << "Printing the Array" << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}