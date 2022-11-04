#include <iostream>
using namespace std;

int main(){
    int n = 5;
    for (int i = 1; i <= n-1; i++){
        cout << "i : " << i << endl;
        for (int j = i+1; j <= n; j++){
            cout << "jota: " << j << endl;
        }
    }
}