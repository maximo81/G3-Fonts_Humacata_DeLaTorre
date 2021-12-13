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

void Listadeespera(int bandera)
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
	//----------------Declaracion de las variables--------------------------------------///	
	FILE *arch4, *arch3; Cliente reg4; Turnos reg3; int IdProfesional, IdProfesionalcorrecta, Dia, Mes, Anio, hayturnos;
	
	///--------------------------------Apertura de Archivos -----------------------------------///	
	arch4=fopen("Clientes.dat","rb");
	arch3=fopen("Turnos.dat","rb");
	
	//--------------------------------Verificacion de Archivos--------------------------------------///	
	if(arch3==NULL|| arch4==NULL)
	{
		printf("Error en el programa, Archivos no cargados");
	}
	//--------------------------------Control de inicio de sesion--------------------------------------///	
	if(bandera==0)
	{
		gotoxy(2,4); printf("No ha iniciado sesion");
		gotoxy(2,5); system("pause");
		gotoxy(2,4);printf("                                                                      ");
		gotoxy(2,5);printf("                                                                             ");
	}
	else
	{//--------------------------------Solicitud de los datos--------------------------------------	
	
		gotoxy(2,4);printf("Ingrese su ID por favor: ") ;scanf("%d",&IdProfesional);
		gotoxy(2,4);printf("                                                           ");
		gotoxy(2,4);printf("Fecha: ");	
		gotoxy(2,5);printf(" Dia: ");scanf("%d",&Dia);
		gotoxy(2,6);printf(" Mes: ");scanf("%d",&Mes);
		gotoxy(2,7);printf("Anio: ");scanf("%d",&Anio);
		 
		//--------------------------------Verificacion de los datos en los archivos--------------------------------------///	
		hayturnos=0;
		IdProfesionalcorrecta=0;
		fread(&reg3,sizeof(Turnos),1,arch3);
		
		while(!feof(arch3))
		{
			if(IdProfesional==reg3.IdProfesional)	
			{
			  	IdProfesionalcorrecta=1;
			}
			fread(&reg3,sizeof(Turnos),1,arch3);
		}
		  
		if(IdProfesionalcorrecta==1)
		{
	  		rewind(arch3);
			fread(&reg3,sizeof(Turnos),1,arch3);
	        while(!feof(arch3))
	        {  
	            if(reg3.fueatendido==2 && reg3.IdProfesional==IdProfesional && Dia==reg3.fecha.dd && Mes==reg3.fecha.mm && Anio==reg3.fecha.aaaa)
	            {
			        rewind(arch4);
			        fread(&reg4,sizeof(Cliente),1,arch4);
			        
			        while(!feof(arch4))
			        {    ///--------------------------------Impresion de lista de espera--------------------------------------///	
			            gotoxy(2,8); printf("En espera: ");
				        if(reg4.DNI_Cliente=reg3.dniCliente)
		    		    {
			    		   	hayturnos=1;
						    gotoxy(2,10); printf("Cliente: ");
						    gotoxy(2,11); puts(reg4.NombreCliente);
						    gotoxy(2,12); printf("Fecha de turno: ");
						    gotoxy(2,13); printf("Dia: %d",reg3.fecha.dd);
						    gotoxy(2,14); printf("Mes: %d", reg3.fecha.mm);
						    gotoxy(2,15); printf("Anio: %d",reg3.fecha.aaaa);
						    gotoxy(2,16); printf("DNI: %d",reg3.dniCliente);
						    gotoxy(2,17); system("pause");
						    gotoxy(2,10); printf("                                                   ");
						    gotoxy(2,11); printf("                                                   ");
						    gotoxy(2,12); printf("                                                   ");
						    gotoxy(2,13); printf("                                                   ");
						    gotoxy(2,14);printf("                                                    ");
						    gotoxy(2,15); printf("                                                   ");
						    gotoxy(2,16);printf("                                                    ");
				        }
		 	          fread(&reg4,sizeof(Cliente),1,arch4);	
			        }
	            }
		        fread(&reg3,sizeof(Turnos),1,arch3);	
	        }
		}
		else
		{
		  	gotoxy(2,6); printf("ID incorrecta, Vuelva a intentarlo");
		}
		
		if(hayturnos==0)
		{
			gotoxy(2,8);  printf("No hay turnos en la fecha");
			gotoxy(2,9); system("pause");
		}
		gotoxy(2,8); printf("                                                   ");  
	    gotoxy(2,4); printf("                                                   ");
		gotoxy(2,5); printf("                                                   ");
		gotoxy(2,6); printf("                                                   ");
		gotoxy(2,7); printf("                                                   ");
		gotoxy(2,9); printf("                                                   ");  
	     
		fclose(arch3); fclose(arch4);
		
    }
	gotoxy(2,18); system("pause");
	
}

void RegistroEvolucionCliente(int bandera)
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
	
	FILE *arch4, *arch3;Cliente reg4; Turnos reg3;
	int Clienteencontrada=0, tamanoevolucion, evolucionregistrada,dniCliente,IdProfesional, IdProfesionalcorrecta, evolucionguardada, no=2, si=1;
	char nombreCliente[32], DetalleEvolucion[380]; bool atencion;
	
	arch4=fopen("Clientes.dat","r+b");
	arch3=fopen("Turnos.dat","r+b");
	
	///////////////////////////////////////////Verificar archivos correctos-----
	if(arch4==NULL|| arch3==NULL)
	{
		gotoxy(2,4); printf("*Error en el sistema-Archivos no cargados*");
	}	

	//////////////////////////////////////////// Verificar Inicio de Sesion-----
	if(bandera==0)
	{
		gotoxy(2,4); printf("No ha iniciado sesion");
		gotoxy(2,5); system("pause");
		gotoxy(2,4);printf("                                                                      ");
		gotoxy(2,5);printf("                                                                             ");
	}
	else
	{
		/////////////////////////////////////////////Verificar IdProfesional----
		gotoxy(2,4); printf("Ingrese su ID: "); scanf("%d",&IdProfesional);
		do
		{
			IdProfesionalcorrecta=0;
			fread(&reg3,sizeof(Turnos),1,arch3);
			rewind(arch3);
			
			while(!feof(arch3))
			{
				if(reg3.IdProfesional==IdProfesional)
				{
					IdProfesionalcorrecta=1;
				}
				fread(&reg3,sizeof(Turnos),1,arch3);
			}
			
			if(IdProfesionalcorrecta==0)
			{
				gotoxy(2,4);printf("El numero de la ID no esta en el sistema- Vuelva a intentarlo");
				gotoxy(2,4);printf("                                                                    ");
			}
			
	    }while(IdProfesionalcorrecta==0);
	    
		gotoxy(2,5); printf("Ingrese el DNI del Cliente: "); scanf("%d",&dniCliente);
		
		//////////////////////////////////////////////////////Registrar evolucion----		
		evolucionregistrada=0;
		rewind(arch3);
		
		fread(&reg3,sizeof(Turnos),1,arch3);
		
		while(!feof(arch3)&&evolucionregistrada==0)
		{
			if(dniCliente==reg3.dniCliente && reg3.fueatendido==2&&reg3.IdProfesional==IdProfesional)
			{
				fread(&reg4,sizeof(Cliente),1,arch4);
				while(!feof(arch4)&&evolucionregistrada==0)
				{
				 	if(reg4.DNI_Cliente==dniCliente)
					{
						Clienteencontrada=1;
						gotoxy(2,4);printf("                                                                                ");
						gotoxy(2,5);printf("                                                                                ");
						gotoxy(2,4); printf("Cliente: ");
						gotoxy(2,5); puts(reg4.NombreCliente);
						gotoxy(2,6); printf("Peso: %.2f Kg",reg4.Peso);
						gotoxy(2,7); printf("Edad: %d anios",reg3.edadCliente);
						gotoxy(2,8); printf("DNI Cliente: %d",reg4.DNI_Cliente);
						do 
						{
							gotoxy(2,9); printf("Ingrese la evolucion de la Cliente en no mas de 380 letras:");
							gotoxy(2,10); _flushall(); gets(DetalleEvolucion);   // (reg3.DetalleAtencion); 
							tamanoevolucion=strlen(DetalleEvolucion);//(reg3.DetalleAtencion);
							if(tamanoevolucion>380) //(tamanoevolucion>380)
							{
								gotoxy(2,10);printf("                                                                     ");
							}
						}while(tamanoevolucion>380||tamanoevolucion<5);
						
						gotoxy(2,4); printf("                                                                           ");
						gotoxy(2,5); printf("                                                                           ");
						gotoxy(2,6); printf("                                                                           ");
						gotoxy(2,7); printf("                                                                           ");
						gotoxy(2,8); printf("                                                                           ");
						gotoxy(2,9); printf("                                                                           ");
						gotoxy(2,10);printf("                                                                           ");
											
						gotoxy(2,4); printf("Ingrese su ID para finalizar: ");
						gotoxy(2,5); printf("ID: "); scanf("%d",&IdProfesional);//("%d",reg3.IdProfesional);
						
						evolucionregistrada=1;
						break;	
					 }
			      fread(&reg4,sizeof(Cliente),1,arch4);
				}
			
		    }
			fread(&reg3,sizeof(Turnos),1,arch3);		  
	    }
    
		if(evolucionregistrada==1)
		{
			gotoxy(2,10);system("pause");
			//////////////////////////////////////////////////////////////////////// Guardar evolucion-----	 
			evolucionguardada=0;
			rewind(arch3); rewind(arch4);	
			fread(&reg3,sizeof(Turnos),1,arch3);
			while(!feof(arch3)&&evolucionguardada==0)
			{
				if(reg3.fueatendido==2 && reg3.dniCliente==dniCliente&&reg3.IdProfesional==IdProfesional)
				{   
					fread(&reg4,sizeof(Cliente),1,arch4);
					while(!feof(arch4)&&evolucionguardada==0)
					{   
						if(reg4.DNI_Cliente==dniCliente && reg3.fueatendido==2 && evolucionguardada==0);
						{
							reg3.edadCliente=reg3.fecha.aaaa-reg4.fechanacimiento.aaaa;
							reg3.fueatendido=1;
							strcpy(reg3.DetalleAtencion,DetalleEvolucion);
							int pos=ftell(arch3)-sizeof(Turnos);
							fseek(arch3,pos,SEEK_SET);
							fwrite(&reg3,sizeof(Turnos),1,arch3);
							gotoxy(2,9); printf("Se ha guardado la evolucion correctamente ");
							evolucionguardada=1;
							break;
						}
						fread(&reg4,sizeof(Cliente),1,arch4);
					}
				}
				if(evolucionguardada==1)
				{
					break;
				}
				else
				{
					fread(&reg3,sizeof(Turnos),1,arch3);  
				}
			}
		}
		
		fclose(arch4); fclose(arch3);
		
		if(evolucionregistrada==0)
		{
			gotoxy(2,6); printf("El dni ingresado no esta registrado en sistema");
		}
    }
	gotoxy(2,12); system("pause");
}

void fin()
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
	gotoxy(2,2); printf("***FIN DEL PROGRAMA***\n\n");
	gotoxy(2,3); system("pause"); 
	 
}

void error()
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
	gotoxy(2,2); printf("***LA OPCION NO ES VALIDA***\n\n");
	gotoxy(2,3); system("pause");
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
