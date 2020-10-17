#include<iostream>
#include <math.h>
#include <conio.h>

using namespace std;

void func(int a0, double u, float chislo)
{
	int pm = 1, p = a0, qm = 0, q = 1; //P(-1), P(0),Q(-1),Q(0)
	double alpha = u; //альфа(0)
	int a = a0;
	int flag = 0; //флажок на сравнение
	int count = 0; //счетчик проходов
	int res_alpha = (int)(alpha * 10000);//преобразуем наше число для дальнейшего сраанения
	double the_alpha, result;
	float count_PQ;       // P/Q
	int the_a, the_P, the_Q, res_count;   
	do {                                       //находим альфа(i),a(i),P(i),Q(i),P(i)/Q(i)
		the_alpha = 1 / (alpha - a);    
		the_a = (int)the_alpha;
		the_P = the_a * p + pm;
		the_Q = the_a * q + qm;
		count_PQ =(float) the_P/the_Q;      
		res_count = (int)(count_PQ * 10000); // выполняем для дальнейшего сравнения P/Q с нашим числом
		result = (float)res_count / 10000;   // это будет результирующий корень числа
		count++;
		alpha = the_alpha;           //меняем значение переменных для следующего шага
		pm = p;
		p = the_P;
		qm = q;
		q = the_Q;
		a = the_a;
		if (res_count == res_alpha) flag = 1;     //сравниваем P/Q с тем, что мы должны получить
	} while (flag != 1);

	cout <<"Корень из заданного числа с точностью до 4-го знака после запятой равен "
		<<result<<" . Число проходов:" <<count;
}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	float p;
	cout << "Введите число : ";
	cin >> p; //Вводим наше число
	double u = sqrt(p);//Значение корня из числа
	int a0 = (int)u; //Целая часть
	func(a0, u, p);
	_getch();
}


