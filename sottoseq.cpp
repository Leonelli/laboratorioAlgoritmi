#include <fstream>
#include <vector>
#include <iostream>
#include <numeric>      
using namespace std;


int MaxSubarraySum(int vettore[], int n){
    if(n == 1){
        return vettore[0];
    }
    int m = n/2;
    int left_MSS = MaxSubarraySum(vettore,m);
    int right_MSS = MaxSubarraySum(vettore+m,n-m);
    int leftsum = 0, rightsum=0,sum=0;

    for(int i = m; i <n;i++){
        sum+=vettore[i];
        rightsum = max(rightsum,sum);
    }
    sum = 0;
    for(int i = (m-1); i >= 0; i--){
        sum+=vettore[i];
        leftsum = max(leftsum,sum);
    }
    int ans = max(left_MSS,right_MSS);
    return max(ans,leftsum+rightsum);
    
}





int main(){
    int valore;
    int max_global;
    ifstream infile("input.txt");
    int N; 
    infile >> N;
    int vettore[N];


    for(int i = 0; i<N; i++)
    { 
        infile >> valore;
        vettore[i]=valore;
    } 

    max_global = MaxSubarraySum(vettore,N); 

    ofstream out("output.txt");
    out<<max_global<<endl;
    cout << max_global<<endl;
    //cout << max(arraySum(vettore),25)<<endl;
    //cout << arraySum(vettore)<<endl; 
    return 0;
}

