#include<iostream>
using namespace std;

int main()
{
    int n, i, search;

    cout<<"Enter size: ";
    cin>>n;

    int arr[n];

    cout<<"Enter sorted elements: ";
    for(i=0;i<n;i++)
    cin>>arr[i];

    cout<<"Enter number to search: ";
    cin>>search;

    int left=0, right=n-1, mid;

    while(left<=right)
    {
        mid=(left+right)/2;

        if(arr[mid]==search)
        {
            cout<<"Found at position "<<mid+1;
            return 0;
        }
        else if(search<arr[mid])
        right=mid-1;

        else
        left=mid+1;
    }

    cout<<"Not Found";

    return 0;
}
