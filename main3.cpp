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

string ch[30];		///��������� ������ ����� � �������� �������
int Next=0,index=0,length=10;

/** 
@function Insert
������� ����������� �������� � �������
*/

void Insert(string i)			
{
 if(Next+1 == index || (Next+1 == length && !index))
 {
  cout<<"���� ���!\n";									///���� ������� ����������� ������� ���������
  return;
 }
 ch[Next]=i; /// ���������� �������� �������� � �������
 Next++; /// �������� ������� ������
 if(Next==length)
  Next=0; /// ����������� �������.
}
/** 
@function Retrieve
������� ���������� �������� �� �������
 */
string Retrieve()
{
 if(index == length)
  index=0; /// ����������� �������.
 if(index == Next)
 {
  cout<<"������� �����.\n";		///���� ������� ������ ������� ���������
  return 0;
 }
 index++; /// �������� ������� ����������
 return ch[index-1]; /// ���������� ������ ������� � �������
}

/** 
@function main
������� �������
*/

int main()	
{
 Insert("st1");		  		///��������� ��� �������� � �������
 Insert("st2");		  	
 Insert("st3");		  	
 cout<<Retrieve()<<endl;	///������� ������ �� �������
 Insert("st4");		  		///��������� ���� �������
 cout<<Retrieve()<<'\n';	///������� ��� 2 ��������
 cout<<Retrieve()<<endl;	
 getch();
 return 0;		
}		

