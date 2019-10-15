#include <fstream>
#include <iostream>
using namespace std;
const int DIMMAX = 1000000;


void merge(int *Arr, int start, int mid, int end) {
	// create a temp array
	int temp[end - start + 1];

	// crawlers for both intervals and for temp
	int i = start, j = mid+1, k = 0;

	// traverse both arrays and in each iteration add smaller of both elements in temp 
	while(i <= mid && j <= end) {
		if(Arr[i] <= Arr[j]) {
			temp[k] = Arr[i];
			k += 1; i += 1;
		}
		else {
			temp[k] = Arr[j];
			k += 1; j += 1;
		}
	}

	// add elements left in the first interval 
	while(i <= mid) {
		temp[k] = Arr[i];
		k += 1; i += 1;
	}

	// add elements left in the second interval 
	while(j <= end) {
		temp[k] = Arr[j];
		k += 1; j += 1;
	}

	// copy temp to original interval
	for(i = start; i <= end; i += 1) {
		Arr[i] = temp[i - start];
	}
}


int * mymergesort(int a[], int i, int j){
    if(i>=j){
        return a;
    }
    else{
        int m = (i+j)/2;
        mymergesort(a,i,m);
        mymergesort(a,m+1,j);
        merge(a,i,m,j);
    }
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

    mymergesort(vettore,0,N-1);

     for(int i = 0; i<N; i++)
    { 
        cout << vettore[i] << " ";
    } 
    cout << endl;
    return 0;
}







