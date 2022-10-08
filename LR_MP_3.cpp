#include <iostream>
#include <string>
#include <vector>

using namespace std;

int input_check()
{
	/*
	Функция, проверяет, являются ли введенные пользователем данные числом

	Если фукнция stod не срабатывает ИЛИ to_string обрезает ввод, то выводит ошибку

	Возвращает:
		number: double  число, переведенное из input: string, которое ввел пользователь
	*/
	string input;
	bool ok = true;
	int number = 0;

	while (ok)
	{
		getline(cin, input);
		try
		{
			number = stoi(input);
			if (to_string(number).length() != input.length())
			{
				throw (1);
			}
			return number;
		}
		catch (invalid_argument)
		{
			cerr << "Error! Write an integer number!" << endl;
		}
		catch (int i)
		{
			cerr << "Error! Write an integer number!" << endl;
		}
	}
}



vector <int> individual_record(int count)
{
	vector <int> array;

	cout << "You chose individual input" << endl;
	for (int i = 0; i < count; ++i)
	{
		cout << "\n Input #" << i + 1 << " element of sequence: ";
		int number = input_check();
		array.push_back(number);
	}
	return array;
}

vector <int> random_record(int count)
{
	vector <int> array;

	cout << "You chose random input" << endl;
	for (int i = 0; i < count; ++i)
	{
		int number = rand () % 10;
		array.push_back(number);
	}
	return array;
}

vector <int> sorting_elements(vector <int> array)
{
	for (int i = 0; i < (array.size()-1); ++i)
	{
		for (int j = i; j < array.size(); ++j)
		{
			if (array[i] > array[j])
			{
				int minc = array[j];
				array[j] = array[i];
				array[i] = minc;
			}
		}
	}
	return array;
}

int YN_function()
{
	string button;
	int end = 0;
	while (end == 0) 
	{
		getline(cin, button);
		if (button[0] == 'Y' && button.length() == 1) return  2; //продолжаем работу программы или вводим вручную
		if (button[0] == 'N' && button.length() == 1)  return 1;//переключаем тумблер при "N" или вводим случайные числа
		if (end == 0) cout << "Write 'Y' or 'N'!" << endl;
	}
}

void output(vector <int> array)
{
	for (int i = 0; i < array.size(); ++i)
		cout << array[i] << "|";
}

int main()
{
	int end = 2;
	while (end == 2)
	{
		cout << "Enter length of your sequence. It must be >3: ";
		int count = 0;
		while (count < 4)
		{
			count = input_check();
			cout << "Number is too low! Try again" << endl;
		}

		if (count > 20)
		{
			cout << "Number is too big. Programm will show first 20 elements" << endl;
			count = 20;
		}

		cout << "Do you want to input elements by yourself?"
			<< " (Write 'Y' to do it OR 'N' to make it random)" << endl;

		int decision = YN_function();

		vector <int> data;
		vector <int> sorted;


		if (decision == 1)
			data = random_record(count);

		if (decision == 2)
			data = individual_record(count);

		sorted = sorting_elements(data);


		cout << '\n' << "Vector before sorting: " << endl;
		output(data);
		cout << '\n' << "Vector after sorting : " << endl;
		output(sorted);
		
		cout << '\n' << "Do you want to continue? Input 'Y' or 'N'" << endl;
		end = YN_function();
	}
}
