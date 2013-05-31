/**
\file main.cpp 
*/

/**
\fn int main() 
*/



#include<iostream>
#include<string>
#include<conio.h>

using namespace std;

/** 
@class element
����� ������� �������� ����������� c �����������
*/

class element{		///������� ����� �������
public:
 /// ����������� �� ��������� element(); 
 /// @param in_iParameter1 � �������� 1
 /// @param out_sParameter2 - �������� 2

 bool DoSmthng(int in_iParameter1, std::string out_sParameter2); 

	string name;	///���� ���
	element *next;/// ��������� �� ��������� ������� ������
};

/** 
@class spisok
����� ������ �������� ����������� � ������
*/
class spisok{		///������� ����� ������
	element *e;		///������� ������ ���������
public:
	spisok();			///�����������
	void add(string s);	///����� ���������� �������� � ������
	void del(string s);	///����� �������� �������� �� ������
	///@param s - ��������
    ///@param i - ��������
	element* get(int i);	///����� ��������� �������� �������� �� ������
};

/** 
@function spisok
*/
spisok::spisok(){
	e=NULL;								///�������� ������
	element* new_e = new element[1];	
	if (new_e)
	{									///��������� ������ �������
	new_e->name="df";
	new_e->next=NULL;
	e=new_e;							///������� ���������� ������� ������
	}
}
/** 
@function add
������� ����������
@param s - ��������
*/
void spisok::add(string s){

	element* new_e = new element[1];			///�������� ������ ��� ������ ��������
	new_e->name=s;								///����������� �������� �����
	new_e->next=NULL;							///�������� ��������� �� ��������� �������
	element* last_e = e;						///������� ��������� �� ��������� �������
	/// ������� ������� ��������� �� ��������� �������?
	while (last_e->next)
	{
	/// ������� � ���������� �������� ������
	last_e = last_e->next;
	}
	/// ���������� ���������� �������� � �����
	last_e->next = new_e;
}	
/** 
@function del
������� ��������
@param s - ��������
*/
void spisok::del(string s){
	element* current = e;
	/// ������������� ��������� ������ ��� ���
	element* previous = NULL;
	/// ��������� �� ������� ������ ���������?
	while (current)
	{
		/** ���������� ��������� �� �������, ��������� �� �������, ��� ��� � �����
		 �������� ����� ������� ������� ����� ���� ������ � ���������� �����
		 �������� ��������� �� �������, ������� � ���� ��������
		 */

		element* next = current->next;
		/// �������� �������� ��������: �������� ����� ������ 0?
		if (current->name ==s)
		{
			/// ��������� �� ���������� ������� ������ ���������?
			if (previous) 
			{
				/// �������� � ���� ��������, ���������� �� �������
				previous->next = next;
			}
			/// �������� �������� �������� ������
			delete []current;
		}

		/** ���������� �������� �������� � �������� ����������� 
		� ������� � ���������� �������� ������
		*/
		previous = current;
		current = next;
	}
}
/** 
@function get
������� ��������� �������� �������� �� �������
@param i - ��������
*/
element* spisok::get(int i){
	element* current = e;		///��������� ����� ������ ������
	for (int j=1;j<=i;j++)		/// ���� �� 1 �� ������������
		current=current->next;	///�������� ��������� �� ������ �������
	return current;				///���������� ���������
}

/** 
@function main
������� �������
*/

int main(){
	spisok sp1;			///��������� ��������� ������
	element* elem;		///������� ��������� �� �������
	sp1.add("Privet");	///��������� ������ ��� ��������
	sp1.add("Ya");
	sp1.add("Kate");
	elem=sp1.get(2);		///�������� �������� 2 ��������
	cout<<elem->name<<endl;	///������� ��� �� �����
	sp1.del("Ya");			///������� ������� � ������ YA
	
	getch();
	return 0;
}


