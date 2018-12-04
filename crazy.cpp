#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <locale.h>

double F(double x)
{
    double f;
    f=log(log(x));
    return f;
}

double Y(double x)
{
    double y;
    y=1/(x*log(x));
    return y;
}

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
    int a=2, b=3; 
    int n=30; 
    double time; 
    double E=0.0001; 
    double Itog, IMethod=0, IMethodTwice;
    
    setlocale(LC_ALL, "RUSSIAN");
    system("color F0");
    
    Itog=F(b)-F(a); 
    
    do  
    {
        IMethod=Middle_Rectangle_Method(a,b,n);
        IMethodTwice=Middle_Rectangle_Method(a,b,n*2);
        n=2*n;
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
