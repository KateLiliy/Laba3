/**
\file main1.cpp 
*/

/**
\fn int main() 
*/


#include<iostream>
#include<conio.h>
#include<string>

using namespace std;
const int MAX=5;

/** 
@class Stack 
Содержит конструктор
*/ 
class Stack
{

public:
	string stack[MAX+1];
	int tos;   /// вершина стека 
	Stack(){tos=0; }	/// конструктор
	void push(string i);	///поместить в стек
	///@param i - параметр
	string pop(void);		///извлечь из стека
	string top();			///получить верхнее значение
};

/** 
@function push
Функция помещения элемента в стек
@param i - параметр
*/
void Stack::push(string i)
{
  
  if(tos >= MAX) {		
    printf("Стек полон\n");			///выводим на экран сообщение если стек переполнен
	    return;
  }
  tos++;							///увеличиваем количество элементов в стеке
  stack[tos] = i;					///записываем значение элемента в стек
  
}
/** 
@function pop
Функция извлечения элемента из стека
*/

string Stack::pop(void)
{
  tos--;							///уменьшаем количество элементов в стеке
  if(tos < 0) {
    printf("Стек пуст\n");			///выводим на экран сообщение если стек пуст
    return 0;
  }
  return stack[tos+1];				///возваращаем последний элемент стека
}

/** 
@function top
Функция получения верхнего значения
*/
string Stack::top(void)
{
  return stack[tos];				///возвращаем последний элемент стека
}

/** 
@function main
Главная функция
*/
int main(){

	Stack s1;					///объявляем объект класса stack
	s1.push("st1");				///записываем подряд 5 элементов в стек
	s1.push("st2");
	s1.push("st3");
	s1.push("st4");
	s1.push("st5");
	cout<<s1.pop()<<endl;		///извлекаем последний элемент
	cout<<s1.top()<<endl;		///выводим последний элемент стека
	cout<<s1.pop()<<endl;		///извлекаем последний элемент
	s1.push("new");				///заносим новый элемент
	cout<<s1.top()<<endl;		///выводим его
 getch();
 return 0;
}