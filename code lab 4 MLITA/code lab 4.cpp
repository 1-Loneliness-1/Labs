#define _CRT_SECURE_NO_WARNINGS
#define F 500
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <sstream>
using namespace std;

int main()
{
	FILE* f;
	char answer;
	int i, n, m = 0, flag = 0;
	char e[F];
	::printf("Enter size of struct array: ");
	::cin >> n;
	i = 0;
	f = fopen("output.txt", "a");
	struct Film
	{
		char title[F];
		char surname[F];
		char name[F];
		char middlename[F];
		char country[F];
		int year;
		int cost;
		int profit;

	};
	Film* myfilm;
	myfilm = new Film[n];
	while (true)
	{
		if (m != 0)
		{
			m = n + m;
			Film* myfilm1;
			myfilm1 = new Film[m];
			for (int k = 0; k < n; k++)
			{
				myfilm1[k] = myfilm[k];
			}
			delete[] myfilm;
			myfilm = myfilm1;
			i = n;
			n = m;
		}
		//Запись значений в массив структур 
		for (i; i < n; i++)
		{
			::printf("Enter title of film for struct %d: ", i);
			::cin >> myfilm[i].title;
			::printf("Enter surname of the producer for struct %d: ", i);
			::cin >> myfilm[i].surname;
			::printf("Enter name of the producer for struct %d: ", i);
			::cin >> myfilm[i].name;
			::printf("Enter middlename of the producer for struct %d: ", i);
			::cin >> myfilm[i].middlename;
			::printf("Enter country for struct %d: ", i);
			::cin >> myfilm[i].country;
			::printf("Enter year for struct %d: ", i);
			::cin >> myfilm[i].year;
			::printf("Enter cost of film for struct %d: ", i);
			::cin >> myfilm[i].cost;
			::printf("Enter profit of film for struct %d: ", i);
			::cin >> myfilm[i].profit;
			::fprintf(f, "%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\n", myfilm[i].title, myfilm[i].surname, myfilm[i].name, myfilm[i].middlename, myfilm[i].country, myfilm[i].year, myfilm[i].cost, myfilm[i].profit);
		}

		::printf("You want add more elements?(y/n)\n");
		::cin >> answer;
		if (answer == 'y')
		{
			::printf("Enter number of new elements here: ");
			::cin >> m;
			continue;
		}
		else
			break;
	}
	//Поиск структуры, в которой содержится введенный пользователем элемент
	::printf("You want to search the structure by element?(y/n)\n");
	::cin >> answer;
	if (answer == 'y')
	{
		while (true)
		{
			::printf("Do you want search number or string?(n/s)\n");
			char choise1;
			::cin >> choise1;
			if (choise1 == 'n')
			{
				::printf("Enter number for search: ");
				int e;
				::cin >> e;
				for (i = 0; i < n; i++)
				{
					if ((myfilm[i].year == e) || (myfilm[i].cost == e) || (myfilm[i].profit == e))
					{
						::printf("Your element found in struct %d\nThis struct:\n", i);
						::printf("%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\n", myfilm[i].title, myfilm[i].surname, myfilm[i].name, myfilm[i].middlename, myfilm[i].country, myfilm[i].year, myfilm[i].cost, myfilm[i].profit);
						flag = 1;
					}

				}
			}
			else
			{
				::printf("Print string for search: ");
				char e[500];
				::cin >> e;
				for (i = 0; i < n; i++)
				{
					if ((strcmp(myfilm[i].title, e) == 0) || (strcmp(myfilm[i].surname, e) == 0) || (strcmp(myfilm[i].name, e) == 0) || (strcmp(myfilm[i].middlename, e) == 0) || (strcmp(myfilm[i].country, e) == 0))
					{
						::printf("Your element found in struct %d\nThis struct:\n", i);
						::printf("%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\n", myfilm[i].title, myfilm[i].surname, myfilm[i].name, myfilm[i].middlename, myfilm[i].country, myfilm[i].year, myfilm[i].cost, myfilm[i].profit);
						flag = 1;
					}

				}
			}
			if (flag == 0)
				::printf("Element not found.\n");
			flag = 0;
			::printf("You want to search the structure by element again?(y/n)\n");
			::cin >> answer;
			if (answer == 'y')
				continue;
			else
				break;

		}
	}
	//Упорядочение массива структур по заданному пользователем элементу
	::printf("Do you want to organize the array of structures?(y/n)\n");
	::cin >> answer;
	if (answer == 'y')
	{
		while (true)
		{
			::printf("Select sort method.(press: '1' for sorting by ascending/'2' for sorting by descending/\n'3' for sorting by alphabet(A-Z)/'4' for sorting by alphabet(Z-A)\n");
			int choise;
			::cin >> choise;
			if ((choise >= 1) && (choise <= 4))
			{
				if ((choise == 1) || (choise == 2))//Проверка на тип сортировки: по алфавиту или по числам с выдачей соответствующего набора полей для сортировки
				{
					if (choise == 1)//Выбор сортировки по возрастанию
					{
						while (true)
						{
							::printf("Select field of structure for sorting by ascending(press: '1' for sorting on the field 'year' of structure\n'2' for sorting on the field 'cost' of structure\n'3' for sorting on the field 'profit' of structure)");
							::cin >> choise;
							if ((choise >= 1) && (choise <= 3))
							{
								if (choise == 1)//Сортировка поля year по возрастанию
								{
									int j = 0;
									Film* myfilm1;
									myfilm1 = new Film[n];
									myfilm1 = myfilm;
									for (int i = 0; i < n - j;)
									{
										for (int k = 0; k < n - j - 1; k++)
										{
											if (myfilm1[k].year > myfilm1[k + 1].year)
											{
												swap(myfilm1[k], myfilm1[k + 1]);
											}
										}
										j++;
									}
									::printf("Array of structures sorted in ascending. On elements 'year'\n");
									for (i = 0; i < n; i++)
									{
										::printf("%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\n", myfilm1[i].title, myfilm1[i].surname, myfilm1[i].name, myfilm1[i].middlename, myfilm1[i].country, myfilm1[i].year, myfilm1[i].cost, myfilm1[i].profit);
									}
									myfilm1 = NULL;
								}
								if (choise == 2)//Сортировка поля cost по возрастанию
								{
									int j = 0;
									Film* myfilm1;
									myfilm1 = new Film[n];
									myfilm1 = myfilm;
									for (int i = 0; i < n - j;)
									{
										for (int k = 0; k < n - j - 1; k++)
										{
											if (myfilm1[k].cost > myfilm1[k + 1].cost)
											{
												swap(myfilm1[k], myfilm1[k + 1]);
											}
										}
										j++;
									}
									::printf("Array of structures sorted in ascending. On elements 'cost'\n");
									for (i = 0; i < n; i++)
									{
										::printf("%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\n", myfilm1[i].title, myfilm1[i].surname, myfilm1[i].name, myfilm1[i].middlename, myfilm1[i].country, myfilm1[i].year, myfilm1[i].cost, myfilm1[i].profit);
									}
									myfilm1 = NULL;
								}
								if (choise == 3)//Сортировка поля profit по возрастанию
								{
									int j = 0;
									Film* myfilm1;
									myfilm1 = new Film[n];
									myfilm1 = myfilm;
									for (int i = 0; i < n - j;)
									{
										for (int k = 0; k < n - j - 1; k++)
										{
											if (myfilm1[k].profit > myfilm1[k + 1].profit)
											{
												swap(myfilm1[k], myfilm1[k + 1]);
											}
										}
										j++;
									}
									::printf("Array of structures sorted in ascending. On elements 'profit'\n");
									for (i = 0; i < n; i++)
									{
										::printf("%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\n", myfilm1[i].title, myfilm1[i].surname, myfilm1[i].name, myfilm1[i].middlename, myfilm1[i].country, myfilm1[i].year, myfilm1[i].cost, myfilm1[i].profit);
									}
									myfilm1 = NULL;
								}
							}
							else
							{
								::printf("Please select field of structure for sorting by ascending again. Field number %d not found.", choise);
								continue;
							}
							::printf("Do you want sorting by ascending again?(y/n)\n");
							::cin >> answer;
							if (answer == 'y')
								continue;
							else
								break;

						}

					}
					else// Choise = 2 т.е. выбрана сортировка по убыванию чисел в выбранном поле структуры
					{
						while (true)
						{
							::printf("Select field of structure for sorting by descending(press: '1' for sorting on the field 'year' of structure\n'2' for sorting on the field 'cost' of structure\n'3' for sorting on the field 'profit' of structure)");
							::cin >> choise;
							if ((choise >= 1) && (choise <= 3))
							{
								if (choise == 1)//Сортировка поля year по убыванию
								{
									int j = 0;
									Film* myfilm1;
									myfilm1 = new Film[n];
									myfilm1 = myfilm;
									for (int i = 0; i < n - j;)
									{
										for (int k = 0; k < n - j - 1; k++)
										{
											if (myfilm1[k].year < myfilm1[k + 1].year)
											{
												swap(myfilm1[k], myfilm1[k + 1]);
											}
										}
										j++;
									}
									::printf("Array of structures sorted in descending. On elements 'year'\n");
									for (i = 0; i < n; i++)
									{
										::printf("%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\n", myfilm1[i].title, myfilm1[i].surname, myfilm1[i].name, myfilm1[i].middlename, myfilm1[i].country, myfilm1[i].year, myfilm1[i].cost, myfilm1[i].profit);
									}
									myfilm1 = NULL;
								}
								if (choise == 2)//Сортировка поля cost по убыванию
								{
									int j = 0;
									Film* myfilm1;
									myfilm1 = new Film[n];
									myfilm1 = myfilm;
									for (int i = 0; i < n - j;)
									{
										for (int k = 0; k < n - j - 1; k++)
										{
											if (myfilm1[k].cost < myfilm1[k + 1].cost)
											{
												swap(myfilm1[k], myfilm1[k + 1]);
											}
										}
										j++;
									}
									::printf("Array of structures sorted in descending. On elements 'cost'\n");
									for (i = 0; i < n; i++)
									{
										::printf("%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\n", myfilm1[i].title, myfilm1[i].surname, myfilm1[i].name, myfilm1[i].middlename, myfilm1[i].country, myfilm1[i].year, myfilm1[i].cost, myfilm1[i].profit);
									}
									myfilm1 = NULL;
								}
								if (choise == 3)//Сортировка поля profit по убыванию
								{
									int j = 0;
									Film* myfilm1;
									myfilm1 = new Film[n];
									myfilm1 = myfilm;
									for (int i = 0; i < n - j;)
									{
										for (int k = 0; k < n - j - 1; k++)
										{
											if (myfilm1[k].profit < myfilm1[k + 1].profit)
											{
												swap(myfilm1[k], myfilm1[k + 1]);
											}
										}
										j++;
									}
									::printf("Array of structures sorted in descending. On elements 'profit'\n");
									for (i = 0; i < n; i++)
									{
										::printf("%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\n", myfilm1[i].title, myfilm1[i].surname, myfilm1[i].name, myfilm1[i].middlename, myfilm1[i].country, myfilm1[i].year, myfilm1[i].cost, myfilm1[i].profit);
									}
									myfilm1 = NULL;
								}
							}
							else
							{
								::printf("Please select field of structure for sorting by descending again. Field number %d not found.\n", choise);
								continue;
							}
							::printf("Do you want sorting by descending again?(y/n)\n");
							::cin >> answer;
							if (answer == 'y')
								continue;
							else
								break;
						}
					}
				}
				else//Сортировка полей по алфавиту т.е. choise = 3 or 4
				{
					if (choise == 3)// Выбор сортировки по алфавиту с начала и до конца
					{
						while (true)
						{
							::printf("Select field of structure for sorting by alphabet(A-Z)(press:'1' for sorting on the field 'title' of structure\n'2' for sorting on the field 'surname' of structure\n'3' for sorting on the field 'name' of structure\n'4' for sorting on the field 'middlename' of structure\n'5' for sorting on the field 'country' of structure\n");
							::cin >> choise;
							if ((choise >= 1) && (choise <= 5))
							{
								if (choise == 1)//Сортировка поля title по алфавиту от начала до конца
								{
									int j = 0;
									Film* myfilm1;
									myfilm1 = new Film[n];
									myfilm1 = myfilm;
									for (int i = 0; i < n - j;)
									{
										for (int k = 0; k < n - j - 1; k++)
										{
											if (((int)toupper(myfilm1[k].title[0])) > ((int)toupper(myfilm1[k + 1].title[0])))
											{
												swap(myfilm1[k], myfilm1[k + 1]);
											}
										}
										j++;
									}
									::printf("Array of structures sorted by alphabet(A-Z). On elements 'title'\n");
									for (i = 0; i < n; i++)
									{
										::printf("%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\n", myfilm1[i].title, myfilm1[i].surname, myfilm1[i].name, myfilm1[i].middlename, myfilm1[i].country, myfilm1[i].year, myfilm1[i].cost, myfilm1[i].profit);
									}
									myfilm1 = NULL;
								}
								if (choise == 2)//Сортировка поля surname по алфавиту от начала до конца
								{
									int j = 0;
									Film* myfilm1;
									myfilm1 = new Film[n];
									myfilm1 = myfilm;
									for (int i = 0; i < n - j;)
									{
										for (int k = 0; k < n - j - 1; k++)
										{
											if ((int)toupper(myfilm1[k].surname[0]) > (int)toupper(myfilm1[k + 1].surname[0]))
											{
												swap(myfilm1[k], myfilm1[k + 1]);
											}
										}
										j++;
									}
									::printf("Array of structures sorted by alphabet(A-Z). On elements 'surname'\n");
									for (i = 0; i < n; i++)
									{
										::printf("%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\n", myfilm1[i].title, myfilm1[i].surname, myfilm1[i].name, myfilm1[i].middlename, myfilm1[i].country, myfilm1[i].year, myfilm1[i].cost, myfilm1[i].profit);
									}
									myfilm1 = NULL;
								}
								if (choise == 3)//Сортировка поля name по алфавиту от начала до конца
								{
									int j = 0;
									Film* myfilm1;
									myfilm1 = new Film[n];
									myfilm1 = myfilm;
									for (int i = 0; i < n - j;)
									{
										for (int k = 0; k < n - j - 1; k++)
										{
											if ((int)toupper(myfilm1[k].name[0]) > (int)toupper(myfilm1[k + 1].name[0]))
											{
												swap(myfilm1[k], myfilm1[k + 1]);
											}
										}
										j++;
									}
									::printf("Array of structures sorted by alphabet(A-Z). On elements 'name'\n");
									for (i = 0; i < n; i++)
									{
										::printf("%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\n", myfilm1[i].title, myfilm1[i].surname, myfilm1[i].name, myfilm1[i].middlename, myfilm1[i].country, myfilm1[i].year, myfilm1[i].cost, myfilm1[i].profit);
									}
									myfilm1 = NULL;
								}
								if (choise == 4)//Сортировка поля middlename по алфавиту от начала до конца
								{
									int j = 0;
									Film* myfilm1;
									myfilm1 = new Film[n];
									myfilm1 = myfilm;
									for (int i = 0; i < n - j;)
									{
										for (int k = 0; k < n - j - 1; k++)
										{
											if ((int)toupper(myfilm1[k].middlename[0]) > (int)toupper(myfilm1[k + 1].middlename[0]))
											{
												swap(myfilm1[k], myfilm1[k + 1]);
											}
										}
										j++;
									}
									::printf("Array of structures sorted by alphabet(A-Z). On elements 'middlename'\n");
									for (i = 0; i < n; i++)
									{
										::printf("%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\n", myfilm1[i].title, myfilm1[i].surname, myfilm1[i].name, myfilm1[i].middlename, myfilm1[i].country, myfilm1[i].year, myfilm1[i].cost, myfilm1[i].profit);
									}
									myfilm1 = NULL;
								}
								if (choise == 5)//Сортировка поля country по алфавиту от начала до конца
								{
									int j = 0;
									Film* myfilm1;
									myfilm1 = new Film[n];
									myfilm1 = myfilm;
									for (int i = 0; i < n - j;)
									{
										for (int k = 0; k < n - j - 1; k++)
										{
											if ((int)toupper(myfilm1[k].country[0]) > (int)toupper(myfilm1[k + 1].country[0]))
											{
												swap(myfilm1[k], myfilm1[k + 1]);
											}
										}
										j++;
									}
									::printf("Array of structures sorted by alphabet(A-Z). On elements 'country'\n");
									for (i = 0; i < n; i++)
									{
										::printf("%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\n", myfilm1[i].title, myfilm1[i].surname, myfilm1[i].name, myfilm1[i].middlename, myfilm1[i].country, myfilm1[i].year, myfilm1[i].cost, myfilm1[i].profit);
									}
									myfilm1 = NULL;
								}
							}
							else
							{
								::printf("Please select field of structure for sorting by alphabet(A-Z) again. Field number %d not found.\n", choise);
								continue;
							}
							::printf("Do you want sorting by alphabet(A-Z) again?(y/n)\n");
							::cin >> answer;
							if (answer == 'y')
								continue;
							else
								break;
						}
					}
					else//choise == '4' т.е. сортировка по алфавиту от конца до начала (Z-A)
					{
						while (true)
						{
							::printf("Select field of structure for sorting by alphabet(Z-A)(press:'1' for sorting on the field 'title' of structure\n'2' for sorting on the field 'surname' of structure\n'3' for sorting on the field 'name' of structure\n'4' for sorting on the field 'middlename' of structure\n'5' for sorting on the field 'country' of structure\n");
							::cin >> choise;
							if ((choise >= 1) && (choise <= 5))
							{
								if (choise == 1)//Сортировка поля title по алфавиту от конца до начала
								{
									int j = 0;
									Film* myfilm1;
									myfilm1 = new Film[n];
									myfilm1 = myfilm;
									for (int i = 0; i < n - j;)
									{
										for (int k = 0; k < n - j - 1; k++)
										{
											if ((int)toupper(myfilm1[k].title[0]) < (int)toupper(myfilm1[k + 1].title[0]))
											{
												swap(myfilm1[k], myfilm1[k + 1]);
											}
										}
										j++;
									}
									::printf("Array of structures sorted by alphabet(Z-A). On elements 'title'\n");
									for (i = 0; i < n; i++)
									{
										::printf("%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\n", myfilm1[i].title, myfilm1[i].surname, myfilm1[i].name, myfilm1[i].middlename, myfilm1[i].country, myfilm1[i].year, myfilm1[i].cost, myfilm1[i].profit);
									}
									myfilm1 = NULL;
								}
								if (choise == 2)//Сортировка поля surname по алфавиту от конца до начала
								{
									int j = 0;
									Film* myfilm1;
									myfilm1 = new Film[n];
									myfilm1 = myfilm;
									for (int i = 0; i < n - j;)
									{
										for (int k = 0; k < n - j - 1; k++)
										{
											if ((int)toupper(myfilm1[k].surname[0]) < (int)toupper(myfilm1[k + 1].surname[0]))
											{
												swap(myfilm1[k], myfilm1[k + 1]);
											}
										}
										j++;
									}
									::printf("Array of structures sorted by alphabet(Z-A). On elements 'surname'\n");
									for (i = 0; i < n; i++)
									{
										::printf("%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\n", myfilm1[i].title, myfilm1[i].surname, myfilm1[i].name, myfilm1[i].middlename, myfilm1[i].country, myfilm1[i].year, myfilm1[i].cost, myfilm1[i].profit);
									}
									myfilm1 = NULL;
								}
								if (choise == 3)//Сортировка поля name по алфавиту от конца до начала
								{
									int j = 0;
									Film* myfilm1;
									myfilm1 = new Film[n];
									myfilm1 = myfilm;
									for (int i = 0; i < n - j;)
									{
										for (int k = 0; k < n - j - 1; k++)
										{
											if ((int)toupper(myfilm1[k].name[0]) < (int)toupper(myfilm1[k + 1].name[0]))
											{
												swap(myfilm1[k], myfilm1[k + 1]);
											}
										}
										j++;
									}
									::printf("Array of structures sorted by alphabet(Z-A). On elements 'name'\n");
									for (i = 0; i < n; i++)
									{
										::printf("%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\n", myfilm1[i].title, myfilm1[i].surname, myfilm1[i].name, myfilm1[i].middlename, myfilm1[i].country, myfilm1[i].year, myfilm1[i].cost, myfilm1[i].profit);
									}
									myfilm1 = NULL;
								}
								if (choise == 4)//Сортировка поля middlename по алфавиту от конца до начала
								{
									int j = 0;
									Film* myfilm1;
									myfilm1 = new Film[n];
									myfilm1 = myfilm;
									for (int i = 0; i < n - j;)
									{
										for (int k = 0; k < n - j - 1; k++)
										{
											if ((int)toupper(myfilm1[k].middlename[0]) < (int)toupper(myfilm1[k + 1].middlename[0]))
											{
												swap(myfilm1[k], myfilm1[k + 1]);
											}
										}
										j++;
									}
									::printf("Array of structures sorted by alphabet(Z-A). On elements 'middlename'\n");
									for (i = 0; i < n; i++)
									{
										::printf("%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\n", myfilm1[i].title, myfilm1[i].surname, myfilm1[i].name, myfilm1[i].middlename, myfilm1[i].country, myfilm1[i].year, myfilm1[i].cost, myfilm1[i].profit);
									}
									myfilm1 = NULL;
								}
								if (choise == 5)//Сортировка поля country по алфавиту от конца до начала
								{
									int j = 0;
									Film* myfilm1;
									myfilm1 = new Film[n];
									myfilm1 = myfilm;
									for (int i = 0; i < n - j;)
									{
										for (int k = 0; k < n - j - 1; k++)
										{
											if ((int)toupper(myfilm1[k].country[0]) < (int)toupper(myfilm1[k + 1].country[0]))
											{
												swap(myfilm1[k], myfilm1[k + 1]);
											}
										}
										j++;
									}
									::printf("Array of structures sorted by alphabet(Z-A). On elements 'country'\n");
									for (i = 0; i < n; i++)
									{
										::printf("%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\n", myfilm1[i].title, myfilm1[i].surname, myfilm1[i].name, myfilm1[i].middlename, myfilm1[i].country, myfilm1[i].year, myfilm1[i].cost, myfilm1[i].profit);
									}
									myfilm1 = NULL;
								}

							}
							else
							{
								::printf("Please select field of structure for sorting by alphabet(Z-A) again. Field number %d not found.", choise);
								continue;
							}
							::printf("Do you want sorting by alphabet(Z-A) again?(y/n)\n");
							::cin >> answer;
							if (answer == 'y')
								continue;
							else
								break;
						}
					}
				}
			}
			else
			{
				::printf("Please, select sort method again. Method number %d not found.\n", choise);
				continue;
			}
			::printf("Do you want to organize the array of structures again?(y/n)\n ");
			::cin >> answer;
			if (answer == 'y')
				continue;
			else
				break;
		}
	}
	//Вывод массива структур
	::printf("Do you want to display the array of structures on the screen?(y/n)\n");
	::cin >> answer;
	if (answer == 'y')
	{
		for (i = 0; i < n; i++)
		{
			::printf("%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\n", myfilm[i].title, myfilm[i].surname, myfilm[i].name, myfilm[i].middlename, myfilm[i].country, myfilm[i].year, myfilm[i].cost, myfilm[i].profit);
		}
	}
	fclose(f);
	delete[] myfilm;
	return 0;
}