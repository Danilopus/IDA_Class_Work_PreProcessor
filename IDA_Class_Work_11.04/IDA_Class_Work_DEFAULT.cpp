﻿#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>
#include <algorithm>
//#include <array>

#include "Header_1.h"

#define _PI 3.14

#define Forever for(int _i=0;;_i++)

#define begin {
#define end   }

#define sum(a,b) a+b
 
#define arr_cout(arr, size) std::cout << "[";\
for (int i = 0; i<size;i++)\
std::cout <<arr[i]<<" | ";\
std::cout << "\b\b]\n"

// Conditional compilation. Works with integer values ONLY
#if 5<4

#define var 666

#elif 5==4

#define var 0

#else
// # - transform to std::string
#define show(p) std::cout << #p <<"\n"
#define var(name) std::cout <<#name<< " = "<< name <<"\n"

#endif

#ifdef _PI

void func(){}

#endif

#ifndef PI

void func2() {}

#endif

// ## code concatenation
#define concat(a,b) a ## b


// Service functions prototypes ------------------------------------
int Get_Int_SA();			// String-analysis вариант фильтра INTEGER
int Get_Int_Positive();		// String-Analysis вариант проверки ввода INTEGER_POSITIVE		
int Get_Int_PG();			// peek&get вариант проверки ввода INTEGER	
double Get_Dbl_SA();		// String-analysis вариант фильтра DOUBLE.
double Get_Dbl_Positive();	// String-analysis вариант фильтра DOUBLE_POSITIVE
double Get_Dbl_PG();		// peek&get вариант проверки ввода DOUBLE	
int Get_Random(int Range_min, int Range_max);
double Get_Random(double Range_min, double Range_max);
template <typename ANY> void Fill_Array_with_Random(ANY arr[], int Size, ANY Range_min, ANY Range_max);
template <typename ANY> void Array_Console_Out(ANY arr[], int Size);

// Class Work 11.04.2023 -------------------------------------------	

// Проепроцессор - это программа, которая производит некоторые, а иногда весьма значительные манипуляции с текстом программы, перед тем как она подвергается компиляции
// Preprocessor - this is a program that produces some, and sometimes very significant manipulations with the text of the program, before it undergoes compilation

// Директива препроцессора - комманда, указывающая на то, как именно должен быть изменен исходный текст программы
// The preprocessor directive is a command that indicates how the output text of the program should be changed

// #define - заменяет имя на значение после обработки препроцессором

//Task 1. Preprocessor objects. Intro
void Task_1()
{
	std::cout <<"\n" << "Pi = " << _PI;
	Forever 
	begin
		std::cout << "|";
		if (_i > 2e3) break;
	end
	//_PI=8; // Error
}

//Task 2. Preprocessor macroses
void Task_2()
{	
	std::cout << "\n" << "Entrada dos numeros\n";
	int n = Get_Int_SA();
	int m = Get_Int_SA();
	std::cout << "\n" << n << " + " << m <<" = "<< sum(n, m);

	int const Size = 5;
	int arr[Size] = { 0,10,15,25 };
	std::cout << "\n\n" << "Array: "; 
	arr_cout(arr, Size);
}

// Task_3. Preprocessor operators: #, 
void Task_3()
{
	show(i loved C++);
	int n = 10;
	var(n);

	double tmp = 1.555;
	std::cout << "tmp = " << concat(t, mp) << "\n";
}

// Task_4
void Task_4()
{
	std::cout << "\n" << _PI;

#undef _PI

//	std::cout << _PI; //Error: _PI is alredy undefined

#define _PI 222

	std::cout<<"\n" << _PI;

}
#undef _PI

//Task_5. Сonditional compilation
void Task_5()
{
	std::cout << "Task_4";
	return;
}



// MAIN ------- MAIN ------- MAIN ------- MAIN ------- MAIN --------
int main()
{
srand(time(NULL));
		
//Task_1();
 //Task_2();
//Task_3();
//Task_4();
Task_5();




std::cout << "\n\n";
system("pause");	
}

// Service functions -----------------------------------------
int Get_Int_SA() {
	std::string a;
	std::cin.sync(); 
	std::cin.clear(); 
	getline(std::cin, a);
	if (a != "")
	{

		if ((a.find_first_not_of("-0123456789") == -1))
		{
			for (int i = 1; i < a.size(); i++) // определяем есть ли минусы кроме первого символа
			{
				if (a[i] == '-') 
				{
					std::cout << "Input Error: Minus misstanding. [INTEGER] expected.\n";
					return Get_Int_SA();
				}
			}
			try
			{
				return stoi(a);
			}
			catch (std::out_of_range)
			{
				std::cout << "Input Error: Data type overflow. [INTEGER] expected.\n";
				return Get_Int_SA();
			}


		}
		else
		{
			std::cout << "Input Error: Incorrect symbol. [INTEGER] expected.\n";
			return Get_Int_SA();
		}
	}
	else
	{
		std::cout << "Input Error: NULL input. [INTEGER] expected.\n";
		return Get_Int_SA();
	}
}
int Get_Int_Positive()
{
	std::string a;
	std::cin.sync();
	std::cin.clear();
	getline(std::cin, a);
	if (a != "") 
	{

		if ((a.find_first_not_of("0123456789") == -1))
		{
			try{
				return stoi(a);
			}
			catch (std::out_of_range){
				std::cout << "Input Error: overflow. Positive [INTEGER] expected.\n";
			}
		}
		else
		{
			std::cout << "Input Error: Positive [INTEGER] expected.\n";
			return Get_Int_Positive();
		}		
	}
	else
		std::cout << "Input Error: NULL input. Positive [INTEGER] expected.\n";
	return Get_Int_Positive();
}
int Get_Int_PG()
{
	int a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n'))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Input error! [INTEGER] expected. Repeat please...\n";
	}
	return a;
}
double Get_Dbl_SA(){
	std::string a;
	std::cin.sync();
	getline(std::cin, a);
	if (a == "") { std::cout << "\nInput Error : NULL input\n"; return Get_Dbl_SA(); }
	if ((a.find_first_not_of("-.0123456789") == -1))
	{
		for (int i = 1; i < a.size(); i++) // Проверяем отсутсвие лишних минусов
		{
			if (a[i] == '-')
			{
				std::cout << "\nInput Error: Minus misstanding. [DOUBLE] expected.\n";
				return Get_Dbl_SA();
			}

		}
		bool Dot_Flag = 0;
		for (int i = 0; i < a.size(); i++) // проверяем отсутсвие лишних точек
		{
			if (a[i] == '.')
			{
				if (Dot_Flag == 1)
				{
					std::cout << "\nInput Error: Dot misstandig. [DOUBLE] expected.\n";
					return Get_Dbl_SA();
				}
				Dot_Flag = 1;
			}

		}		 	
				try{
					return stod(a);
				}
				catch (std::out_of_range) {
					std::cout << "Input Error: overflow. [DOUBLE] expected.\n";
					return Get_Dbl_SA();					
				}						
	}
	else {		
		std::cout << "Incorrect symbols: [DOUBLE] expected.\nUse dot instead of coma. Example 50.64\n";
		return Get_Dbl_SA();
	}
}
double Get_Dbl_Positive(){
	std::string a, dot = ".";
	std::cin.sync();
	std::cin.clear();
	getline(std::cin, a);
	if (a != "")
	{
		if ((a.find_first_not_of(".0123456789") == -1))
		{
			bool One_Dot_already = false;
			for (int i = 0; i < a.size(); i++)
			{				
				if (a[i] == dot[0] && One_Dot_already == true) //проверяем количество разделителей
				{
					std::cout << "Input Error: Dot misstandig. Positive [DOUBLE] expected.\n";
					return Get_Dbl_Positive();
				}
				if (a[i] == dot[0])	One_Dot_already = true;
			}
			try
			{				
				return stod(a);
			}
			catch (std::out_of_range)
			{
				std::cout << "Input Error: Data type overflow. Positive [DOUBLE] expected.\n";
				return Get_Dbl_Positive();
			}
		}
		else
		{
			//std::cout << "Incorrect symbols: positive REAL expected.\nUse coma instead of dot. Example 50,64\n"; // да точно говорю вот даже сообщение такое было, а теперь наоборот wtf*2?!
			std::cout << "Incorrect symbols: Positive [DOUBLE] expected.\nUse dot instead of coma. Example 50.64\n";
			return Get_Dbl_Positive();
		}
	}
	else
	{
		std::cout << "Input Error: NULL input. Positive [DOUBLE] expected.\n";
		return Get_Dbl_Positive();
	}
	return Get_Dbl_Positive();
}
double Get_Dbl_PG()
{
	double a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n'))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Input error! [DOUBLE] expected. Repeat please...\n";
	}
	return a;
}
int Get_Random(int Range_min=-999, int Range_max=999)
{
	if (Range_min > Range_max) 
	{ 
		std::cout << "\nError: Range_min > Range_max. New range: [Range_max..Range_min]\n";
		std::swap(Range_min, Range_max);
	}
	//return (Range_min + rand() % (Range_max - Range_min + 1));
	double K_random = double((rand() % RAND_MAX)) / RAND_MAX;
	int random = Range_min + ((Range_max - Range_min) * K_random);
	//return Range_min + (Range_max - Range_min) * (rand() % RAND_MAX) / RAND_MAX;
	return random;
}
double Get_Random(double Range_min=-9999.0, double Range_max=9999.0)
{
	if (Range_min > Range_max)
	{
		std::cout << "\nError: Range_min > Range_max. New range: [Range_max..Range_min]\n";
		std::swap(Range_min, Range_max);
	}
	return 	Range_min + (Range_max - Range_min) * double(rand() % RAND_MAX) / RAND_MAX;	
}
template <typename ANY> void Array_Console_Out(ANY arr[], int Size)
{
	std::cout << "\n[";
	for (int i = 0; i < Size; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}
template <typename ANY> void Fill_Array_with_Random(ANY arr[], int Size, ANY Range_min, ANY Range_max)
{
	for (int i = 0; i < Size; i++)
	{
		arr[i] = Get_Random(Range_min, Range_max);		
	}
}
