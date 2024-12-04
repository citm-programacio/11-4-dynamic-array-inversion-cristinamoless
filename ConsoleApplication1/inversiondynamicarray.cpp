#include <iostream>
using namespace std;

class darray {
private:
	int size = 0;
	int capacity;
	int* array;
public:
	darray() {
		capacity = 3;
		array = new int[capacity];
	}
	~darray() {
		delete[] array;
	}

	bool add(int num, int position) {
		if (capacity <= size) {
			capacity *= 2;
		}
		int* narray = new int[capacity];

		for (int i = 0; i < position; i++) {
			narray[i] = array[i];
		}
		narray[position] = num;
		for (int i = position; i < size; i++) {
			narray[i + 1] = array[i];
		}
		size++;
		delete[] array;
		array = narray;
		return true;
	}

	bool remove() {
		size--;
		int* narray = new int[size];
		for (int i = 0; i < size; i++) {
			narray[i] = array[i];
		}
		delete[] array;
		array = narray;
		return true;
	}
	void invert() {
		int* narray = new int[capacity];
		int j = 0;
		for (int i = size; i >= 0; i--) {
			narray[j] = array[i - 1];
			j++;
		}

		delete[] array;
		array = narray;
	}

	void print() {
		for (int i = 0; i < size; i++) {
			cout << array[i] << ", ";
		}
		cout << endl;
	}
};


int main()
{
	darray d;
	d.add(4, 0);
	d.print();
	d.add(1, 0);
	d.print();
	d.add(7, 1);
	d.print();
	d.invert();
	d.print();
	d.add(9, 1);
	d.print();
	d.add(5, 0);
	d.print();
	d.remove();
	d.print();
	
}
