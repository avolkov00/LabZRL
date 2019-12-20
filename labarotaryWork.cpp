#include <iostream>
using namespace std;

int globalValue;
void coutValues() {
	// Вывод адресов статической,динамической и глобальной переменной
	int staticValue;
	int* dynamicValue = new int;
	cout << &staticValue << " Static value" << '\n'
		<< dynamicValue << " Dynamic value " << '\n'
		<< &globalValue << " Global value " << '\n';
	delete dynamicValue;
}

const int sizeOfArray = 6;

void coutArray(int* Array) {
	for (int i = 0; i < sizeOfArray; i++) {
		cout << &Array[i] << "[" << i << "]" << endl;
	}
}
void coutArrays() {
	//Вывод адресов статического массива
	int staticArray[sizeOfArray];
	cout << &staticArray << " Static Array" << endl;
	coutArray(staticArray);

	//Вывод адресов динамического массива
	int* dynamicArray = new int[sizeOfArray];
	cout << dynamicArray << " Dynamic Array" << endl;
	coutArray(dynamicArray);
	delete[] dynamicArray;
}

const int sizeOfArray1 = 2, sizeOfArray2 = 3;
void coutMultidimensionalArrays() {
	//Вывод адресов многомерного статического массива
	int multidimensionalStaticArray[sizeOfArray1][sizeOfArray2];
	cout << &multidimensionalStaticArray << " Multidimensional Static Array" << endl;
	for (int i = 0; i < sizeOfArray1; i++) {
		for (int j = 0; j < sizeOfArray2; j++) {
			cout << &multidimensionalStaticArray[i][j] << "[" << i << "][" << j << "]" << endl;
		}
	}

	//Вывод адресов многомерного динамического массива
	int** multidimensionalDynamicArray = new int* [sizeOfArray1];
	for (int i = 0; i < sizeOfArray1; i++) {
		multidimensionalDynamicArray[i] = new int[sizeOfArray2];
	}
	cout << multidimensionalDynamicArray << " Multidimensional Dynamic Array" << endl;
	for (int i = 0; i < sizeOfArray1; i++) {
		//cout << multidimensionalDynamicArray[i] << " Multidimensional Dynamic Array [" << i << "]" << endl;
		for (int j = 0; j < sizeOfArray2; j++) {
			cout << &multidimensionalDynamicArray[i][j] << "[" << i << "][" << j << "]" << endl;
		}
	}
	for (int i = 0; i < sizeOfArray1; i++) {
		delete[] multidimensionalDynamicArray[i];
	}
	delete[] multidimensionalDynamicArray;
}

struct structWithAligment1
{
	char ch;
	int id;
	short opt;
	int value;
};

struct structWithAligment2
{
	char ch;
	short opt;
	int id;
	int value;
};

#pragma pack(push, 1)
struct structWithoutAligment
{
	char ch;
	short opt;
	int id;
	int value;
};
#pragma pack(pop)
void coutStructs() {
	//Вывод адресов и размеров различных структур
	structWithAligment1 withAligment1;
	cout << &withAligment1 << " " << sizeof(withAligment1) << endl
		<< (void*)&withAligment1.ch << " " << sizeof(withAligment1.ch) << endl
		<< &withAligment1.id << " " << sizeof(withAligment1.id) << endl
		<< &withAligment1.opt << " " << sizeof(withAligment1.opt) << endl
		<< &withAligment1.value << " " << sizeof(withAligment1.value) << endl
		<< sizeof(withAligment1.ch) + sizeof(withAligment1.id) + sizeof(withAligment1.opt) + sizeof(withAligment1.value) << " " << sizeof(withAligment1) << endl;

	structWithAligment2 withAligment2;
	cout << &withAligment2 << " " << sizeof(withAligment2) << endl
		<< (void*)&withAligment2.ch << " " << sizeof(withAligment2.ch) << endl
		<< &withAligment2.opt << " " << sizeof(withAligment2.opt) << endl
		<< &withAligment2.id << " " << sizeof(withAligment2.id) << endl
		<< &withAligment2.value << " " << sizeof(withAligment2.value) << endl
		<< sizeof(withAligment2.ch) + sizeof(withAligment2.id) + sizeof(withAligment2.opt) + sizeof(withAligment2.value) << " " << sizeof(withAligment2) << endl;

	structWithoutAligment withoutAligment;
	cout << &withoutAligment << " " << sizeof(withoutAligment) << endl
		<< (void*)&withoutAligment.ch << " " << sizeof(withoutAligment.ch) << endl
		<< &withoutAligment.opt << " " << sizeof(withoutAligment.opt) << endl
		<< &withoutAligment.id << " " << sizeof(withoutAligment.id) << endl
		<< &withoutAligment.value << " " << sizeof(withoutAligment.value) << endl
		<< sizeof(withoutAligment.ch) + sizeof(withoutAligment.id) + sizeof(withoutAligment.opt) + sizeof(withoutAligment.value) << " " << sizeof(withoutAligment) << endl;

}

int main()
{
	coutValues();
	coutArrays();
	coutMultidimensionalArrays();
	coutStructs();
}
