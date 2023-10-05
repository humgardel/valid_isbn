#include <conio.h>
#include <stdio.h>
#include <math.h>
void ISBN(double codigo, int A[13]);
bool ISBNValido(int A[13]);
void main()
{
	double codigo=978316148410;
	int A[13];
	//printf("Ingrese codigo: ");
	//scanf("%f",&codigo);
	printf("\n\n%0.f",codigo);
	for(int i=0;i<13;i++)
		A[i]=0;
	ISBN(codigo, A);
	printf("\n");
	for(int j=0;j<=12;j++)
	{
		printf("%d ",A[j]);
	}
	if(ISBNValido(A))
		printf("\nCodigo Valido");
	else
		printf("\nCodigo Invalido");
	getch();
}
void ISBN(double codigo, int A[13])
{
	double rest=codigo;
	double num=0.0;
	for(int i=11;i>=0;i--)
	{
		num=fmod(rest,10);
		//printf("%d",num);
		rest=rest/10;
		A[i]=(int)num;
	}
	A[12]=(int)rest;
}
bool ISBNValido(int A[13])
{
	int suma=0, residuo=0, resultado=0, verificador=0;
	for(int i=0;i<12;i=i+2)
	{
		suma+=A[i]*1;
	}
	for(int i=1;i<12;i=i+2)
	{
		suma+=A[i]*3;
	}
	residuo=suma%10;
	resultado=10-residuo;
	if(resultado==10)
		verificador=0;
	else
		verificador=resultado;
	if (verificador==A[12])
		return true;
	else
		return false;
}



