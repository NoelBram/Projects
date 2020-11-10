/*	Description:
	Course: Data Structures
	Created: 10/03/19
    Modified: 07/03/20
    Completed: 
*/
#include "brambila.h"

void selectionSort (vector<int> & v, int n){
	for (int i = 0; i < n - 1; i++){
		for (int j = i + 1; j < n; j++){       
			if (v[i] > v[j]){           
				swap(v[i], v[j]);       
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
	
    selectionSort(v, n);
	
	finish =clock();
	cout << "time= " << finish-start << endl;


	return 0;
}