#include <iostream>
#include <algorithm>

using namespace std;


int main(){

    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(int);

    rotate(arr,arr+2,arr+n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<",";
    }
    cout<<endl;

    // next_permutation : print the next bigger lexographicall number 
    next_permutation(arr,arr+n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<",";
    }

    return 0;
}

/*
Output : 

40,50,5,10,30

*/


/* 
Some other functions :


max,min,swap,reverse(arr,arr+m) -> reverse first m element of the array