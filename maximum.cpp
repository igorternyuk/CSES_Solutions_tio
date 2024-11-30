#include <iostream>
#include <cmath>
#include <functional>

#define	 _g_	0.38196601

/************************************************************************/
/*				Поиск максимума функции одной переменной				*/
/*						методом золотого сечения						*/
/************************************************************************/
/*-----------------------------------------------------------------------
    BBOДИMAЯ ИHФOPMAЦИЯ:
   ======================   
   F  - оптимизируемая функция возвращает значение 
		функции для заданного аргумент;
   i  - признак:
		0 - поиск с определением начального интервала
		1 - поиск в заданном интервале
   x0 - начальная точка;
   h0 - начальный шаг;
   ex - точность по аргументу;
   n  - коэффициент увеличения шага поиска.;
   max_N - максимальное колличество итераций;

    РЕЗУЛЬТАТ
   ======================   
   абсцисса максимума функции
------------------------------------------------------------------------*/
double GoldSection (std::function<double(double)> F, int i, double x0,
						double h0, double ex, double n, int max_N )

{
	double  dx = h0, x1 = x0, x3 = x0 + dx,
			y1, y2, f1, f2, f3;
	int     N = 0;

	if (!i)
	{
		f3 = F(x3); f2 = F(x1);
		if (f3 > f2)
			x1 = x3;
		else
		{
			dx *= (-n); x1 += dx; f1 = f3;	f3 = F(x1);
		}
		while (f3 > f2)
		{
			dx *= n;	x1 += dx; f1 = f2;	f2 = f3;	f3 = F(x1);
		}
		dx *= (1.+ 1./n); x3 = x1; x1 = x3 - dx;
	}
	y1 = x1 + _g_*dx; f1 = F(y1);
	y2 = x3 - _g_*dx; f2 = F(y2);

	while (fabs (dx) >= ex)
	{
		if (++N > max_N) 
			break;
		if (f1 > f2)
		{
			x3 = y2;		y2 = y1;			f2 = f1;
			dx = x3 - x1;	y1 = x1 + _g_*dx;	f1 = F(y1);
		}
		else
		{
			x1 = y1;		y1 = y2;			f1 = f2;
			dx = x3 - x1;	y2 = x3 - _g_*dx;	f2 = F(y2);
		}
	}
	return .5*(x1 + x3);
}

/*-----------------------------------------------------------------------    
    Ввoдимaя инфopмaция:
  ======================   
   F  - oптимизиpуeмaя функция;
   XX - нaчaльнaя тoчкa;
   DD - нaчaльный шaг;
   E  - точнocть;
   max_N - максимальное колличество итераций

    Результат
  ======================   
   aбcциcca мaкcимумa функции;
------------------------------------------------------------------------*/
double DSKPowell(std::function<double(double)> F, double XX, double DD, double E, int max_N)
{
	int    N = 2;
	double D = DD, F1, F2, F3, X1, X2, X3, X, Y, XM, YM;

	X  = XX;	F2 = F(X);
	X += D;		F3 = F(X);
	if (F3 <= F2)
	{
		D  =-D;		X += D;
		Y  = F3;	F3 = F2;	F2 = Y;
	}
	do
	{
		D += D;		X += D;
		F1 = F2;	F2 = F3;	F3 = F(X); 	N++;
	} while (F3 > F2);

	X3 = X;	XM = X - .5*D;	X2 = X - D;	X1 = XM - D;
	do
	{
		YM = F(XM);		N++;
		if (YM <= F2)					X  = XM, XM = X2, X2 = X, Y = YM, YM = F2, F2 = Y;
		if ((XM - X1)*(X2 - XM) > 0.)	X3 = X2, F3 = F2; 
		else							X1 = X2, F1 = F2;

		X2	= XM;	F2 = YM;
		X	= (X2 - X3)*F1 + (X3 - X1)*F2 + (X1 - X2)*F3;
		if (X == 0.) break;

		XM	= .5*((X2*X2 - X3*X3)*F1 + (X3*X3 - X1*X1)*F2 + (X1*X1 - X2*X2)*F3)/X;
		if (N > max_N)  
			break;
	} 
	while (fabs (X2 - XM) > E);

	return XM;
}

double Bisection(std::function<double(double)> fun, double X1, double X2, double& X, double tol, double iterMax)
{
	double F1 = fun(X1);
	double F2 = fun(X2);

	while (fabs(X1 - X2) > tol && iterMax--)
	{
		X = 0.5 * (X1 + X2);
		double F = fun(X);
		if (F * F1 > 0)
		{
			X1 = X;
			F1 = F;
		}
		else if (F * F2 > 0)
		{
			X2 = X;
			F2 = F;
		}
		else
			break;
	}

	X = 0.5 * (X1 + X2);
	return iterMax > 0;
}

double func(double x)
{
    return sqrt((1-x * x) / (1 - log(x)));
}

double dF(double x)
{
    return 1 / (2.0 * func(x)) * (-3 * x + 2 * x * log(x) + 1 / x) / (1 - log(x)) / (1 - log(x));
}

int main()
{
    double eps = 1.0e-8;
    double a = 0.0 + eps, b = 1.0 - eps, Xmax;
    
    if(Bisection(dF, a, b, Xmax, eps, 200))
    {
        double Fmax = func(Xmax);
        std::cout << "Xmax = " << Xmax << " Fmax = " << Fmax << std::endl;
    }
    //double Xmax = GoldSection(-func, 0, 0.01, 0.0001, 1.0e-6, 2.0, 100);
    //double Fmax = func(Xmax);
    
    return 0;
}