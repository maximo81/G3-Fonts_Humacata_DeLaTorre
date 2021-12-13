#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include"recuadrar.h"

//######################################*******Espacios*****#####################################################//
struct Fecha
{
  int dd;
  int mm;
  int aaaa;	
};

struct Profesionales
{
	char ApellidoNombre[60];
	int IdProfesional;
	int DNI;
	int Telefono;
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

struct Turnos
{
	int IdProfesional;
	Fecha fecha;
	int dniCliente;
	int edadCliente;
	char DetalleAtencion[380];
	int fueatendido; //-1) si -2) no
};

struct CuentasDeUsuarios
{
	char user[10];
	char password [32];
	char ApellidoNombre[60];
};

int MENUPRINCIPAL()
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
	
	gotoxy(34,3); printf("MODULO 1: Espacios \n\n");//titulo del modulo del programa
	
	gotoxy(2,6); printf("1)Iniciar Sesion");
	gotoxy(2,8); printf("2)Visualizar lista de espera de turnos [informe]");
	gotoxy(2,10); printf("3)Registrar evolucion del Cliente");
	gotoxy(2,12); printf("4)Cerrar la aplicacion");
	gotoxy(2,16); printf("Ingrese Opcion: ");
	scanf("%d",&opc);
	return(opc);
    	
	
}


void InicioDeSesion(int &bandera)
{
	system("cls");
	 //recuadro principal 
	for (int x=1; x<=100; x++)
	{  
		gotoxy(x,0); printf("%c",177);
		gotoxy(x,24); printf("%c",177);
		
		if(x<=24)
		{
			gotoxy(1,x); printf("%c",177); 
			gotoxy(100,x); printf("%c",177); 
		}
	}
	
	char nameuser[10], passuser[32], usuario[30]; 
	FILE *arch2;int clavecorrecta, usuariocorrecto;
	CuentasDeUsuarios usu;
	
	arch2=fopen("Recepcionistas.dat","a+b");
	
	if(arch2==NULL)
	{
		gotoxy(2,2); printf("Error en el programa");
	}
	else
	{
		gotoxy(2,4); printf("Ingrese nombre de usuario: ");
		_flushall();
		gets(nameuser);
		gotoxy(2,5); printf("Clave de usuario: ");
		_flushall();
		gets(passuser);
		bandera=0;
		fread(&usu,sizeof(CuentasDeUsuarios),1,arch2);
		
		while(!feof(arch2))
		{
			usuariocorrecto=strcmp(nameuser, usu.user);
			clavecorrecta=strcmp(passuser, usu.password);
			
			if(clavecorrecta==0&&usuariocorrecto==0)
			{
				strcpy(usuario,usu.ApellidoNombre);
				bandera=1;
			}
			
			fread(&usu,sizeof(CuentasDeUsuarios),1,arch2);	
		}
		
		if(bandera==1)
		{
			strcat(usuario," !");
			gotoxy(2,4);printf("                                                    ");
			gotoxy(2,5); printf("                                                    ");
			gotoxy(2,4); printf("Bienvenido/a: ");
			gotoxy(16,4);puts(usuario);
			gotoxy(2,5); system("pause");
			gotoxy(2,4);printf("                                                               ");
			gotoxy(2,5); printf("                                                              ");
		}
		
		if(bandera==0)
		{
			
			gotoxy(2,4);printf("                                                    ");
			gotoxy(2,5); printf("                                                    ");
			gotoxy(2,4); printf("Clave o usuario incorrecto");
			gotoxy(2,5); system("pause");
			gotoxy(2,4);printf("                                                    ");
			gotoxy(2,5); printf("                                                    ");
			
		}
		
	}
	gotoxy(2,20); system("pause");
	
}













main()
{
	system("COLOR 1F"); //consultorio, colores: 1: AZUL - F: BLANCO BRILLANTE
	
	int opcionmenu, bandera=0;
	do{
		opcionmenu=MENUPRINCIPAL();
		switch(opcionmenu)
		{
			case(1): InicioDeSesion(bandera);
			break;
			
			case(2): Listadeespera(bandera);
			break;
			
			case(3): RegistroEvolucionCliente(bandera);
			break;
			
			case(4): fin();
			break;
			
			default: error();
			break;
		}
   }while(opcionmenu!=4);
	
}
