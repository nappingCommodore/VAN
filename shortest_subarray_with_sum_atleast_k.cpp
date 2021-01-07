#include <cstdio>
#include <iostream>

#define ll long long

using namespace std;

int main(){
    int arr[10];
    int n = 10;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int sumArr[10] = {0};
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
        sumArr[i] = sum;
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            cout<<i<<" "<<j<<" "<<sumArr[i]<<" "<<sumArr[j]<<" "<<sumArr[j]-sumArr[i]<<endl;
        }
    }
}