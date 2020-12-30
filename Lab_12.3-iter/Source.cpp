
#include <iostream>
#include <Windows.h> 
using namespace std;

typedef struct List List;

struct List 
{
	int el;
	List* prev;
	List* next;
};

void Input(List*, int);
void Output(List*);
bool FindPairs(List*);

int main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	List* start = new List;

	int size;
	cout << "Скільки елементів ти хочеш ввести? ";
	cin >> size;
	cout << "Вводи ці " << size << " елементів:";
	cout << endl;

	Input(start, size);
	Output(start);

	bool pairFound = FindPairs(start);
	if (pairFound)
		cout << "Пара знайдена!" << endl;
	else
		cout << "Не знайдено жодної пари" << endl;
	return 0;
}

void Input(List* start, int size)
{
	List* prev = start;
	cin >> start->el;
	List* cur = start;
	cur->prev = NULL;
	for (int i = 0; i < size - 1; i++)
	{
		cur = new List;
		prev->next = cur;
		cur->prev = prev;
		cin >> cur->el;
		prev = cur;
	}
	cur->next = NULL;
}

void Output(List* start)
{
	cout << "Список: ";
	List* cur = start;
	while (cur != NULL) 
	{
		cout << cur->el << ", ";
		cur = cur->next;
	}
	cout << endl;
}

bool FindPairs(List* start)
{
	bool pairFound = false;
	List* cur1 = start;
	List* cur2 = start->next;
	while (cur1 != NULL)
	{
		cur2 = cur1->next;
		while (cur2 != NULL)
		{
			if (cur2->el == cur1->el) 
			{
				pairFound = true;
				return pairFound;
			}
			cur2 = cur2->next;
		}
		cur1 = cur1->next;
	}
	return pairFound;
}