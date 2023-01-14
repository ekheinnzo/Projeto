#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "funcoes.h"

Professor cad_professor(){

    Professor professor;

    printf("Nome do Professor: ");
    scanf(" %[^\n]s", professor.nome);
    printf("Quantidade de Disciplinas: ");
    scanf("%i", &professor.num_disc);

    return professor;
}

Disciplina *cad_disciplina(int num_disc){

    Disciplina disciplinas[num_disc];

    FILE *fdisciplina = fopen("arquivos/fdiscilina.dat", "w");

    if(!fdisciplina) exit(1);

    for(int i = 0; i < num_disc; i++){
        printf("Nome da disciplina: ");
        scanf(" %[^\n]s", disciplinas[i].nome);
        fprintf(fdisciplina,"%s",disciplinas[i].nome);

        printf("Codigo: ");
        scanf("%i",&disciplinas[i].codigo);
        fprintf(fdisciplina,"%i",disciplinas[i].codigo);

        printf("Ano: ");
        scanf("%i",&disciplinas[i].ano);
        fprintf(fdisciplina,"%i",disciplinas[i].ano);

        printf("Semestre: ");
        scanf("%i",&disciplinas[i].semestre);
        fprintf(fdisciplina,"%i",disciplinas[i].semestre);

        printf("Quantidade de Alunos: ");
        scanf("%i",&disciplinas[i].qtd_alunos);
        fprintf(fdisciplina,"%i", disciplinas[i].qtd_alunos);

        printf("Quantidade de Trabalhos: ");
        scanf("%i",&disciplinas[i].qtd_trabalhos);
        fprintf(fdisciplina,"%i", disciplinas[i].qtd_trabalhos);

        printf("Carga Horaria: ");
        scanf("%i",&disciplinas[i].carga_horaria);
        fprintf(fdisciplina,"%i", disciplinas[i].carga_horaria);

        printf("Carga Horaria Realizada: ");
        scanf("%i",&disciplinas[i].carga_hor_realizada);
        fprintf(fdisciplina,"%i", disciplinas[i].carga_hor_realizada);

        printf("Nota minima: ");
        scanf("%f",&disciplinas[i].nota_minima);
        fprintf(fdisciplina,"%f", disciplinas[i].nota_minima);

        printf("Frequencia para aprovação: ");
        scanf("%f",&disciplinas[i].frequencia);
        fprintf(fdisciplina,"%f", disciplinas[i].frequencia);

        cad_aluno(disciplinas[i].alunos, disciplinas->qtd_alunos);
    }
    return disciplinas;
}

void cad_aluno(Aluno alunos[], int TAM)
{
    FILE *falunos = fopen("arquivos/falunos.dat", "w");

    for(int i = 0; i < TAM; i++){
        printf("Matricula: ");
        scanf("%i",&alunos->matricula);//entender pq seta e nao ponto!!!!!
        fprintf(falunos,"%i",alunos->matricula);

        printf("Nome Aluno: ");
        scanf(" %[^\n]s",alunos->nome_aluno);
        fprintf(falunos," %s",alunos->nome_aluno);

        cad_prova_trab(alunos->prova_trab);

        cad_aula(alunos->aula);
    }
}

void cad_prova_trab(Prova_trab *prova_trab)
{
    FILE *fprova_trab = fopen("arquivos/fprova_trab.dat", "w");

    printf("Nome da Avaliação: ");
    scanf(" %[^\n]s", prova_trab->nome);
    fprintf(fprova_trab," %s", prova_trab->nome);

    printf("Tipo de Avaliação: ");
    scanf(" %c",&prova_trab->tipo);
    fprintf(fprova_trab," %c",prova_trab->tipo);

    printf("Data da Avaliação: ");
    scanf("%i",&prova_trab->data);
    fprintf(fprova_trab," %i",prova_trab->data);

    printf("Peso da Avaliação: ");
    scanf("%f",&prova_trab->peso);
    fprintf(fprova_trab," %f",prova_trab->peso);

    printf("Nota da Avaliação: ");
    scanf("%f",&prova_trab->notas);
    fprintf(fprova_trab," %f",prova_trab->notas);

    return;
}

void cad_aula(Aluno **aula)
{
    /*Não é necessario a aula estar dentro da struct aluno
    apenas precisamos para cada aula de uma lista de presença*/

    FILE *faula = fopen("arquivos/faula.dat", "w");

    printf("Numero de ordem: ");
    scanf("%i", &aula->num_ordem);
    fprintf(faula," %i", aula->num_ordem);

    printf("Data: ");
    scanf("%i", &aula->num_ordem);
    fprintf(faula," %i", aula->num_ordem);

    printf("Quantidade de Horas de Aula: ");
    scanf("%i", &aula->qtd_horas_aula);
    fprintf(faula," %i", aula->qtd_horas_aula);

    printf("Conteudo da aula: ");
    scanf(" %[^\n]s", aula->conteudo);
    fprintf(faula," %s", aula->conteudo);

    printf("Presença ");            //Fazer uma lista de presença
    scanf(" %c", aula->presenca);
    fprintf(faula," %c", aula->presenca);

    return;
}
