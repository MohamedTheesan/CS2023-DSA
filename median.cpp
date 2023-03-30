#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

void median(int a[],int n){
    cout<<"Sorted"<<setw(3*n+1)<<"Median"<<endl;
    int i=0;
    vector<int> temp;
    while(i<n){
        temp.push_back(a[i]);
        sort(temp.begin(), temp.end());
        double median;
        int n1 = temp.size();
        if(n1%2 == 1){
            median = temp[n1/2];
        }
        else{
            median = (temp[n1/2]+temp[n1/2-1])/2.0;
        }
        cout << "[" + to_string(temp[0]);
        for (int j = 1; j < n1; ++j) {
            cout << ", " + to_string(temp[j]);
        }
        cout << "]" << setw(3*(n+1)-i*3)<< fixed << setprecision(1) << median << endl;

        i++;
    }


}

int main()
{
    int arr[] = {7,3,5,1,6,8,2,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    median(arr,n);
    return 0;
}
