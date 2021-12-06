#include<bits/stdc++.h>
using namespace std;

typedef struct 
{
	double realpart;//ʵ��
	double imagpart;//�鲿 
}Complex;//���� 
void assign(Complex *A,float real,float imag)//��ֵ��������ʵ�����鲿 
{
	A->realpart=real;
	A->imagpart=imag;
}
void add(Complex *A,Complex B,Complex C)//�ӷ���A=B+C 
{
	A->realpart=B.realpart+C.realpart;
	A->imagpart=B.imagpart+C.imagpart;
}
void substract(Complex *A,Complex B,Complex C)//������A=B-C
{
	A->realpart=B.realpart-C.realpart;
	A->imagpart=B.imagpart-C.imagpart;	
} 
void multiply(Complex *A,Complex B,Complex C)//�˷���A=B*C
{
	A->realpart=B.realpart*C.realpart-B.imagpart*C.imagpart;
	A->imagpart=B.realpart*C.imagpart+B.imagpart*C.realpart;	
}
void divide(Complex *A,Complex B,Complex C)//������A=B/C
{
	Complex D,E;
	assign(&D,C.realpart ,-C.imagpart );
	multiply(&E,B,D);
	double c=C.realpart * C.realpart + C.imagpart * C.imagpart ;
	A->realpart = E.realpart / c;
	A->imagpart = E.imagpart / c;
} 
void printcomplex(Complex A)
{
	int sign=0;
	if(A.realpart !=0)
	{
		cout<<A.realpart ;
		sign=1;		
	}
	if(A.imagpart <0)
	{
		if(A.imagpart  !=-1)
		cout<<A.imagpart <<"i";
		else
		cout<<"i";
	}
	if(A.imagpart >0)
	{
		if(sign==1) cout<<"+";
		if(A.imagpart !=1)
		cout<<A.imagpart <<"i";
		else
		cout<<"i";
	}
	cout<<endl;
}



int main()
{
	Complex z1,z2,z3;
	double a,b,c,d;
	while(1)
	{
		cout<<"�Ƿ����������������������ش�y�������ش�n����";
		char f;
		cin>>f;
		if(f=='y')
		{
			cout<<"������z1��ʵ����";
			cin>>a;
			cout<<"������z1���鲿��";
			cin>>b; 
			assign(&z1,a,b);
			cout<<"z1=";
			printcomplex(z1);
			cout<<"������z2��ʵ����";
			cin>>a;
			cout<<"������z2���鲿��";
			cin>>b; 
			assign(&z2,a,b);
			cout<<"z2=";	
			printcomplex(z2);
			cout<<"�������������ͣ�+-*/����";
			char e;
			cin>>e;
			if(e=='+')
			{
				add(&z3,z1,z2);
				cout<<"z1+z2=";
				printcomplex(z3);		
			}
				if(e=='-')
			{
				substract(&z3,z1,z2);
				cout<<"z1-z2=";
				printcomplex(z3);		
			}
			if(e=='*')
			{
				multiply(&z3,z1,z2);
				cout<<"z1*z2=";
				printcomplex(z3);		
			}
			if(e=='/')
			{
				divide(&z3,z1,z2);
				cout<<"z1/z2=";
				printcomplex(z3);
			}
					
		}
		else if(f=='n') break;
	}
	return 0;
}

