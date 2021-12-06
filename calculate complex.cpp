#include<bits/stdc++.h>
using namespace std;

typedef struct 
{
	double realpart;//实部
	double imagpart;//虚部 
}Complex;//复数 
void assign(Complex *A,float real,float imag)//赋值：复数，实部，虚部 
{
	A->realpart=real;
	A->imagpart=imag;
}
void add(Complex *A,Complex B,Complex C)//加法：A=B+C 
{
	A->realpart=B.realpart+C.realpart;
	A->imagpart=B.imagpart+C.imagpart;
}
void substract(Complex *A,Complex B,Complex C)//减法：A=B-C
{
	A->realpart=B.realpart-C.realpart;
	A->imagpart=B.imagpart-C.imagpart;	
} 
void multiply(Complex *A,Complex B,Complex C)//乘法：A=B*C
{
	A->realpart=B.realpart*C.realpart-B.imagpart*C.imagpart;
	A->imagpart=B.realpart*C.imagpart+B.imagpart*C.realpart;	
}
void divide(Complex *A,Complex B,Complex C)//除法：A=B/C
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
		cout<<"是否启动复数计数器（启动回答y，结束回答n）：";
		char f;
		cin>>f;
		if(f=='y')
		{
			cout<<"请输入z1的实部：";
			cin>>a;
			cout<<"请输入z1的虚部：";
			cin>>b; 
			assign(&z1,a,b);
			cout<<"z1=";
			printcomplex(z1);
			cout<<"请输入z2的实部：";
			cin>>a;
			cout<<"请输入z2的虚部：";
			cin>>b; 
			assign(&z2,a,b);
			cout<<"z2=";	
			printcomplex(z2);
			cout<<"请输入运算类型（+-*/）：";
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

