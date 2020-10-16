#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    int arr[] = {10,20,30,30,30,40,50};
    int n = sizeof(arr)/sizeof(int);

    int key = 20;
    bool present = binary_search(arr,arr+n,key);
    if(present){
        cout<<"Present";
    }
    else{
        cout<<"Not Present";
    }
    cout<<endl;
    
    auto lb = lower_bound(arr,arr+n,30);
    cout<<"Lower Bound"<<lb-arr<<endl;

    auto ub = upper_bound(arr,arr+n,30);
    cout<<"Upper Bound"<<ub-arr<<endl;

    //Occurence of any number in sorted array

    cout<<"Occurence : "<<ub-lb<<endl;

    return 0;
}