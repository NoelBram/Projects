/*
	Description:
	Created: 07/01/20
    Modified: 07/03/20
    Completed: 

*/
#include "brambila.h"

void bubbleSort (vector<int> & v, int n){
	for (int i = n - 1; i > 0; i--){
		for (int j = 0; j < i; j++){
			if (v[j] > v[j + 1]){
				swap(v[j], v[j + 1]);
			}	
		}
	}
}

int main(){
	int start, finish;
	srand (time(NULL)); // generating some randome number
	vector<int> v;
	int n = 0;

	cout << "Enter size of input :" ;
	cin >> n;
	
	for (int i=0; i<n; i++){
		v.push_back(rand());
	}

	start=clock();
	
    bubbleSort(v, n);
	
	finish =clock();
	cout << "time= " << finish-start << endl;


	return 0;
}