#include <stdio.h>
#include <string>
#include <iostream>
#include <limits.h>
#include <cstdlib>
#include "Node.h"
using namespace std;




int main() {

	List start;
	for (int i = 0; i < 10; i++)
	{
		int number;
		cin >> number;
		start.addNode(number);
		//start.addNode(rand() % 10); // Инициализация
	}

	start.print(); // Вывод входных данных
	printf("\n");

	for (int i = 0; i < 10; i++) // Сортировка
	{
		cout << "Iteration #" << i + 1 << "\n";
		Node* tmp = start.first;
		for (int j = 0; j < i; j++)
			tmp = tmp->next;
		Node* tmpStart = tmp;
		Node* min = new Node(INT_MAX);
		while (tmp != NULL)
		{
			if (tmp->val < min->val) min = tmp;
			tmp = tmp->next;
		}
		start.deleteElem(min->val, tmpStart);
		printf("\n");
		start.addToStart(min);
		start.print();
		printf("\n");
		free(tmp);
	}
}