// cat_chapter5_example.cpp : 定义控制台应用程序的入口点。
#include "stdafx.h"

//////////第1部分. 三种注释方法的说明。注释就是代码不能编译和运行，打开注释后才能。
//尝试打开注释和注释：下面四行看操作后的颜色变化，1种删除和加上//，2种删除/**/和重新加上，3种0改成1，再改成0
//#include <stdio.h>
/* #include <stdio.h> */
#if 0
#include <stdio.h>
#endif
//三种注释方式：一是注释目标行前用//；二是注释目标放到/*与*/之间；三是注释目标放到#if 0与#endif之间。
//打开注释方法：前两种删掉对应的符号即//及/**/, 最后一种0改成1。



/////////////第2部分. 第五章猫工程例题，每个例题都放到#if 0与#endif之间。
////////调试某例题时：改成#if 1即可，调试完后改成#if 0即注释掉该例题。 再调试别的例题，重复同样的操作。

#if 1
/*【例5-1】输入圆柱的高和半径，求圆柱体积，volume=3.1415926*r*r*h。要求定义和调用函数cylinder (r, h )计算圆柱体的体积。 */

/* 计算圆柱体积 */
#include <stdio.h>
double cylinder(double r, double h);		/* 函数声明*/
int main(void)
{
	double height, radius, volume;

	printf("Enter radius and height: ");	    /* 输入提示 */
	scanf("%lf%lf", &radius, &height);		    /* 输入圆柱的半径和高度 */
	volume = cylinder(radius, height);			/* 调用函数，返回值赋给volume */
	printf("Volume = %.3f\n", volume);			/*输出圆柱的体积 */
	return  0;
}

/* 定义求圆柱体积的函数 */
double cylinder(double r, double h)
{
	double result;
	result = 3.1415926 * r * r * h;    			/* 计算圆柱体积 */
	return result;								/* 返回结果 */
}
#endif

#if 0
/*【例5-2】定义一个判断奇偶数的函数even(n)，当n为偶数时返回1，否则返回0。*/

int even(int n)；
int main(void)
{
	even(10);
	return  0;
}
/* 判断奇偶数的函数 */
int even(int n)				/* 函数首部 */
{
	if (n % 2 == 0) 			/* 判别奇偶数 */
		return 1;			/* 偶数返回1 */
	else
		return 0;			/* 奇数返回0 */
}
#endif

#if 0
/*【例5-3】 输入精度e，使用格里高利公式求π的近似值，精确到最后一项的绝对值小于e。要求定义和调用函数funpi(e)求π的近似值。*/

/*  用格里高利公式计算π的近似值，精度为e  */
#include <stdio.h>
#include <math.h>
double funpi(double e);			/* 函数声明 */
int main(void)
{
	double e, pi;     				/* e 代表精度 */

	printf("Enter e:");				/* 提示用户输入精度 */
	scanf("%lf", &e);
	pi = funpi(e);					/* 调用函数，把返回值赋值给pi */
	printf("pi = %.4f\n", pi);
	return 0;
}
double funpi(double e)					/* 定义计算pi的函数 */
{
	int denominator, flag;
	double item, sum;

	flag = 1;       				/* flag 表示第 i 项的符号，初始为正 */
	denominator = 1;				/* denominator表示第 i 项的分母，初始为1 */
	item = 1.0;        				/* item 中存放第 i 项的值，初值取 1 */
	sum = 0;            			/* 置累加和 pi 的初值为0 */

									/*  当|item| ≥ e时，执行循环 */
	while (fabs(item) >= e) {
		item = flag * 1.0 / denominator;    	/* 计算第 i 项的值 */
		sum = sum + item;        				/* 累加第 i 项的值 */
		flag = -flag;   	 					/* 改变符号，为下一次循环做准备 */
		denominator = denominator + 2;			/* 分母递增2 ，为下一次循环做准备 */
	}
	return sum * 4;
}
#endif

#if 0
/*【例5-4】求100以内的全部素数，每行输出10个。素数就是只能被1和自身整除的正整数，1不是素数，2是素数。要求定义和调用函数prime(m)判断m是否为素数，当m为素数时返回1，否则返回0。*/

/* 使用函数求100以内的全部素数 */
#include <stdio.h>
#include <math.h>					/* 调用求平方根函数，需要包含数学库 */
int main(void)
{
	int count, m;
	int prime(int m);				/* 函数声明 */

	count = 0;						/* count记录素数的个数，用于控制输出格式 */
	for (m = 2; m <= 100; m++) {
		if (prime(m) != 0) {		      	/* 调用prime(m)判断m是否为素数 */
			printf("%6d", m);     	/* 输出m */
			count++;            	/* 累加已经输出的素数个数 */
			if (count % 10 == 0)  printf("\n");   /* 如果count是10的倍数，换行 */
		}
	}
	printf("\n");
}
/* 定义判断素数的函数，如果m是素数则返回1（"真"）；否则返回0（"假"）*/
int prime(int m)
{
	int i, n;

	if (m == 1) return 0;   	    /* 1不是素数，返回0 */
	n = sqrt(m);
	for (i = 2; i <= n; i++)
		if (m % i == 0) {   		/* 如果m不是素数 */
			return 0;			/* 返回0 */
		}

	return 1;					/* m是素数，返回1 */
}
#endif

#if 0
/*【例5-5】输出5之内的数字金字塔。*/

/* 输出数字金字塔 */
#include <stdio.h>
void pyramid(int n);					/* 函数声明 */
int main(void)
{
	pyramid(5);								/* 调用函数，输出数字金字塔 */
	return 0;
}
void pyramid(int n)							/* 函数定义 */
{
	int i, j;

	for (i = 1; i <= n; i++) {				/* 需要输出的行数 */
		for (j = 1; j <= n - i; j++) 			/* 输出每行左边的空格 */
			printf(" ");
		for (j = 1; j <= i; j++)  			/* 输出每行的数字 */
			printf(" %d ", i);
		putchar('\n');
	}
}
#endif

#if 0
/*  【例5-6】分别输入两个复数的实部与虚部，计算两个复数之和与之积。 */
#include<stdio.h> 
float result_real, result_imag;			/*  全局变量，用于存放函数结果  */
										/*  函数声明  */
void complex_prod(float real1, float imag1, float real2, float imag2);
void complex_add(float real1, float imag1, float real2, float imag2);
int main(void)
{
	float imag1, imag2, real1, real2;		/* 两个复数的实、虚部变量 */

	printf("Enter 1st complex number(real and imaginary): ");
	scanf("%f%f", &real1, &imag1); 			/* 输入第一个复数 */
	printf("Enter 2nd complex number(real and imaginary): ");
	scanf("%f%f", &real2, &imag2); 			/* 输入第二个复数 */
	complex_add(real1, imag1, real2, imag2);	/* 求复数之和 */
	printf("addition of complex is %f+%fi\n", result_real, result_imag);
	complex_prod(real1, imag1, real2, imag2); 	/* 求复数之积 */
	printf("product of complex is %f+%fi\n", result_real, result_imag);

	return 0;
}

/* 定义求复数之和函数 */
void complex_add(float real1, float imag1, float real2, float imag2)
{
	result_real = real1 + real2;
	result_imag = imag1 + imag2;
}

/* 定义求复数之积函数 */
void complex_prod(float real1, float imag1, float real2, float imag2)
{
	result_real = real1*real2 - imag1*imag2;
	result_imag = real1*imag2 + real2*imag1;
}
#endif

#if 0
/*【例5-7】全局变量定义。*/

#include <stdio.h>
int x;					/* 定义全局变量x */
int f();
int main(void)
{
	int a = 1;

	x = a;   			/* 对全局变量 x 赋值1 */
	a = f();  			/* a的值为4 */
	{
		int b = 2;
		b = a + b;		/* b的值为6 */
		x = x + b;		/* 全局变量运算 */
	}
	printf("%d %d", a, x);

	return 0;
}

int f()
{
	int x = 4;			/* x为局部变量，在本函数中，全局变量x不起作用 */

	return x;
}
#endif

#if 0
/* 【例5-8】用函数实现财务现金记账。先输入操作类型（1收入，2支出，0结束），再输入操作金额，计算现金剩余额，经多次操作直到输入操作为0结束。要求定义并调用函数，其中现金收入与现金支出分别用不同函数实现。 */
#include<stdio.h> 
float cash;						/* 定义全局变量，保存现金余额 */
void income(float number), expend(float number);	/* 函数声明  */
int main(void)
{
	int choice;
	float value;

	cash = 0;							/* 初始金额=0 */
	printf("Enter operate choice(0--end, 1--income, 2--expend):");
	scanf("%d", &choice);				/* 输入操作类型 */
	while (choice != 0) {	/*  若输入类型为0，循环结束  */
		if (choice == 1 || choice == 2) {
			printf("Enter cash value:"); 	/* 输入操作现金额 */
			scanf("%f", &value);
			if (choice == 1)
				income(value);		/* 函数调用，计算现金收入 */
			else
				expend(value);		/* 函数调用，计算现金支出 */
			printf("current cash:%.2f\n", cash);
		}
		printf("Enter operate choice(0--end, 1--income, 2--expend):");
		scanf("%d", &choice);		/* 继续输入操作类型 */
	}

	return 0;
}

/* 定义计算现金收入函数 */
void income(float number)
{
	cash = cash + number;	/*  改变全局变量cash  */
}

/* 定义计算现金支出函数 */
void expend(float number)
{
	cash = cash - number;	/*  改变全局变量cash  */
}
#endif

#if 0
/* 【例5-9】输入正整数n，输出1！~n！的值。要求定义并调用含静态变量的函数fact_s(n)计算n！。 */
#include <stdio.h>
double fact_s(int n);
int main(void)
{
	int i, n;

	printf("Input n:");
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		printf("%3d!=%.0f\n", i, fact_s(i));	/* 输出i和i! */

	return 0;
}

double fact_s(int n)
{
	static double f = 1;			/* 定义静态变量，第一次赋值为0 */
	f = f*n;						/* 在上一次调用时的值上乘n */

	return(f);
}
#endif