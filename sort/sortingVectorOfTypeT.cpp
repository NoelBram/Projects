/*	Description:
	This Vector of type T is sorted with Selection Sort
	Created: 7/01/20
    Modified: 08/03/20
    Completed: 
*/
#include "brambila.h"

template<typename T> // like auto, universal type ... T is commonly used
					// every funtion that follows uses the template thing
class universalVector {
	public:
		universalVector(); // constructor 
		universalVector(vector<T> STL); // constructor with a vector type T as a peramiter 
		void sortLargestToSmallest(vector<T> & STL);
		T back();
		T front();
		void push(T entry);
		void pop();
		void print();
		int size();
		void mpush(int x);			
		void mpop();
	private:
		int verticies;                  // Number of vertices 
        list<int> *adj;                 // Pointer to an array containing adjacency lists 
		vector<T> STL;	
};

template<typename T>
universalVector<T>::universalVector(){
	universalVector<T>::STL = NULL;
}

template<typename T>
universalVector<T>::universalVector(vector<T> STL1){
	sortLargestToSmallest(STL1);
	STL = STL1;
}

template<typename T>
void universalVector<T>::sortLargestToSmallest(vector<T> & STL){	// Selection Sort, Largest to smallest 
	int n = STL.size();
	for (int i = 0; i < n-1; i++){ 	
		for (int j = i+1; j < n; j++){
			if (STL[i] > STL[j]){
				swap(STL[i], STL[j]);
			}
		}
	}	
}

template<typename T>
T universalVector<T>::front(){ 
        return STL[0];
}

template<typename T>
T universalVector<T>::back(){ 
	return STL[STL.size() - 1];
}

template<typename T>
void universalVector<T>::push(T entry){
	STL.push_back(entry);
}

template<typename T>
void universalVector<T>::pop(){
	STL.pop_back();
}

template<typename T>
void universalVector<T>::print(){
	cout << " The vector is " << endl;
	for(int x: STL){	
		cout << x << " " << endl;
	}
}

template<typename T>
int universalVector<T>::size(){
	return STL.size();
}

template<typename T>
void universalVector<T>::mpush(int x){
	STL.push_back(x);
	sort(STL);
}

template<typename T>
void universalVector<T>::mpop(){
	STL.erase(STL.begin());
}

int main(){	
	vector<int> x;
	x.push_back(7);
	x.push_back(2);
	x.push_back(10);
	x.push_back(3);
	x.push_back(9);
	x.push_back(1);
	
	universalVector<int> myuniversalVector(x);
	
	myuniversalVector.push(34);	

	cout << " The Size of the Vector is " << myuniversalVector.size() << endl;	
	cout << " The Front of the Vector is " << myuniversalVector.front() << endl;
	myuniversalVector.mpush(5);
	myuniversalVector.print();
	myuniversalVector.mpop();
	myuniversalVector.print();
	return 0;
}
		
