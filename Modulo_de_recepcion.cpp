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

void Iniciosesion(int &bandera)
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
	
	char nameuser[10], passuser[32]; 
	FILE *arch2;int clavecorrecta, usuariocorrecto; char usuario[32];
	CuentasDeUsuarios usu;
	
	arch2=fopen("Recepcionistas.dat","r+b");
	
	if(arch2==NULL)
	{
		gotoxy(2,2); printf("Error en el programa");
		arch2=fopen("Recepcionistas.dat","a+b");
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
				bandera=1;
				strcpy(usuario,usu.ApellidoNombre);
			}
			
		fread(&usu,sizeof(CuentasDeUsuarios),1,arch2);
		}
		if(bandera==1)
		{
			gotoxy(2,4);printf("                                                    ");
			gotoxy(2,5); printf("                                                    ");
			gotoxy(2,4); printf(" Bienvenido: ");
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
	fclose(arch2);
}

void RegistrarCliente(int bandera)
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
	/////********************Declaracion de variables**********************////
	FILE *arch4; Cliente reg;
	/////********************Apertura de archivos**********************////
	arch4=fopen("Clientes.dat","a+b");
	/////********************Verificacion de archivos**********************////
	if(arch4==NULL)
	{
		gotoxy(2,2);printf("*Ha habido errores en el sistema*"); 
		gotoxy(2,3); exit(1);
	}
	/////********************Verificacion de inicio de sesion**********************////
	if(bandera==0)
	{
		gotoxy(2,4); printf("No ha iniciado sesion");
		fclose(arch4);
		gotoxy(2,5); system("pause");
		gotoxy(2,4);printf("                                                                      ");
		gotoxy(2,5);printf("                                                                             ");
		
	}
	else
	{ /////********************Registro de Clientes**********************////
		
		gotoxy(2,4);printf("Ingrese nombre de la cliente: ");_flushall(); 
		gotoxy(2,5);gets(reg.NombreCliente);
		gotoxy(2,6);printf("Ingrese DNI del Cliente: "); scanf("%d",&reg.DNI_Cliente);
		gotoxy(2,7);printf("Domicilio: "); _flushall();
		gotoxy(2,8);gets(reg.Domicilio);
		gotoxy(2,9);printf("Localidad: "); _flushall();
		gotoxy(2,10);gets(reg.localidad);
		gotoxy(2,11);printf("Telefono: "); scanf("%d",&reg.Telefono);
		gotoxy(2,12);printf("Peso en Kg: "); scanf("%f",&reg.Peso);
		gotoxy(2,13);printf("Fecha de nacimiento: ");
		gotoxy(2,14);printf("Dia: "); scanf("%d",&reg.fechanacimiento.dd);
		gotoxy(2,15);printf("Mes: "); scanf("%d",&reg.fechanacimiento.mm);
		gotoxy(2,16);printf("Anio: "); scanf("%d",&reg.fechanacimiento.aaaa);
		fwrite(&reg,sizeof(Cliente),1,arch4);
		gotoxy(2,18); printf("Se ha registrado la Cliente con exito");
		fclose(arch4);
		gotoxy(2,20); system("pause");
	}
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
