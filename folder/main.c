#include <stdio.h>
#include <string.h>

int main() {
    char nomes[100][100]; 
    float medias[100];        
    int anos[100];            
    int totalAlunos = 0;             
    int opcao;

    do {
        printf("\n--- Sistema de Cadastro de Alunos ---\n");
        printf("1. Inserir dados de um novo aluno\n");
        printf("2. Listar todos os alunos cadastrados\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao < 1 || opcao > 3) {
            printf("Opção inválida. Tente novamente.\n");
            continue;
        } switch (opcao) {
            case 1: {
                if (totalAlunos >= 100) {
                    printf("Limite de alunos atingido.\n");
                } else { 
                    printf("Digite o nome do aluno: ");
                    scanf(" %[^\n]s", nomes[totalAlunos]);
                    do {
                        printf("Digite a média escolar (0.0 a 10.0): ");
                        scanf("%f", &medias[totalAlunos]);
                        if (medias[totalAlunos] < 0.0 || medias[totalAlunos] > 10.0) {
                            printf("Média inválida. Tente novamente.\n");
                        }
                    } while (medias[totalAlunos] < 0.0 || medias[totalAlunos] > 10.0);
                    do {
                        printf("Digite o ano escolar (1 a 3): ");
                        scanf("%d", &anos[totalAlunos]);
                        if (anos[totalAlunos] < 1 || anos[totalAlunos] > 3) {
                            printf("Ano inválido. Tente novamente.\n");
                        }
                    } while (anos[totalAlunos] < 1 || anos[totalAlunos] > 3);
                    totalAlunos++;
                    printf("Aluno cadastrado com sucesso!\n"); 
                }
                break;
            }
            case 2:
                if (totalAlunos == 0) {
                    printf("Nenhum aluno cadastrado.\n");
                } else {
                    printf("\n--- Lista de Alunos Cadastrados ---\n");
                    for (int i = 0; i < totalAlunos; i++) {
                        printf("Aluno %d:\n", i + 1);
                        printf("Nome: %s\n", nomes[i]);
                        printf("Média: %.2f\n", medias[i]);
                        printf("Ano: %d\n", anos[i]);
                    }
                }
                break;
            case 3:
                printf("Saindo do programa...\n");
                break;
        }
    } while (opcao != 3);
    return 0;
}
