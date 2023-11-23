/*Вариант 11
Дана матрица размера M × N и
целое число K (1 ≤ K ≤ M ).
Удалить строку матрицы с номером K.
*/
#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	int strm, stn, k;

	cout << "Введите размер матрицы m x n (m и n не больше 10)" << endl;
	cin >> strm >> stn;
	cout << "Введите целое число K (1 <= K <= M )" << endl;
	cin >> k;
	if ((k < 1) && (k > strm)) {
		cerr << "Ошибка: k не соответствует условию!!!" << endl;
		return 1;
	}

	int** arr = new int * [strm];
	for (int i = 0; i < stn; i++) {
		arr[i] = new int[stn];
	}
	for (size_t i = 0; i < strm; i++) {
		for (size_t j = 0; j < stn; j++) {
			cout << "Введите элемент: ";
			cin >> arr[i][j];
		}
	}

	for (size_t i = k-1; i < strm-1; i++) {
		for (size_t j = 0; j < stn; j++) {
			arr[i][j] = arr[i+1][j];
	    }
	}
	strm--;

	for (size_t i = 0; i < strm; i++) {
		for (size_t j = 0; j < stn; j++) {
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}

	for (size_t i = 0; i < stn; i++) {
		delete[] arr[i];
	}
	delete[] arr;

	cout << endl;
	return 0;
}