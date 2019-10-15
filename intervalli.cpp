#include <fstream>
#include <iostream>
using namespace std;

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


     for(int i = 0; i<N; i++)
    { 
        cout << vettore[i] << " ";
    } 
    cout << endl;
    return 0;
}







