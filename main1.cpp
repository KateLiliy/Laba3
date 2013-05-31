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
�������� �����������
*/ 
class Stack
{

public:
	string stack[MAX+1];
	int tos;   /// ������� ����� 
	Stack(){tos=0; }	/// �����������
	void push(string i);	///��������� � ����
	///@param i - ��������
	string pop(void);		///������� �� �����
	string top();			///�������� ������� ��������
};

/** 
@function push
������� ��������� �������� � ����
@param i - ��������
*/
void Stack::push(string i)
{
  
  if(tos >= MAX) {		
    printf("���� �����\n");			///������� �� ����� ��������� ���� ���� ����������
	    return;
  }
  tos++;							///����������� ���������� ��������� � �����
  stack[tos] = i;					///���������� �������� �������� � ����
  
}
/** 
@function pop
������� ���������� �������� �� �����
*/

string Stack::pop(void)
{
  tos--;							///��������� ���������� ��������� � �����
  if(tos < 0) {
    printf("���� ����\n");			///������� �� ����� ��������� ���� ���� ����
    return 0;
  }
  return stack[tos+1];				///����������� ��������� ������� �����
}

/** 
@function top
������� ��������� �������� ��������
*/
string Stack::top(void)
{
  return stack[tos];				///���������� ��������� ������� �����
}

/** 
@function main
������� �������
*/
int main(){

	Stack s1;					///��������� ������ ������ stack
	s1.push("st1");				///���������� ������ 5 ��������� � ����
	s1.push("st2");
	s1.push("st3");
	s1.push("st4");
	s1.push("st5");
	cout<<s1.pop()<<endl;		///��������� ��������� �������
	cout<<s1.top()<<endl;		///������� ��������� ������� �����
	cout<<s1.pop()<<endl;		///��������� ��������� �������
	s1.push("new");				///������� ����� �������
	cout<<s1.top()<<endl;		///������� ���
 getch();
 return 0;
}