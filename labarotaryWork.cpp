#include <iostream>
using namespace std;

int globalValue;
void coutValues() {
	// Вывод адресов глобальной,динамической и статической переменной
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
	char symbol;
	int inText1;
	short index;
	int inText2;
};

struct structWithAligment2
{
	char symbol;
	short index;
	int inText1;
	int inText2;
};

#pragma pack(push, 1)
struct structWithoutAligment
{
	char symbol;
	short index;
	int inText1;
	int inText2;
};
#pragma pack(pop)
void coutStructs() {
	//Вывод адресов и размеров различных структур
	structWithAligment1 withAligment1;
	cout << (void*)&withAligment1.symbol  << endl
		<< &withAligment1.inText1 << endl
		<< &withAligment1.index << endl
		<< &withAligment1.inText2 << endl
		<< sizeof(withAligment1.symbol) + sizeof(withAligment1.inText1) + sizeof(withAligment1.index) + sizeof(withAligment1.inText2) << " " << sizeof(withAligment1) << endl;

	structWithAligment2 withAligment2;
	cout << (void*)&withAligment2.symbol << endl
		<< &withAligment2.index  << endl
		<< &withAligment2.inText1 << endl
		<< &withAligment2.inText2 << endl
		<< sizeof(withAligment2.symbol) + sizeof(withAligment2.inText1) + sizeof(withAligment2.index) + sizeof(withAligment2.inText2) << " " << sizeof(withAligment2) << endl;

	structWithoutAligment withoutAligment;
	cout << (void*)&withoutAligment.symbol << endl
		<< &withoutAligment.index <<  endl
		<< &withoutAligment.inText1  << endl
		<< &withoutAligment.inText2 << endl
		<< sizeof(withoutAligment.symbol) + sizeof(withoutAligment.inText1) + sizeof(withoutAligment.index) + sizeof(withoutAligment.inText2) << " " << sizeof(withoutAligment) << endl;

}

int main()
{
	coutValues();
	coutArrays();
	coutMultidimensionalArrays();
	coutStructs();
}
