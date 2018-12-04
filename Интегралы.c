#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <locale.h>

/*Функция первообразной для более точного вычисления*/
double F(double x)
{
    double f;
    f=log(log(x));
    return f;
}

/*Подынтегральная функция*/
double Y(double x)
{
    double y;
    y=1/(x*log(x));
    return y;
}

/*Метод средних прямоугольников*/
double Middle_Rectangle_Method(int a, int b, int z)
{
    double h, xi;
    double S=0.0, x;
    int i;
    h=(b-a)*1.0/z;
    xi=a+h/2;
    for(i=0;i<=z-1;i++)
    {
        x=xi+i*h;
        S=S+Y(x)*h;
    }
    return S;
}

void main()
{
    int a=2, b=3; //Пределы интегрирования
    int n=30; //Начальное число разделений
    double time; //Погрешность вычислений
    double E=0.0001; //Заданная погрешность
    double Itog, IMethod=0, IMethodTwice; //Значения интеграла
    
    setlocale(LC_ALL, "RUSSIAN");
    system("color F0");
    
    Itog=F(b)-F(a); //Точное значение интеграла
    
    do  
    {
        /*Интеграл вычисляется при числе разделений, равном 30*/
        IMethod=Middle_Rectangle_Method(a,b,n);
        /*Интеграл вычисляется при числе разделений, равном 60*/
        IMethodTwice=Middle_Rectangle_Method(a,b,n*2);
        /*Удвоение числа шагов для последующих итераций цикла*/
        n=2*n;
        /*Вычисление погрешности вычислений*/
        time=fabs(IMethodTwice-IMethod);
    } while (time>=E);
    
    
    printf("\n\t\tДано: \n");
    printf("\n\tИнтеграл: ");
    printf("\n\t\t  dx ");
    printf("\n\t\t------");
    printf("\n\t\tx*ln(x) ");
    printf("\n\tНижний предел интегрирования: 2");
    printf("\n\tВерхний предел интегрирования: 3\n\n");
    
    printf("\n\t\tИтог вычислений: \n");
    printf("\tТочное значение интеграла: %f\n", Itog);
    printf("\tПриближенное значение интеграла: %f\n", IMethodTwice);
    printf("\tКоличество разделений: %d\n", n);
    getch();
}
