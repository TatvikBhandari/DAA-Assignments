#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n=5;
    int arrival[]={900,910,920,1100,1120}; 
    int departure[]={940,1200,950,1130,1140};

    sort(arrival,arrival+n);
    sort(departure,departure+n);

    int plat=1,mPlat=1;
    int i = 1, j = 0;

    while(i<n && j<n){
        if(arrival[i]<=departure[j]){  
            plat++;
            mPlat=max(mPlat,plat);
            i++;
        }
        else{
            plat--;
            j++;
        }
    }
    cout<<"Minimum number of platforms :"<<mPlat;
    return 0;
}