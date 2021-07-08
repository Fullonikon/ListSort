#pragma once
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;


struct Node { // �����
public:
	int val;
	Node* next;

	Node(int _val) : val(_val), next(nullptr) {} // ����������� �� ���������
};

class List
{
public:
	Node* first; // ������ �������
	Node* last; // ���������

	List()
	{
		first = NULL;
		last = NULL;
	}

	void addNode(int val) // ���������� 
	{
		if (first == NULL) // ���� �����
		{
			first = new Node(val);
			last = first;
			return;
		}
		last->next = new Node(val); // ����� ��������� ����������
		last = last->next;
	}

	void addToStart(Node* node) // ���������� � ������
	{
		Node* tmp = first; // ������� ������ ������ � ������� ����� � ������ ��������� �������
		node->next = tmp;
		first = node;
	}

	void deleteElem(int val) // �� ��������
	{
		if (first == NULL) return; // �������� ���� �����
		if (val == first->val) // �������� ���� ������� ������ �������
		{
			first = first->next; // ��������� ������� ���������� ������
			return;
		}
		Node* tmp;
		tmp = first;
		while (tmp->next->val != val && tmp->next != NULL) // ������������� ������ ������� � �����
		{ // ���� �� ������ ����, �������������� elem
			tmp = tmp->next;
		}
		if (tmp->next == NULL) return;
		tmp->next = tmp->next->next; // ������������ ���������
	}

	void deleteElem(int val, Node* start) // ������� � ������ �� ��������
	{
		if (first == NULL) return; // �������� ���� �����
		Node* tmp;
		tmp = first;
		Node* last = tmp;
		while (tmp != start && tmp->next != NULL) // ���� ��������� �������
		{
			last = tmp; // ����������
			tmp = tmp->next;
		}
		if (start->val == val) // ���� �������� ������� ����� ������� ������� ������� ������
		{
			last->next = tmp->next;
			return;
		}
		while (tmp->next->val != val && tmp->next != NULL) // ������������� ������ ������� � ������� �����
		{ // ���� �� ������ ����, �������������� elem
			tmp = tmp->next;
		}
		if (tmp->next == NULL) return;
		tmp->next = tmp->next->next; // ������������ ���������
	}

	void print()
	{
		Node* p;
		p = first;
		do {
			cout << p->val << " "; // ����� �������� �������� p
			p = p->next; // ������� � ���������� ����
		} while (p != NULL);
	}

};