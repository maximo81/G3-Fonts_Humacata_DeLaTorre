#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<windows.h>
#include"recuadrar.h"

/////////////////////////////**************************Administracion******************//////////////////////////////

struct Fecha
{
  int dd;
  int mm;
  int aaaa;	
};

struct RegistroDeAtenciones
{
	int IdProfesional;
	char ApellidoNombre[60];
	int atenciones;
	Fecha fechadeatencion;
};

struct Turnos
{
	int IdProfesional;
	Fecha fecha;
	int dni;
	int edadCliente;
	char DetalleAtencion[380];
	int fueatendido; //1-si 2-no
};

struct CuentasDeRecepcionistas
{
	char user[10];
	char password [32];
	char ApellidoNombre[60];
};

struct RegistroDeProfesionales
{
	char ApellidoNombre[60];
	int IdProfesional;
	int DNI;
	int Telefono;
};

int MENU()
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
	
	gotoxy(34,3); printf("MODULO 3: Administracion \n\n");//titulo del modulo del programa
	
	gotoxy(2,6); printf("1)Registrar Profesional");
	gotoxy(2,8); printf("2)Registrar Recepcionista");
	gotoxy(2,10); printf("3)Atenciones por profesional");
	gotoxy(2,12); printf("4)Ranking de atenciones por profesional en el mes");
	gotoxy(2,14); printf("5)Cerrar programa");
	gotoxy(2,17); printf("Ingrese Opcion: ");
	scanf("%d",&opc);
	return(opc);
    	
	
}

void RegistrarProfesional()
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
	
	FILE *arch1; arch1=fopen("Profesionales.dat","a+b");
	
	if(arch1==NULL)
	{
		gotoxy(2,2); printf("***Error de Archivo***");
	}
	
	RegistroDeProfesionales reg;
	
	gotoxy(2,4); printf("Ingrese Apellido y Nombre del profesional: "); 
	_flushall(); 
	gets(reg.ApellidoNombre);
	
	gotoxy(2,6); printf("Ingrese nro. de DNI: "); 
	scanf("%d",&reg.DNI);
	
	gotoxy(2,8); printf("Ingrese nro. de ID: "); 
	scanf("%d",&reg.IdProfesional);
	
	gotoxy(2,10); printf("Ingrese nro. de telefono: "); 
	scanf("%d",&reg.Telefono);
	
	fwrite(&reg,sizeof(RegistroDeProfesionales),1,arch1);
	
	gotoxy(2,12); printf("Se ha registrado con exito el profesional");
	
	fclose(arch1);
	
	gotoxy(2,13); system("pause");
	
}

void RegistrarUsuarioProfesionalAsistente()
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
	
	
	FILE *arch2; int controlusername, tamanousername, iniciacon1minuscula, tiene2mayusculas, hasta3digitos, digito, esunicoelnombre;
	int controluserpass, tienealmenos1M, tienealmenos1m, tienealmenos1nro, tamanouserpass, soloalfanumericos, solo3dconsecutivos;
	char auxpass[32]; CuentasDeRecepcionistas usu, regi;
	
	 arch2=fopen("Recepcionistas.dat","r+b");
	
	if(arch2==NULL)
	{
		gotoxy(2,2); printf("***Error de Archivo***");
		arch2=fopen("Recepcionistas.dat","a+b"); 
	}
	else
	{
	
	gotoxy(2,4); printf("Ingrese Apellido y Nombre:  "); 
	_flushall(); 
	gets(usu.ApellidoNombre);
	
	gotoxy(2,4); printf("                                     ");
	do
	{
	controlusername=1;
	gotoxy(2,4); printf("Ingrese nombre de usuario respetando lo sgte.:[De lo contrario no podra avanzar] "); 
	gotoxy(2,5); printf("a. Debe tener entre 6 y 10 caracteres");
	gotoxy(2,6); printf("b. Debe comenzar con una minuscula");
	gotoxy(2,7); printf("c. Debe tener al menos 2 mayusculas");
	gotoxy(2,8); printf("d. Debe tener como maximo 3 digitos");
	gotoxy(2,9); printf("e. Si todo es correcto y no avanza, se debe a que ya existe un nombre igual");
    gotoxy(2,11); printf("Nombre: "); _flushall(); gets(usu.user);
    
	tamanousername=strlen(usu.user);
	if(tamanousername<6||tamanousername>10)
	{
		controlusername=0;
	}
	
	iniciacon1minuscula=usu.user[0];
	if(iniciacon1minuscula<97 || iniciacon1minuscula>122)
	{
		controlusername=0;
	}
	
	tiene2mayusculas=0;
	for(int i=0; i<tamanousername; i++)
	{
	   if(usu.user[i]>=65&&usu.user[i]<=90)
	   {
	   	tiene2mayusculas++;
	   }
	}
	if(tiene2mayusculas<2)
	{
		controlusername=0;
	}
	
	hasta3digitos=0;
	for(int i=0; i<tamanousername; i++)
	{
		if(usu.user[i]>=48 && usu.user[i]<=57)
		{
			hasta3digitos++;
		}
	}
	if(hasta3digitos>3)
	{
		controlusername=0;
	}
	
	fread(&regi,sizeof(CuentasDeRecepcionistas),1,arch2);
	while(!feof(arch2))
	{
		esunicoelnombre=strcmp(usu.user,regi.user);
		if(esunicoelnombre==0)
		{
			controlusername=0;
			rewind(arch2);
			break;
		}
     fread(&regi,sizeof(CuentasDeRecepcionistas),1,arch2);
	}
	if(controlusername==0)
	{
		gotoxy(2,11);printf("                                                                                            "); 
	}
    }while(controlusername==0);
	fclose(arch2);
	arch2=fopen("Recepcionistas.dat","a+b");
	
	gotoxy(2,4); printf("                                                                                            "); 
	gotoxy(2,5); printf("                                                                                            "); 
	gotoxy(2,6); printf("                                                                                            "); 
	gotoxy(2,7); printf("                                                                                            "); 
	gotoxy(2,8); printf("                                                                                            ");
	gotoxy(2,9); printf("                                                                                            "); 
    gotoxy(2,10); printf("                                                                                           "); 
    gotoxy(2,11); printf("                                                                                           "); 
	
	do
	{
	controluserpass=1;	
	gotoxy(2,4); printf("Ingrese clave de usuario teniendo en cuenta lo sgte.: [De lo contrario no podra proseguir] "); 
	gotoxy(2,5); printf("a.Debe tener al menos una minuscula, una mayuscula y un numero ");
	gotoxy(2,6); printf("b. Solo debe tener caracteres alfanumericos");
	gotoxy(2,7); printf("c. Debe tener entre 6 y 32 caracteres ");
	gotoxy(2,8); printf("d. No puede haber mas de 3 digitos consecutivos ");
	gotoxy(2,9); printf("e. No puede haber 2 letras consecutivas y alfabeticamente consecutivas");
	gotoxy(2,11); printf("Contrasenia: ");
	_flushall();
	gets(usu.password);
	
	gotoxy(2,13); printf("                                                             ");
	
	tamanouserpass=strlen(usu.password);
	if(tamanouserpass<6||tamanouserpass>32)
	{
		controluserpass=0;
	}
	
	for(int i=0; i<tamanouserpass; i++)
	{
		if(usu.password[i]>=65 && usu.password[i]<=90)
		{
			tienealmenos1M=1;
		}
	}
	for(int i=0; i<tamanouserpass; i++)
	{
		if(usu.password[i]>=97 && usu.password[i]<=122)
		{
			tienealmenos1m=1;
		}
	}
	for(int i=0; i<tamanouserpass; i++)
	{
		if(usu.password[i]>=48 && usu.password[i]<=57)
		{
			tienealmenos1nro=1;
		}
	}
	if(tienealmenos1m!=1 || tienealmenos1M!=1 || tienealmenos1nro!=1)
	{
		controluserpass=0;
	}
	
	soloalfanumericos=1;
	for(int i=0; i<tamanouserpass; i++)
	{
		if(usu.password[i]>=91 && usu.password[i]<=96)
		{
			soloalfanumericos=0;
		}
		if(usu.password[i]>=123 && usu.password[i]<=255)
		{
			soloalfanumericos=0;
		}
		if(usu.password[i]>=32 && usu.password[i]<=47)
		{
			soloalfanumericos=0;
		}
		if(usu.password[i]>=58 && usu.password[i]<=64)
		{
			soloalfanumericos=0;
		}
	}
	if(soloalfanumericos==0)
	{
		controluserpass=0;
	}
	
	solo3dconsecutivos=0;
	for(int i=0; i<tamanouserpass; i++)
	{
		if(isdigit(usu.password[i]) && isdigit(usu.password[i+1]) && isdigit(usu.password[i+2]))
		{
			solo3dconsecutivos++;
		}
	}
	if(solo3dconsecutivos>1)
	{
		controluserpass=0;
	}
	
	strcpy(auxpass, usu.password);
    strlwr(auxpass);
    for(int i=0; i<tamanouserpass-1; i++)
   {
       for(int j=97; j<122-1; j++)
       {
         if(auxpass[i]==j && auxpass[i+1]==j+1)
         {
          controluserpass=0;
         }
        } 
    }
    if(controluserpass==0)
    {
    	gotoxy(2,11); printf("                                                                                            "); 
	}

    }while(controluserpass==0);
    
	gotoxy(2,4); printf("                                                                                                                  "); 
	gotoxy(2,5); printf("                                                                     "); 
	gotoxy(2,6); printf("                                                                     "); 
	gotoxy(2,7); printf("                                                                     "); 
	gotoxy(2,8); printf("                                                                     "); 
    gotoxy(2,9); printf("                                                                     "); 
    gotoxy(2,11); printf("                                                                                            "); 
	
	fwrite(&usu,sizeof(CuentasDeRecepcionistas),1,arch2);
	
	gotoxy(2,4); printf("La cuenta se ha registrado con exito");
    }
	fclose(arch2);
	
	gotoxy(2,6); system("pause");
}


void NroDeAtencionesProfesional()
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
//////////////////////////////////////////////////////////Declaracion de las variables	
	int nroatenciones, IdProfesional, mes, tieneatencionesenlafecha;
	FILE *arch1, *arch3; 
	Turnos reg3;
	RegistroDeProfesionales reg1;
/////////////////////////////////////////////7//////////Apertura de Archivos	
	arch1=fopen("Profesionales.dat","a+b");
	arch3=fopen("Turnos.dat","a+b");
//////////////////////////////////////////////////Verificacion de archivos	
	if(arch1==NULL||arch3==NULL)
	{
	 gotoxy(2,4);printf("*Error en el sistema - Archivos no cargados*");
	 gotoxy(2,5); exit(1);
	}
    else
	{ ///////////////////////////////////////////////////Ingreso de los datos 
		gotoxy(2,4);printf("Ingrese el mes para verificar nro. de atenciones: ");
		scanf("%d",&mes);
		gotoxy(2,5);printf("Ingrese la ID del profesional: ");
		scanf("%d",&IdProfesional);
		//////////////////////////////Conteo de las atenciones en el mes ingresado por el profesional
		nroatenciones=0;
		fread(&reg3,sizeof(Turnos),1,arch3);
        while(!feof(arch3))		
        {
          	 if(reg3.fueatendido==1&&reg3.IdProfesional==IdProfesional && reg3.fecha.mm==mes)	
          	 {
			   nroatenciones++; 
			 }
          fread(&reg3,sizeof(Turnos),1,arch3);
		}
    //////////////////////////////////////////////Resultados del conteo
     if(nroatenciones==0)
     {
      gotoxy(2,6); printf("El profesional de la ID ingresada no presenta atenciones en el mes");	
     }
     else
     {
	 gotoxy(2,6); printf("El profesional tuvo %d atenciones en el mes",nroatenciones);
     }
	}
	
	fclose(arch3); fclose(arch1);
	gotoxy(2,8); system("pause");
}

void RankingAtencionesProfesional()
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
	
	FILE *arch1, *arch3; RegistroDeAtenciones vectordeatenciones[50], aux; 
	int nroderegistros, bandera, mes, nrodeatenciones;
	RegistroDeProfesionales reg1; Turnos reg3; 
	
	arch1=fopen("Profesionales.dat","r+b");
	arch3=fopen("Turnos.dat","r+b");
	
	if(arch1==NULL||arch3==NULL)
	{
		gotoxy(2,4); printf("*Error en el sistema-Archivos no cargados*"); 
		gotoxy(2,5); exit(1);
		
	}
	gotoxy(2,4);printf("Ingrese el mes: "); scanf("%d",&mes);
	gotoxy(2,4);printf("                                                         ");
	
///////////////////////////////////////////////////////////Almacenamiento de los Profesionales en un vector de registro
    nroderegistros=0;
	rewind(arch1);
	fread(&reg1,sizeof(RegistroDeProfesionales),1,arch1);
	while(!feof(arch1))
	{		
				strcpy(vectordeatenciones[nroderegistros].ApellidoNombre,reg1.ApellidoNombre);
				vectordeatenciones[nroderegistros].IdProfesional=reg1.IdProfesional;
				vectordeatenciones[nroderegistros].atenciones=0;
				vectordeatenciones[nroderegistros].fechadeatencion.mm=mes;
				nroderegistros++;
		fread(&reg1,sizeof(RegistroDeProfesionales),1,arch1);		
	}
	
////////////////////////////////////////////////////////Conteo y guardado de las atenciones de cada profesional en el mes
  
   rewind(arch3);
   for(int i=0; i<nroderegistros; i++)
   { 
     nrodeatenciones=0;
   	
   	 fread(&reg3,sizeof(Turnos),1,arch3);
	 while(!feof(arch3))
   	 {
   	 	if(reg3.fueatendido==1 && reg3.IdProfesional==vectordeatenciones[i].IdProfesional &&mes==reg3.fecha.mm)
   	 	{
   	 	  nrodeatenciones++;	 
		}
	 fread(&reg3,sizeof(Turnos),1,arch3);
	 }
	 rewind(arch3);
	 vectordeatenciones[i].atenciones=nrodeatenciones;
   }
   fclose(arch1); fclose(arch3);
   
   //////////////////////////////Ordenamiento por cantidad de atenciones en el mes
   do
   {
   bandera=0;	
   for(int i=0; i<nroderegistros-1;i++)
   {
   	if(vectordeatenciones[i].atenciones<vectordeatenciones[i+1].atenciones)
   	{
   		aux=vectordeatenciones[i+1];
   		vectordeatenciones[i+1]=vectordeatenciones[i];
   		vectordeatenciones[i]=aux;
   		bandera=1;
	}
   }
   }while(bandera==1);
   
   /////////////////////////////// Muestra del ranking
   for(int i=0; i<nroderegistros; i++)
   {
   	gotoxy(2,4);printf("Puesto nro. %d",i+1);
   	gotoxy(2,6);printf("Profesional: ");
   	gotoxy(17,6);puts(vectordeatenciones[i].ApellidoNombre);
   	gotoxy(2,7);printf("ID: %d", vectordeatenciones[i].IdProfesional);
   	gotoxy(2,8);printf("Nro. de atenciones en el mes %d: %d",mes,vectordeatenciones[i].atenciones);
   	gotoxy(2,9);system("pause");
   	gotoxy(2,5);printf("                                                                                          ");
   	gotoxy(2,6);printf("                                                                                          ");
   	gotoxy(2,7);printf("                                                                                          ");
   	gotoxy(2,8);printf("                                                                                          ");
   	gotoxy(2,9);printf("                                                                                          ");
   }
    gotoxy(2,4);printf("                                                                                          ");
    
	if(nroderegistros==0)
    {
    	gotoxy(2,11); printf("Aun no hay Profesionales registrados en el sistema");
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
	gotoxy(2,4); system("pause");
	 
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
	gotoxy(2,4); system("pause");
}

main()
{
	system("COLOR 1F"); //Colores administracion_ F: blanco brillante(fondo), 0: Negro(letras)
	int opcionmenu;
	do{
	opcionmenu=MENU();
	switch(opcionmenu)
	{
		case(1): RegistrarProfesional();
		break;
		
		case(2): RegistrarUsuarioProfesionalAsistente();
		break;
		
		case(3): NroDeAtencionesProfesional();
		break;
		
		case(4): RankingAtencionesProfesional();
		break;
		
		case(5): fin();
		break;
		
		default: error();
		break;
	}
   }while(opcionmenu!=5);
	
}

