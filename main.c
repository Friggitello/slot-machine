#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void gioco();
int inserisci_credito();
int salva_file();
int carica_file();
int credito = 0;

int main(){
	printf("Benvenuto alle slot:\nCredito Attuale: %d\n1:Gioca\n2:Inserisci credito\n3:Salva progresso\n4:Carica progresso\n5:Esci\n\n",credito);
	int scelta_menu;
	scanf("%d",&scelta_menu);
		switch(scelta_menu){
			case 1:
				gioco();
				break;
			case 2:
				inserisci_credito();
				break;
			case 3:
				salva_file();
				break;
			case 4:
				carica_file();
				break;
			case 5:
				return 0;
				break;
			default:
				main();
				break;

	}
}


void gioco(){
	int i,j;
	char a[] = "ABCX";
	char b[3];
	char scelta;

	srand(time(0));
	printf("Premere y per giocare o n per uscire:\n");
	scanf(" %c",&scelta);
	if (scelta == 'y'){
		if (credito > 0){
			for(i=0; i<3; i++){
				j = rand()%4;
				b[i] = a[j];
			}
			b[i] = '\0';
			printf("%s\n",b);
			if((b[0] == b[1] && b[0] == b[2]) && b[0] != 'X'){
				credito += 3;
			}
			else if((b[0] == b[1] && b[1] == b[2]) && b[0] == 'X'){
				credito -= 3;
			}
			else if((b[0] == b[1] && b[0] != 'X') || (b[0] == b[2] && b[0] != 'X') || (b[1] == b[2]) && b[1] != 'X'){
				credito += 1;
			}
			else{
				credito--;
			}
			printf("%d\n",credito);
			gioco();
		}
		else {
			printf("Devi inserire altri crediti.\n");
			main();
		}
	}
	else{
		main();
	}

}

int inserisci_credito(){
	int credito_aggiunto;
	printf("Inserire il credito da aggiungere: \n");
	scanf("%d", &credito_aggiunto);
	credito = credito + credito_aggiunto;
	printf("Nuovo credito: %d\n\n",credito);
	main();
}

int salva_file(){
	FILE *fptr;
	fptr = fopen("./credito.txt","w");
	fprintf(fptr,"%d",credito);
	fclose(fptr);
	main();
}

int carica_file(){
	FILE *fptr;
	fptr = fopen("./credito.txt","r");
	fscanf(fptr,"%d",&credito);
	fclose(fptr);
	main();
}
