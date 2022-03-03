# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <windows.h> //Compatible sólo con windows

//Cambia este valor para modificar las dimensiones de la matriz
#define t 4

//Función donde serán generados los valores de cada coordenada dentro de la matriz
void datos(int Mat[t][t]) {
	int num;
	for (int i=0; i<t; i++) {
        // Iterar por rlas filas
        for (int j=0; j<t; j++){
        	num = rand()%99+1;
        	//Si las filas y columnas coinciden i==j, guardará el valor pseudoaleatorio "num" en la coordenada Mat[i][j] 
			if(i==j){
				Mat[i][j]=num;
					
					//Seguirá con los demás valores en la fila[i], también asignándoles "num"
					while(j!=t-1){
						num = rand()%99+1;
						j+=1;
						Mat[i][j]=num;	
					}
					//Si la coordenada Mat[i][j] está por debajo de la diagonal principal(i==j), su valor será guardado como 0. Se reestablece
					//el valor de j para que itere desde la columna 0 y así hasta que se encuentre con la diagonal, que sería (j==i)
					j=0;
					while(j!=i){
						Mat[i][j]=0;
						j+=1;
					}
			}
    	}
    }
}

//Impresión de datos guardados en la función "datos"
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
	
	//Estructura que almacenará el tiempo en sus distintos componentes...AA/MM/DD/
	struct tm *tiempo,*tiempo2;
	
	//Se declara una variable de tipo time
	time_t inicio;
	inicio = time(NULL);
	
	//El struct tiempo tendrá almacenado AA/MM/DD hasta semana, teniendo en cuenta la información que le arroje el sistema
	tiempo = localtime(&inicio);
	
	do{
		system("cls");
		printf("Matriz triangular superior\n\n");
		
		//Semilla para el número aleatorio
		srand(time(0));
		
		//Generando matriz, dónde se le manda la variable para guardar la matriz y el código de generador de pseudo
		datos(A);
		
		//Imprimiendo los datos
		imprimir(A);
		printf("\n\nDesea generar otra matriz triangular superior(ponga 1 para aceptar)? ");
		scanf("%d",&repetir);
		Beep(293,200);
	}while(repetir==1);
	
	//Los valores del struct se reescribían así que se le hizo una asignación para que no se reescribiera
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

