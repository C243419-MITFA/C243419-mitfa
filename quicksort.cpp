#include <iostream>
using namespace std;

void quickSort(int a[], int l, int r){
    if(l>=r) return;

    int pivot = a[r];
    int i = l;

    for(int j=l;j<r;j++){
        if(a[j] < pivot){
            swap(a[i],a[j]);
            i++;
        }
    }

    swap(a[i],a[r]);

    quickSort(a,l,i-1);
    quickSort(a,i+1,r);
}

int main(){
    int n,a[100];
    cin>>n;

    for(int i=0;i<n;i++)
        cin>>a[i];

    quickSort(a,0,n-1);

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}
