#include <stdio.h>
#include<locale.h>
#include<stdlib.h>

#define MAX 100
#define kWMaior 170

float valorkW = 1.75;

void menu();
void cadastro(int idCliente, int conta[], float kW[],float total[]);
void listar(int idCliente, int conta[], float kW[], float total[]);
void maior(int idCliente, int conta[], float kW[], float total[]);
void menor(int idCliente, int conta[], float kW[], float total[]);
void media(int idCliente, int conta[], float kW[], float total[]);
void maior170(int idCliente, int conta[], float kW[], float total[]);

int main() {
	setlocale(LC_ALL, "Portuguese");

	float kW[MAX], total[MAX];
	int op, idCliente = 0, conta[MAX];

	menu();
	scanf_s("%i", &op);

	while ((op >= 1) && (op <= 6)) {

		switch (op)
		{
		case 1: //CADASTRO
			if (idCliente < MAX) {
				cadastro(idCliente++, conta, kW, total);
			}
			else {
				printf("Total de cadastros excedidos!\n");
			}
			break;
		case 2: //LISTAR
			listar(idCliente,conta,kW,total);
			break;
		case 3: //MAIOR
			maior(idCliente, conta, kW, total);
			break;
		case 4: //MENOR
			menor(idCliente, conta, kW, total);
			break;
		case 5: //MEDIA
			media(idCliente, conta, kW, total);
			break;
		case 6: //170 kW
			maior170(idCliente, conta, kW, total);
			break;

		default:
			break;
		}



		menu();
		scanf_s("%i", &op);
	}

	return 0;
}

void menu() {
	system("cls");
	printf("Digite o que você gostaria de fazer: \n");
	printf("1 - Cadastrar novo cliente. \n");
	printf("2 - Listar clientes \n");
	printf("3 - Cliente de maior consumo. \n");
	printf("4 - Cliente de menor consumo. \n");
	printf("5 - Média de consumo. \n");
	printf("6 - Clientes que consumiram mais de 170kW. \n");
	printf("Digite qualquer outra tecla para sair \n");
	printf("\nOpção: ");
}


void cadastro(int idCliente, int conta[], float kW[], float total[]) {
	
	printf("Digite o número da conta: ");
	scanf_s("%i", &conta[idCliente]);

	printf("Digite o total de kW: ");
	scanf_s("%f", &kW[idCliente]);

	total[idCliente] = kW[idCliente] * valorkW;
	

}

void listar(int idCliente, int conta[], float kW[], float total[]) {
	if (idCliente == 0) {
		printf("Nenhum cadastro foi efetuado ainda! Cadastre antes de listar!\n");
	}
	else {
		for (int i = 0; i < idCliente; i++)
		{
			printf("Número da conta: %i\n", conta[i]);
			printf("Total de kW: %.2f\n", kW[i]);
			printf("Total gasto: %.2f\n", total[i]);
			printf("\n");
		}
	}
	system("pause");
}

void maior(int idCliente, int conta[], float kW[], float total[]) {
	float maior;
	int pos = 0;
	if (idCliente == 0) {
		printf("Nenhum cadastro foi efetuado ainda! Cadastre antes de listar!\n");
	}
	else {
		maior = total[0];
		for (int i = 0; i < idCliente; i++)
		{
			if (total[i] > maior) {
				maior = total[i];
				pos = i;
			}
		}

		printf("O cliente que mais consumiu gastou: %.2f, número da conta: %d\n", maior, conta[pos]);
	}
	system("pause");
}

void menor(int idCliente, int conta[], float kW[], float total[]) {
	float menor;
	int pos = 0;
	if (idCliente == 0) {
		printf("Nenhum cadastro foi efetuado ainda! Cadastre antes de listar!\n");
	}
	else {
		menor = total[0];
		for (int i = 0; i < idCliente; i++)
		{
			if (total[i] < menor) {
				menor = total[i];
				pos = i;
			}
		}

		printf("O cliente que menos consumiu gastou: %.2f, número da conta: %d\n", menor, conta[pos]);
	}
	system("pause");
}

void media(int idCliente, int conta[], float kW[], float total[]) {
	float media, soma=0;
	if (idCliente == 0) {
		printf("Nenhum cadastro foi efetuado ainda! Cadastre antes de listar!\n");
	}
	else {
		for (int i = 0; i < idCliente; i++)
		{
			soma += kW[i];
		} 
		media = soma / idCliente;
		printf("A média de consumo é: %.2f\n", media);
	}
	system("pause");
}


void maior170(int idCliente, int conta[], float kW[], float total[]) {
	int qtd = 0;
	if (idCliente == 0) {
		printf("Nenhum cadastro foi efetuado ainda! Cadastre antes de listar!\n");
	}
	else {
		for (int i = 0; i < idCliente; i++)
		{
			if (kW[i] > kWMaior) {
				printf("O cliente: %d consumiu: %.2f\n", conta[i], kW[i]);
				qtd++;
			}
		}
	}
	if (qtd == 0)
		printf("Ninguém consumiu menos de 170kW\n");
	system("pause");
}