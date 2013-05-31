/**
\file main3.cpp 
*/

/**
\fn int main() 
*/



#include <iostream>
#include<string>
#include<conio.h>
using namespace std;

string ch[30];		///объявляем массив строк в качестве очереди
int Next=0,index=0,length=10;

/** 
@function Insert
Функция добавляения элемента в очередь
*/

void Insert(string i)			
{
 if(Next+1 == index || (Next+1 == length && !index))
 {
  cout<<"Мест нет!\n";									///если очередь переполнена выводим сообщение
  return;
 }
 ch[Next]=i; /// Записываем значение элемента в очередь
 Next++; /// Смещение позиции записи
 if(Next==length)
  Next=0; /// Циклический переход.
}
/** 
@function Retrieve
Функция извлечения элемента из очереди
 */
string Retrieve()
{
 if(index == length)
  index=0; /// Циклический переход.
 if(index == Next)
 {
  cout<<"Очередь пуста.\n";		///если очередь пустая выводим сообщение
  return 0;
 }
 index++; /// Смещение позиции считывания
 return ch[index-1]; /// Возвращаем первый элемент в очереди
}

/** 
@function main
Главная функция
*/

int main()	
{
 Insert("st1");		  		///добавляем три элемента в очередь
 Insert("st2");		  	
 Insert("st3");		  	
 cout<<Retrieve()<<endl;	///удаляем одного из очереди
 Insert("st4");		  		///добавляем один элемент
 cout<<Retrieve()<<'\n';	///удаляем еще 2 элемента
 cout<<Retrieve()<<endl;	
 getch();
 return 0;		
}		

