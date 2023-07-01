#include<iostream>
#include<cstdlib>
#include<ctime>

//Задача1.
void type(int num) {std::cout << "INT\n";}
void type(double num) {std::cout << "DOUBLE\n";}
void type(char num) { std::cout << "CHAR\n"; }

//Задача2.
int sum_AB(int A, int B) {
	if (A == B)
		return A;//выход из рекурсии
	return sum_AB(A, B - 1) + B;//вызов функцией самой себя
}


//Задача3.
template<typename T>
void fill_arr(T arr[], const int length, int left, int right) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (right - left) + left;
}
template<typename T>
void print_arr(T arr[], const int length) {
	std::cout << "{ ";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }"<<std::endl;
}
template<typename T>
void middle_sort(T arr[], const int length);

//Задача 4.
template<typename T>
void move_arr(T arr[], const int length, int steps);

int main() {
	system("chcp 1251>nul");
	int n, m;
	//Задача 1. Тип данных
	/*std::cout << "Задача 1.\n";
	type(10);//INT
	type(5.5);//DOUBLE
	type('k');//CHAR
	std::cout << std::endl;*/

	//Задача 2.Рекурсия диапазона от А до B
	/*std::cout << "Задача 2.\nВведите два числа ->\n";
	std::cin >> n >> m;
	std::cout << "Сумма чисел от " << n << " до " << m << " = " << sum_AB(n, m) << "\n\n";*/

	//Задача 3. Массивы - сортировка середины
	/*std::cout << "Задача 3. \n Изначальный массив.\n";
	const int size3 = 15;
	int arr3[size3];
	fill_arr(arr3, size3, -20, 21);
	print_arr(arr3, size3);
	middle_sort(arr3, size3);
	std::cout << "Итоговый массив:\n";
	print_arr(arr3, size3);
	std::cout << std::endl;*/

	//Задача 4. Циклический сдвиг массива
	std::cout << "Задача 4. \n Изначальный массив:\n";
	const int size4 = 10;
	int arr4[size4]{1,2,3,4,5,6,7,8,9,10};
	print_arr(arr4, size4);
	std::cout << "Введите показатель сдвига ->";
	std::cin >> n;
	move_arr(arr4, size4, n);
	std::cout << "Итоговый массив:\n";
	print_arr(arr4, size4);



	return 0;
}

//Задача3.
template<typename T>
void middle_sort(T arr[], const int length) {
	int first_negative = 0, last_negative = 0;

	//линейный поиск первого отрицательного элемента
	for(int i = 0; i<length; i++)
		if (arr[i] < 0) {
			first_negative = i;
			break;//остановка цикла
		}

	//линейный поиск последнего отрицательного элемента
	for(int i = length - 1; i>=0; i--)
		if (arr[i] < 0) {
			last_negative = i;
			break;//остановка цикла
		}

	//пузырьковая сортировка элементов с индексами от 
	//first_negative + 1 до last_negative - 1
	for (int i = last_negative - 1; i > first_negative + 1; i--)
		for (int j = first_negative + 1; j < i; j++)
			if (arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j + 1]);
}


//Задача 4.
template<typename T>
void move_arr(T arr[], const int length, int steps) {
	if (steps < 0)
		for (int j = 0; j < -steps; j++)
			for (int i = 0; i < length - 1; i++)
				std::swap(arr[i], arr[i + 1]);//swap меняет значение текущего эл-нта со значением следующего
	else
		for (int j = 0; j < steps; j++)
			for (int i = length - 1; i >= 1; i--)
				std::swap(arr[i], arr[i - 1]);//swap меняет значение текущего эл-нта со значением предыдущего
}