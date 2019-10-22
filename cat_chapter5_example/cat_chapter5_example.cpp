// cat_chapter5_example.cpp : �������̨Ӧ�ó������ڵ㡣
#include "stdafx.h"

//////////��1����. ����ע�ͷ�����˵����ע�;��Ǵ��벻�ܱ�������У���ע�ͺ���ܡ�
//���Դ�ע�ͺ�ע�ͣ��������п����������ɫ�仯��1��ɾ���ͼ���//��2��ɾ��/**/�����¼��ϣ�3��0�ĳ�1���ٸĳ�0
//#include <stdio.h>
/* #include <stdio.h> */
#if 0
#include <stdio.h>
#endif
//����ע�ͷ�ʽ��һ��ע��Ŀ����ǰ��//������ע��Ŀ��ŵ�/*��*/֮�䣻����ע��Ŀ��ŵ�#if 0��#endif֮�䡣
//��ע�ͷ�����ǰ����ɾ����Ӧ�ķ��ż�//��/**/, ���һ��0�ĳ�1��



/////////////��2����. ������è�������⣬ÿ�����ⶼ�ŵ�#if 0��#endif֮�䡣
////////����ĳ����ʱ���ĳ�#if 1���ɣ��������ĳ�#if 0��ע�͵������⡣ �ٵ��Ա�����⣬�ظ�ͬ���Ĳ�����

#if 1
/*����5-1������Բ���ĸߺͰ뾶����Բ�������volume=3.1415926*r*r*h��Ҫ����͵��ú���cylinder (r, h )����Բ���������� */

/* ����Բ����� */
#include <stdio.h>
double cylinder(double r, double h);		/* ��������*/
int main(void)
{
	double height, radius, volume;

	printf("Enter radius and height: ");	    /* ������ʾ */
	scanf("%lf%lf", &radius, &height);		    /* ����Բ���İ뾶�͸߶� */
	volume = cylinder(radius, height);			/* ���ú���������ֵ����volume */
	printf("Volume = %.3f\n", volume);			/*���Բ������� */
	return  0;
}

/* ������Բ������ĺ��� */
double cylinder(double r, double h)
{
	double result;
	result = 3.1415926 * r * r * h;    			/* ����Բ����� */
	return result;								/* ���ؽ�� */
}
#endif

#if 0
/*����5-2������һ���ж���ż���ĺ���even(n)����nΪż��ʱ����1�����򷵻�0��*/

int even(int n)��
int main(void)
{
	even(10);
	return  0;
}
/* �ж���ż���ĺ��� */
int even(int n)				/* �����ײ� */
{
	if (n % 2 == 0) 			/* �б���ż�� */
		return 1;			/* ż������1 */
	else
		return 0;			/* ��������0 */
}
#endif

#if 0
/*����5-3�� ���뾫��e��ʹ�ø��������ʽ��еĽ���ֵ����ȷ�����һ��ľ���ֵС��e��Ҫ����͵��ú���funpi(e)��еĽ���ֵ��*/

/*  �ø��������ʽ����еĽ���ֵ������Ϊe  */
#include <stdio.h>
#include <math.h>
double funpi(double e);			/* �������� */
int main(void)
{
	double e, pi;     				/* e ������ */

	printf("Enter e:");				/* ��ʾ�û����뾫�� */
	scanf("%lf", &e);
	pi = funpi(e);					/* ���ú������ѷ���ֵ��ֵ��pi */
	printf("pi = %.4f\n", pi);
	return 0;
}
double funpi(double e)					/* �������pi�ĺ��� */
{
	int denominator, flag;
	double item, sum;

	flag = 1;       				/* flag ��ʾ�� i ��ķ��ţ���ʼΪ�� */
	denominator = 1;				/* denominator��ʾ�� i ��ķ�ĸ����ʼΪ1 */
	item = 1.0;        				/* item �д�ŵ� i ���ֵ����ֵȡ 1 */
	sum = 0;            			/* ���ۼӺ� pi �ĳ�ֵΪ0 */

									/*  ��|item| �� eʱ��ִ��ѭ�� */
	while (fabs(item) >= e) {
		item = flag * 1.0 / denominator;    	/* ����� i ���ֵ */
		sum = sum + item;        				/* �ۼӵ� i ���ֵ */
		flag = -flag;   	 					/* �ı���ţ�Ϊ��һ��ѭ����׼�� */
		denominator = denominator + 2;			/* ��ĸ����2 ��Ϊ��һ��ѭ����׼�� */
	}
	return sum * 4;
}
#endif

#if 0
/*����5-4����100���ڵ�ȫ��������ÿ�����10������������ֻ�ܱ�1��������������������1����������2��������Ҫ����͵��ú���prime(m)�ж�m�Ƿ�Ϊ��������mΪ����ʱ����1�����򷵻�0��*/

/* ʹ�ú�����100���ڵ�ȫ������ */
#include <stdio.h>
#include <math.h>					/* ������ƽ������������Ҫ������ѧ�� */
int main(void)
{
	int count, m;
	int prime(int m);				/* �������� */

	count = 0;						/* count��¼�����ĸ��������ڿ��������ʽ */
	for (m = 2; m <= 100; m++) {
		if (prime(m) != 0) {		      	/* ����prime(m)�ж�m�Ƿ�Ϊ���� */
			printf("%6d", m);     	/* ���m */
			count++;            	/* �ۼ��Ѿ�������������� */
			if (count % 10 == 0)  printf("\n");   /* ���count��10�ı��������� */
		}
	}
	printf("\n");
}
/* �����ж������ĺ��������m�������򷵻�1��"��"�������򷵻�0��"��"��*/
int prime(int m)
{
	int i, n;

	if (m == 1) return 0;   	    /* 1��������������0 */
	n = sqrt(m);
	for (i = 2; i <= n; i++)
		if (m % i == 0) {   		/* ���m�������� */
			return 0;			/* ����0 */
		}

	return 1;					/* m������������1 */
}
#endif

#if 0
/*����5-5�����5֮�ڵ����ֽ�������*/

/* ������ֽ����� */
#include <stdio.h>
void pyramid(int n);					/* �������� */
int main(void)
{
	pyramid(5);								/* ���ú�����������ֽ����� */
	return 0;
}
void pyramid(int n)							/* �������� */
{
	int i, j;

	for (i = 1; i <= n; i++) {				/* ��Ҫ��������� */
		for (j = 1; j <= n - i; j++) 			/* ���ÿ����ߵĿո� */
			printf(" ");
		for (j = 1; j <= i; j++)  			/* ���ÿ�е����� */
			printf(" %d ", i);
		putchar('\n');
	}
}
#endif

#if 0
/*  ����5-6���ֱ���������������ʵ�����鲿��������������֮����֮���� */
#include<stdio.h> 
float result_real, result_imag;			/*  ȫ�ֱ��������ڴ�ź������  */
										/*  ��������  */
void complex_prod(float real1, float imag1, float real2, float imag2);
void complex_add(float real1, float imag1, float real2, float imag2);
int main(void)
{
	float imag1, imag2, real1, real2;		/* ����������ʵ���鲿���� */

	printf("Enter 1st complex number(real and imaginary): ");
	scanf("%f%f", &real1, &imag1); 			/* �����һ������ */
	printf("Enter 2nd complex number(real and imaginary): ");
	scanf("%f%f", &real2, &imag2); 			/* ����ڶ������� */
	complex_add(real1, imag1, real2, imag2);	/* ����֮�� */
	printf("addition of complex is %f+%fi\n", result_real, result_imag);
	complex_prod(real1, imag1, real2, imag2); 	/* ����֮�� */
	printf("product of complex is %f+%fi\n", result_real, result_imag);

	return 0;
}

/* ��������֮�ͺ��� */
void complex_add(float real1, float imag1, float real2, float imag2)
{
	result_real = real1 + real2;
	result_imag = imag1 + imag2;
}

/* ��������֮������ */
void complex_prod(float real1, float imag1, float real2, float imag2)
{
	result_real = real1*real2 - imag1*imag2;
	result_imag = real1*imag2 + real2*imag1;
}
#endif

#if 0
/*����5-7��ȫ�ֱ������塣*/

#include <stdio.h>
int x;					/* ����ȫ�ֱ���x */
int f();
int main(void)
{
	int a = 1;

	x = a;   			/* ��ȫ�ֱ��� x ��ֵ1 */
	a = f();  			/* a��ֵΪ4 */
	{
		int b = 2;
		b = a + b;		/* b��ֵΪ6 */
		x = x + b;		/* ȫ�ֱ������� */
	}
	printf("%d %d", a, x);

	return 0;
}

int f()
{
	int x = 4;			/* xΪ�ֲ��������ڱ������У�ȫ�ֱ���x�������� */

	return x;
}
#endif

#if 0
/* ����5-8���ú���ʵ�ֲ����ֽ���ˡ�������������ͣ�1���룬2֧����0������������������������ֽ�ʣ������β���ֱ���������Ϊ0������Ҫ���岢���ú����������ֽ��������ֽ�֧���ֱ��ò�ͬ����ʵ�֡� */
#include<stdio.h> 
float cash;						/* ����ȫ�ֱ����������ֽ���� */
void income(float number), expend(float number);	/* ��������  */
int main(void)
{
	int choice;
	float value;

	cash = 0;							/* ��ʼ���=0 */
	printf("Enter operate choice(0--end, 1--income, 2--expend):");
	scanf("%d", &choice);				/* ����������� */
	while (choice != 0) {	/*  ����������Ϊ0��ѭ������  */
		if (choice == 1 || choice == 2) {
			printf("Enter cash value:"); 	/* ��������ֽ�� */
			scanf("%f", &value);
			if (choice == 1)
				income(value);		/* �������ã������ֽ����� */
			else
				expend(value);		/* �������ã������ֽ�֧�� */
			printf("current cash:%.2f\n", cash);
		}
		printf("Enter operate choice(0--end, 1--income, 2--expend):");
		scanf("%d", &choice);		/* ��������������� */
	}

	return 0;
}

/* ��������ֽ����뺯�� */
void income(float number)
{
	cash = cash + number;	/*  �ı�ȫ�ֱ���cash  */
}

/* ��������ֽ�֧������ */
void expend(float number)
{
	cash = cash - number;	/*  �ı�ȫ�ֱ���cash  */
}
#endif

#if 0
/* ����5-9������������n�����1��~n����ֵ��Ҫ���岢���ú���̬�����ĺ���fact_s(n)����n���� */
#include <stdio.h>
double fact_s(int n);
int main(void)
{
	int i, n;

	printf("Input n:");
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		printf("%3d!=%.0f\n", i, fact_s(i));	/* ���i��i! */

	return 0;
}

double fact_s(int n)
{
	static double f = 1;			/* ���徲̬��������һ�θ�ֵΪ0 */
	f = f*n;						/* ����һ�ε���ʱ��ֵ�ϳ�n */

	return(f);
}
#endif