# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <windows.h> //Compatible s�lo con windows

//Cambia este valor para modificar las dimensiones de la matriz
#define t 4

//Funci�n donde ser�n generados los valores de cada coordenada dentro de la matriz
void datos(int Mat[t][t]) {
	int num;
	for (int i=0; i<t; i++) {
        // Iterar por rlas filas
        for (int j=0; j<t; j++){
        	num = rand()%99+1;
        	//Si las filas y columnas coinciden i==j, guardar� el valor pseudoaleatorio "num" en la coordenada Mat[i][j] 
			if(i==j){
				Mat[i][j]=num;
					
					//Seguir� con los dem�s valores en la fila[i], tambi�n asign�ndoles "num"
					while(j!=t-1){
						num = rand()%99+1;
						j+=1;
						Mat[i][j]=num;	
					}
					//Si la coordenada Mat[i][j] est� por debajo de la diagonal principal(i==j), su valor ser� guardado como 0. Se reestablece
					//el valor de j para que itere desde la columna 0 y as� hasta que se encuentre con la diagonal, que ser�a (j==i)
					j=0;
					while(j!=i){
						Mat[i][j]=0;
						j+=1;
					}
			}
    	}
    }
}

//Impresi�n de datos guardados en la funci�n "datos"
void imprimir(int Mat[t][t]) {
	for (int i=0; i<t; i++) {
        // Iterar por las filas
        for (int j=0; j<t; j++)
            // Imprimir el elemento correspondiente
            printf(" [%d] ", Mat[i][j]);
        printf("\n");
    }
}

int main(){
	int A[t][t], repetir;
	
	//Estructura que almacenar� el tiempo en sus distintos componentes...AA/MM/DD/
	struct tm *tiempo,*tiempo2;
	
	//Se declara una variable de tipo time
	time_t inicio;
	inicio = time(NULL);
	
	//El struct tiempo tendr� almacenado AA/MM/DD hasta semana, teniendo en cuenta la informaci�n que le arroje el sistema
	tiempo = localtime(&inicio);
	
	do{
		system("cls");
		printf("Matriz triangular superior\n\n");
		
		//Semilla para el n�mero aleatorio
		srand(time(0));
		
		//Generando matriz, d�nde se le manda la variable para guardar la matriz y el c�digo de generador de pseudo
		datos(A);
		
		//Imprimiendo los datos
		imprimir(A);
		printf("\n\nDesea generar otra matriz triangular superior(ponga 1 para aceptar)? ");
		scanf("%d",&repetir);
		Beep(293,200);
	}while(repetir==1);
	
	//Los valores del struct se reescrib�an as� que se le hizo una asignaci�n para que no se reescribiera
	int a = tiempo->tm_min;
	int b = tiempo->tm_sec;
	
	time_t final;
	final = time(NULL);
	
	tiempo2 = localtime(&final);
	
	printf("El programa fue iniciado a las -> %dh: %dm: %ds\n",tiempo->tm_hour,tiempo->tm_min,tiempo->tm_sec);
	
	printf("El programa fue finalizado a las -> %dh: %dm: %ds\n",tiempo2->tm_hour,tiempo2->tm_min,tiempo2->tm_sec);

	printf("Tiempo transcurrido dentro del programa: %im: %is\n\n\n",tiempo2->tm_min-a,tiempo2->tm_sec-b);
	
	Beep(391,300);
	Beep(369,200);
	Beep(246,400);
	system("pause");
	return 0;
} 

