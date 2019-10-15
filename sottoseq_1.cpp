#include <fstream>
#include <vector>
#include <iostream>
#include <numeric>      
using namespace std;

int main(){
    int valore;
    vector<int> vettore;
    ifstream infile("input2.txt");
    
    infile >> valore;
    while(infile >> valore)
    { 
        vettore.push_back(valore);
        cout << valore << endl;
    } 

    int max_current=0;
    int max_global=0;

    for (int i = 0; i < vettore.size(); ++i)
    {
       if((max_current + vettore[i])>0)
       {
           max_current+=vettore[i];
       }
       else{
           max_current=0;
       }
       max_global=max(max_current,max_global);
    }
    cout << "MAX: "<<max_global << endl;

    ofstream out("output.txt");
    out<<max_global<<endl;
    //cout << max(arraySum(vettore),25)<<endl;
    //cout << arraySum(vettore)<<endl; 
    return 0;
}

