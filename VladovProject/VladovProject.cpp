#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#define _USE_MATH_DEFINES
#include <math.h>

float r;
float L;
float U;
float f;
float x;
float i;
float e;

int a = 4;
int b = 2;
const int maxMenuItems = 4;


float calculateElectromotiveForce(float i, float x) {
	return i * x;
}
float calculateCoilResistance(float f, float L) {
	return 2 * M_PI * f * L;
}
float calculateAmperage(float U, float r, float x) {
	return U / sqrt(pow(r, 2) + pow(x, 2));
}

int main()
{
	setlocale(LC_ALL, "Rus");

	//Меню

	programStart:


	printf("1.Ввод исходных данных,\n2.Вывод введенных данных.\nЗ.Вывод рассчитываемых данных.\n4.Выход из программы\n");
	int currentMenuNumber;
	if (!scanf("%i", &currentMenuNumber) || currentMenuNumber > maxMenuItems) return 1;

	switch (currentMenuNumber) {
	case 1:
		//Ввод данных
		printf("Введите r\n");
		if (!scanf("%f", &r)) return 1;

		printf("Введите L\n");
		if (!scanf("%f", &L)) return 1;

		printf("Введите U\n");
		if (!scanf("%f", &U)) return 1;

		printf("Введите f\n");
		if (!scanf("%f", &f)) return 1;


		printf("Введите a\n");
		if (!scanf("%i", &a)) return 1;

		printf("Введите b\n");
		if (!scanf("%i", &b)) return 1;

		break;
	case 2:

		printf("Введённые данные:\n");
		printf("r: %f\n", r);
		printf("L: %f\n", L);
		printf("U: %*.*f\n", a, b, U);
		printf("f: %f\n", f);

		break;
	case 3:
		//Вычисления

		x = calculateCoilResistance(f, L);
		i = calculateAmperage(U, r, x);
		e = calculateElectromotiveForce(i, x);

		//Вывод результатов


		printf("Результаты:\n");
		printf("x: %5.4f\n", x);
		printf("i: %f\n", i);
		printf("e: %4.2f\n", e);
		break;
	case 4:
		return 0;
		break;
	}
			
	printf("\n");
	goto programStart;

	return 0;
}