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
Класс элемент содержит конструктор c параметрами
*/

class element{		///Создаем класс элемент
public:
 /// Конструктор по умолчанию element(); 
 /// @param in_iParameter1 – параметр 1
 /// @param out_sParameter2 - параметр 2

 bool DoSmthng(int in_iParameter1, std::string out_sParameter2); 

	string name;	///поле имя
	element *next;/// указатель на следующий элемент списка
};

/** 
@class spisok
Класс список содержит конструктор и методы
*/
class spisok{		///создаем класс список
	element *e;		///создаем список элементов
public:
	spisok();			///Конструктор
	void add(string s);	///метод добавления элемента в список
	void del(string s);	///метод удаления элемента из списка
	///@param s - параметр
    ///@param i - параметр
	element* get(int i);	///метод получения значения элемента по номеру
};

/** 
@function spisok
*/
spisok::spisok(){
	e=NULL;								///обнуляем список
	element* new_e = new element[1];	
	if (new_e)
	{									///добавляем первый элемент
	new_e->name="df";
	new_e->next=NULL;
	e=new_e;							///элемент становится началом списка
	}
}
/** 
@function add
Функция добавления
@param s - параметр
*/
void spisok::add(string s){

	element* new_e = new element[1];			///выделяем память для нового элемента
	new_e->name=s;								///присваиваем значение имени
	new_e->next=NULL;							///обнуляем указатель на следующий элемент
	element* last_e = e;						///создаем указатель на последний элемент
	/// Текущий элемент указывает на следующий элемент?
	while (last_e->next)
	{
	/// Переход к следующему элементу списка
	last_e = last_e->next;
	}
	/// Связывание последнего элемента с новым
	last_e->next = new_e;
}	
/** 
@function del
Функция удаления
@param s - параметр
*/
void spisok::del(string s){
	element* current = e;
	/// Просмотренных элементов списка еще нет
	element* previous = NULL;
	/// Указатель на элемент списка определен?
	while (current)
	{
		/** Сохранение указателя на элемент, следующий за текущим, так как к концу
		 итерации цикла текущий элемент может быть удален и невозможно будет
		 получить указатель на элемент, который к нему привязан
		 */

		element* next = current->next;
		/// Проверка критерия удаления: хранимое число меньше 0?
		if (current->name ==s)
		{
			/// Указатель на предыдущий элемент списка определен?
			if (previous) 
			{
				/// Привязка к нему элемента, следующего за текущим
				previous->next = next;
			}
			/// Удаление текущего элемента списка
			delete []current;
		}

		/** Сохранение текущего элемента в качестве предыдущего 
		и переход к следующему элементу списка
		*/
		previous = current;
		current = next;
	}
}
/** 
@function get
Функция получения верхнего значения по индексу
@param i - параметр
*/
element* spisok::get(int i){
	element* current = e;		///указатель равен началу списка
	for (int j=1;j<=i;j++)		/// цикл от 1 до необходимого
		current=current->next;	///получаем указатель на нужный элемент
	return current;				///возвращаем указатель
}

/** 
@function main
Главная функция
*/

int main(){
	spisok sp1;			///объявляем экземпляр класса
	element* elem;		///создаем указатель на элемент
	sp1.add("Privet");	///добавляем подряд три элемента
	sp1.add("Ya");
	sp1.add("Kate");
	elem=sp1.get(2);		///получаем значение 2 элемента
	cout<<elem->name<<endl;	///выводим его на экран
	sp1.del("Ya");			///удаляем элемент с именем YA
	
	getch();
	return 0;
}


