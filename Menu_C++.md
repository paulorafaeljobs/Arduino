# Menu feito em C++
```cpp
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <locale>
using namespace std;
int main(){
	{setlocale(LC_ALL,"ptb");}
	int val,num1,num2,resu;
	inicio:
	system("cls");//APAGA COUT ACIMA
	system("color 0f");
	cout<<"Selecione uma Cor:";
	cout<<"\n1 Opçao 1";
	cout<<"\n2 SAIR";
	cout<<"\n";
	cin >>val;
	switch(val){
		case 1:
			system("cls");
			cout<<"Digite Password:";
			cout<<"\n";
			system("pause");
			goto inicio;
		case 2:
			system("cls");
			break;	
			default:
			cout<<"Valor Selecionado Invalido";
			goto inicio;
	}
}
```
