#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct // Estrutura do Cadastro de pacientes.
{
	char Nome[101];
	int Idade;
	float Peso;
	float Altura;
	int Percentual_Gordura; // Por exemplo, 20% de gordura corporal, quer dizer
							// que 20% do seu peso é gordura.
	int Codigo;

} Cadastro;

typedef struct {
	char Nome[101];
	int Dia;
	int Hora;
	int Mes;
	int Codigo;
} Agendamento;

void Horario_Disponivel(
	Agendamento *t,
	int *Quant_Agendamentos,
	int dia,
	int hora,
	int mes) {
	if (t == 0) {
		printf("\n\tErro.\n");
	}
	for (int i = 0; i < *Quant_Agendamentos; i++) {
		if (t[i].Dia == dia && t[i].Mes == mes && t[i].Hora == hora) {
			printf("\n\n\tHorario Indisponivel.\n");
		} else {
			printf("\n\n\t\tHorario Cleiton");
		}
	}
}
Agendamento Ler_Agendamento() {
	Agendamento a;
	printf("Digite seu nome para realizar o Agendamento: ");
	scanf("\n%[^\n]", a.Nome);
	getchar();
	printf("\nA seguir voce deve digitar o Dia, o Mes e o Horario que deseja "
		   "fazer sua Consulta");
	printf("\nDigite o Mes: ");

	do {
		scanf("\n%d", &a.Mes);
		getchar(); // 4 6 9 11
		if (a.Mes < 1 || a.Mes > 12) {
			printf("\nMes invalido\n");
			printf("\nDigite o mes novamente: ");
		}
	} while (a.Mes < 1 || a.Mes > 12);
	printf("Digite agora o Dia que deseja fazer sua consulta: ");
	do {
		scanf("\n%d", &a.Dia);
		getchar();
		if (a.Mes == 4 || a.Mes == 6 || a.Mes == 9 || a.Mes == 11) {
			if (a.Dia < 1 || a.Dia > 30) {
				printf("\nDia invalido\n");
				printf("\nDigite o dia novamente: ");
			}
		} else if (a.Mes == 2) {
			if (a.Dia < 1 || a.Dia > 28) {
				printf("\nDia invalido\n");
				printf("\nDigite o dia novamente: ");
			}
		}
		if (a.Mes == 1 || a.Mes == 3 || a.Mes == 5 || a.Mes == 7 ||
			a.Mes == 10 || a.Mes == 12) {
			if (a.Dia < 1 || a.Dia > 31) {
				printf("\nDia invalido\n");
				printf("\nDigite o dia novamente: ");
			}
		}
	} while (a.Dia < 1 || a.Dia > 31);
	printf(
		"Digite agora o horario que deseja fazer sua consulta, o atendimento "
		"eh realizado das 9 horas as 12 horas, e das 14 horas as 17 horas: ");
	do {
		scanf("\n%d", &a.Hora);
		getchar();
		if ((a.Hora < 9) || (a.Hora > 12 && a.Hora < 14) || (a.Hora > 17)) {
			printf("Horario invalido\n");
			printf("Por favor, digite novamente\n");
		}
	} while ((a.Hora < 9) || (a.Hora > 12 && a.Hora < 14) || (a.Hora > 17));
	printf("\n\t\tDigite o codigo do agendamento\n");
	scanf("\n%d", &a.Codigo);

	return a;
}

Agendamento *Inserir_Agendamento(
	Agendamento *t,
	int *Quant_Agendamentos,
	Agendamento Paciente) {
	t = (Agendamento *)realloc(
		t, (*Quant_Agendamentos + 1) * sizeof(Agendamento));
	if (t == 0) {
		printf("\n\n\tERRO: nao foi possivel inserir Agendamento\n\n");
		return 0;
	}

	t[*Quant_Agendamentos] = Paciente;
	(*Quant_Agendamentos)++;
	return t;
}

void Conferir_Agendamento(Agendamento *v, int *Quant_Agendamentos) {
	printf("\n\n\t\t\tA seguir a lista dos pacientes agendados.\n\n");
	if (v == 0) {
		printf("\n\tNao ha agendamentos.\n");
	}
	for (int i = 0; i < *Quant_Agendamentos; i++) {
		printf(
			"\n\t\t\tNome: %s\n \t\t\t%d/%d as %02d:00 horas.\n ",
			v[i].Nome,
			v[i].Dia,
			v[i].Mes,
			v[i].Hora);
	}
}

void ExibirMenu() { // Menu de opcaoes do sistema, concluido, mas sujeito a
					// mundancas caso necesario
	printf("\n\t\t\t\tBem-Vindo\n");
	printf(
		"\n\tO menu a seguir tem todas as funionalidades deste sistema...\n\n");
	printf("\n\t0-Encerrar o programa\n");
	printf("\n\t1-Cadastrar pacientes\n");
	printf("\n\t2-Listar Agendamentos/Fazer o agendamento de uma consulta\n");
	printf("\n\t3-Listar todos os pacientes cadastrados no sistema\n");
	printf("\n\t4-Remover um paciente\n");
}
void Conferir(Cadastro *v, int *Quantidade_de_Pacientes_a_Serem_Cadastrados) {
	printf("\n\n\t\t\tA seguir a lista de pacientes cadastrados.\n\n");
	if (v == 0) {
		printf("\n\tNao ha cadastros.\n");
	}
	for (int i = 0; i < *Quantidade_de_Pacientes_a_Serem_Cadastrados; i++) {
		printf("\t\t\tNome: %s\n", v[i].Nome);
		printf("\t\t\tIdade: %d\n", v[i].Idade);
		printf("\t\t\tPeso: %.1f\n", v[i].Peso);
		printf("\t\t\tAltura: %.1f\n", v[i].Altura);
		printf("\t\t\tPercentual de Gordura: %d\n", v[i].Percentual_Gordura);
		printf("\t\t\tCodigo do Paciente: %d\n\n\n", v[i].Codigo);
	}
}

Cadastro Ler_Cadastro() {
	Cadastro a;
	printf("\nDigite o nome do paciente: ");
	scanf("\n%[^\n]", a.Nome);
	getchar();
	printf("\nDigite a Idade do paciente: ");
	scanf("%d", &a.Idade);
	getchar();
	printf("\nDigite o Peso do paciente: ");
	scanf("%f", &a.Peso);
	getchar();
	printf("\nDigite a Altura do paciente: ");
	scanf("%f", &a.Altura);
	getchar();
	printf("\nDigita o Percentual de Godura: ");
	scanf("%d", &a.Percentual_Gordura);
	getchar();
	printf("\nDigite o Codigo do paciente: ");
	scanf("%d", &a.Codigo);
	getchar();
	return a;
}
Cadastro *Inserir_Paciente(
	Cadastro *v,
	int *Quantidade_de_Pacientes_a_Serem_Cadastrados,
	Cadastro Paciente) {
	v = (Cadastro *)realloc(
		v,
		(*Quantidade_de_Pacientes_a_Serem_Cadastrados + 1) * sizeof(Cadastro));
	if (v == 0) {
		printf("\n\n\tERRO: nao foi possivel inserir paciente\n\n");
		return 0;
	}

	v[*Quantidade_de_Pacientes_a_Serem_Cadastrados] = Paciente;
	(*Quantidade_de_Pacientes_a_Serem_Cadastrados)++;
	return v;
}
Cadastro *Remover_Paciente(
	Cadastro *v,
	int *Quantidade_de_Pacientes_a_Serem_Cadastrados,
	int Codigo) {
	for (int i = 0; i < *Quantidade_de_Pacientes_a_Serem_Cadastrados; i++) {
		if (v[i].Codigo == Codigo) {
			v[i] = v[*Quantidade_de_Pacientes_a_Serem_Cadastrados - 1];
			v = (Cadastro *)realloc(
				v,
				(*Quantidade_de_Pacientes_a_Serem_Cadastrados - 1) *
					sizeof(Cadastro));
			if (*Quantidade_de_Pacientes_a_Serem_Cadastrados > 1 && v == 0) {
				printf("\n\n\tERRO: não foi possivel remover Paciente.\n\n");
				return 0;
			}
			(*Quantidade_de_Pacientes_a_Serem_Cadastrados)--;
			printf("\n\n\t\t\tRemovido com Sucesso.\n\n");
			break;
		} else {
			printf("\n\n\t\t\tPaciente nao encontrado.");
		}
	}

	return v;
}
Agendamento *
Remover_Agendamento(Agendamento *t, int Quant_Agemdamento, int codigo) {
}
void pacientes_para_arquivo(
	Cadastro *arquivo,
	int Quantidade_de_Pacientes_a_Serem_Cadastrados) {
	FILE *f = fopen("pacientes.txt", "w");
	if (f == 0) {
		printf("ERRO ao abrir o arquivo");
		return;
	}
	for (int i = 0; i < Quantidade_de_Pacientes_a_Serem_Cadastrados; i++) {
		fprintf(
			f,
			"%s\n%d\n%.1f\n%.1f\n%d\n%d\n",
			arquivo[i].Nome,
			arquivo[i].Idade,
			arquivo[i].Peso,
			arquivo[i].Altura,
			arquivo[i].Percentual_Gordura,
			arquivo[i].Codigo);
	}
	fclose(f);
}

Cadastro *imprime_pacientes_arquivo(
	Cadastro *v,
	int *Quantidade_de_Pacientes_a_Serem_Cadastrados) {
	FILE *f = fopen("pacientes.txt", "r");
	if (f == 0) {
		printf("ERRO ao abrir o arquivo");
		return 0;
	}
	Cadastro novo;
	while (fscanf(
			   f,
			   "%[^\n]\n%d\n%f\n%f\n%d\n%d\n",
			   novo.Nome,
			   &novo.Idade,
			   &novo.Peso,
			   &novo.Altura,
			   &novo.Percentual_Gordura,
			   &novo.Codigo) == 6) {
		v = Inserir_Paciente(
			v, Quantidade_de_Pacientes_a_Serem_Cadastrados, novo);
		getchar();
	}

	fclose(f);
	return v;
}


int main() {
	Agendamento *t = 0;
	Cadastro *v = 0;
	int Quantidade_de_Pacientes_a_Serem_Cadastrados = 0;
	v = imprime_pacientes_arquivo(
		v, &Quantidade_de_Pacientes_a_Serem_Cadastrados);
	int Quant_Agendamentos = 0;
	int Opcao_Escolhida; // variavel para o switch case
	int Codigo = 0;
	char arquivo[] = {"pacientes.txt"};
	/*
	scanf("%d\n", &n);
	Cadastro arquivo[n], b;*/

	do {
		ExibirMenu();
		scanf("%d", &Opcao_Escolhida);
		switch (Opcao_Escolhida) {
		case 0:
			/* Saindo */
			printf("\n\tPrograma Finalizado\n");
			pacientes_para_arquivo(
				v, Quantidade_de_Pacientes_a_Serem_Cadastrados);
			getchar();
			free(v);
			break;
		case 1:
			printf("\n\t\tA Seguir, digite a quantidade de pacientes a serem "
				   "cadastrados...\n\n");
			int x = 0;
			scanf("%d", &x);
			// Quantidade_de_Pacientes_a_Serem_Cadastrados = x;
			getchar();
			for (int i = 0; i < x; i++) {
				Cadastro paciente = Ler_Cadastro();
				v = Inserir_Paciente(
					v, &Quantidade_de_Pacientes_a_Serem_Cadastrados, paciente);

				// Quantidade_de_Pacientes_a_Serem_Cadastrados++;
			}
			break;
		case 2:
			/* Ordem_de_agendamento*/
			printf("\n\tDeseja conferir a lista de agendamentos? Digite 1 para "
				   "sim, Digite 2 para prosseguir para o agendamento: ");
			int z = 0;
			scanf("%d", &z);
			if (z == 1) {
				Conferir_Agendamento(t, &Quant_Agendamentos);
			}
			if (z == 2) {
				printf("Quantos pacientes deseja agendar? ");
				int a;
				scanf("\n%d", &a);
				getchar();
				for (int i = 0; i < a; i++) {
					Agendamento Paciente = Ler_Agendamento();
					t = Inserir_Agendamento(t, &Quant_Agendamentos, Paciente);
				}
			} else if (z != 1 && z != 2) {
				printf("\n\tOpcao invalida.");
				Horario_Disponivel(
					t,
					&Quant_Agendamentos,
					t[Quant_Agendamentos - 1].Dia,
					t[Quant_Agendamentos - 1].Hora,
					t[Quant_Agendamentos - 1].Mes);
			}
			break;
		case 3:
			/* Conferir Cadastro */
			Conferir(v, &Quantidade_de_Pacientes_a_Serem_Cadastrados);
			break;
		case 4:

			printf("\n\tDigite o Codigo do paciente: ");
			scanf("%d", &Codigo);
			v = Remover_Paciente(
				v, &Quantidade_de_Pacientes_a_Serem_Cadastrados, Codigo);
			break;

		default:
			/* Opção Inválida */
			if (Opcao_Escolhida != 0) {
				printf("\n\tOpcao Invalida\n");
			}
			break;
		}
	} while (Opcao_Escolhida != 0);
	return 0;
}
