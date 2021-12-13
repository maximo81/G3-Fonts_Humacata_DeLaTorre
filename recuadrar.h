void gotoxy(int x,int y)                      //esta funcion viene normalmente integrada a conio.h pero como no esta la escribimos. Esta funcion tiene supuesto origen en Boorland, lo que hace es mover un puntero a una determinada cooredenada dentro                                          
{                                              // espacio de la consola
	  HANDLE hcon;                                                              
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }
 
