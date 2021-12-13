#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include"recuadrar.h"

//////////////////////************************Recepcion**********************************//////////////////////////

struct Fecha
{
  int dd;
  int mm;
  int aaaa;	
};

struct Cliente
{
 char NombreCliente [60];
 char Domicilio [60];
 int DNI_Cliente; 
 char localidad[60];
 Fecha fechanacimiento;
 float Peso;
 int Telefono;
};

struct CuentasDeUsuarios
{
	char user[10];
	char password [32];
	char ApellidoNombre[60];
};

struct Profesionales
{
	char ApellidoNombre[60];
	int IdProfesional;
	int DNI;
	int Telefono;
};

struct Turnos
{
	int IdProfesional;
	Fecha fecha;
	int dniCliente;
	int edadCliente;
	char DetalleAtencion[380];
	int fueatendido; //-1) si -2) no
};

int MenuDeOpciones()
{      
    system("cls");
    
	int opc;
	    //recuadro principal 
	for (int x=1; x<=100; x++)
	{  
		gotoxy(x,0); printf("%c",177);//linea horizontal superior
		gotoxy(x,24); printf("%c",177);//linea horizontal inferior
		
		if(x<=24)
		{
			gotoxy(1,x); printf("%c",177); //linea vertical izquierda
			gotoxy(100,x); printf("%c",177); //linea vertical derecha
		}
	}
		//recuadro titulo
	for(int x=0; x<=50; x++)
	{
	    gotoxy(x+25,2); printf("%c",177);
		gotoxy(x+25,4); printf("%c",177);
		
		if(x<=4 && x>=2)
		{
			gotoxy(25,x); printf("%c",177); 
			gotoxy(75,x); printf("%c",177); 
		}
	}
	
	gotoxy(34,3); printf("MODULO 2:  Recepcion \n\n");//titulo del modulo del programa
	gotoxy(2,6); printf("1)Iniciar de sesion");
	gotoxy(2,8); printf("2)Registrar cliente");
	gotoxy(2,10); printf("3)Registrar un turno");
	gotoxy(2,12); printf("4)Informe de atenciones por Profesional y Fecha");
	gotoxy(2,14); printf("5)Cerrar la aplicacion");
	gotoxy(2,17); printf("Ingrese Opcion: ");
	scanf("%d",&opc);
	return(opc);
}



main()
{
	system("COLOR 1F"); //colores de la recepcion 1: AZUL - F: BLANCO BRILLANTE
	int opcionmenu, bandera=0;
	do{
	opcionmenu=MenuDeOpciones();
	switch(opcionmenu)
	{
		case(1): Iniciosesion(bandera);
		break;
		
		case(2): RegistrarCliente(bandera);
		break;
		
		case(3): RegistrarTurno(bandera);
		break;
		
		case(4): InformeDeAtenciones(bandera);
		break;
		
		case(5): fin();
		break;
		
		default: error();
		break;
	}
   }while(opcionmenu!=5);
	
}
