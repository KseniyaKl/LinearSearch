//Линейный поиск элемента в массиве
#include <iostream>
using namespace std;

//Вывод массива на экран
template <typename T>
void show_arr(T arr[], const int length) {
	cout << "[";
	for (int i = 0; i < length; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}

//Поиск первого вхождения
template <typename T>
int search_index(T arr[], const int length, T value, int begin = 0) {
	for (int i = begin; i < length; i++)
		if (arr[i] == value)
			return i;
	return -1; // элемент не обнаружен
}

//Последнее вхождение
template <typename T>
int search_last_index(T arr[], const int length, T value) {
	for (int i = length - 1; i >= 0; i--) {
		if (arr[i] == value)
			return i;
	}
	return -1;
}
template <typename T>
int search_last_index(T arr[], const int length, T value, int begin) {
	for (int i = begin - 1; i >= 0; i--) {
		if (arr[i] == value)
			return i;
	}
	return -1;
}

//Вывод подслова
void subWord(char arr[], const int length, char sym) {
	int index = search_index(arr, length,sym);
	if (index == -1)
		cout << "ERROR\n";
	else {
		for (int i = index; i < length; i++)
			cout << arr[i];
		cout << endl;
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	//Линейный поиск
	const int size = 6;
	int arr[size]{ 4, 7, -1, 8, 7, 0 };
	cout << "Массив: \n";
	show_arr(arr, size);



	cout << "Введите число: ";
	cin >> n;
	//Поиск первого вхождения
	if (search_index(arr, size, n, 2) == -1)
		cout << "Такого числа нет в массиве.\n\n";
	else
		cout << "Позиция числа в массиве: " << search_index(arr, size, n, 2) << "\n\n";

	//Последнее вхождение
	if (search_last_index(arr, size, n, 3) == -1)
		cout << "Такого числа нет в массиве.\n\n";
	else
		cout << "Позиция последнего вхождения числа в массив: " << search_last_index(arr, size, n, 3) << "\n\n";


	//Задание "Подслово"
	const int word_size = 8;
	char word[word_size]{ 'f', 'u', 'n', 'c', 't', 'i', 'o', 'n' };
	cout << "Введите символ: ";
	char sym;
	cin >> sym;
	cout << "Подслово: ";
	subWord(word, word_size, sym);
	cout << endl;

	return 0;
}