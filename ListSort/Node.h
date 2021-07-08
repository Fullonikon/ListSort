#pragma once
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;


struct Node { // Звено
public:
	int val;
	Node* next;

	Node(int _val) : val(_val), next(nullptr) {} // Конструктор по умолчанию
};

class List
{
public:
	Node* first; // Первый элемент
	Node* last; // Последний

	List()
	{
		first = NULL;
		last = NULL;
	}

	void addNode(int val) // Добавление 
	{
		if (first == NULL) // Если пусто
		{
			first = new Node(val);
			last = first;
			return;
		}
		last->next = new Node(val); // Иначе добавляем последнему
		last = last->next;
	}

	void addToStart(Node* node) // Добавление в начало
	{
		Node* tmp = first; // Цепляем начало масива к нужному звену и меняем начальный элемент
		node->next = tmp;
		first = node;
	}

	void deleteElem(int val) // По значению
	{
		if (first == NULL) return; // проверка если пусто
		if (val == first->val) // проверка если удаляем первый элемент
		{
			first = first->next; // следующий элемент становится первым
			return;
		}
		Node* tmp;
		tmp = first;
		while (tmp->next->val != val && tmp->next != NULL) // просматриваем список начиная с корня
		{ // пока не найдем узел, предшествующий elem
			tmp = tmp->next;
		}
		if (tmp->next == NULL) return;
		tmp->next = tmp->next->next; // переставляем указатель
	}

	void deleteElem(int val, Node* start) // Начиная с какого то элемента
	{
		if (first == NULL) return; // проверка если пусто
		Node* tmp;
		tmp = first;
		Node* last = tmp;
		while (tmp != start && tmp->next != NULL) // Ищем начальный элемент
		{
			last = tmp; // Предыдущий
			tmp = tmp->next;
		}
		if (start->val == val) // Если значение которое нужно удалить явлется началом поиска
		{
			last->next = tmp->next;
			return;
		}
		while (tmp->next->val != val && tmp->next != NULL) // просматриваем список начиная с нужного звена
		{ // пока не найдем узел, предшествующий elem
			tmp = tmp->next;
		}
		if (tmp->next == NULL) return;
		tmp->next = tmp->next->next; // переставляем указатель
	}

	void print()
	{
		Node* p;
		p = first;
		do {
			cout << p->val << " "; // вывод значения элемента p
			p = p->next; // переход к следующему узлу
		} while (p != NULL);
	}

};