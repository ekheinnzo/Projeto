#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "funcoes.h"


/* 
*   ------> Criando Registros
*/
Professor cad_professor(){

    Professor professor;

    printf("Nome do Professor: ");
    scanf(" %[^\n]s", professor.nome);
    
    printf("Quantidade de Disciplinas: ");
    scanf("%i", &professor.num_disc);
    
    salva_professor(professor);
    return professor;
}

void salva_professor (Professor professor) {
    FILE *arq = fopen("arquivos/professor.dat", "w");

    fprintf(arq ,"%s\n", professor.nome);
    fprintf(arq ,"%i\n", professor.num_disc);

    fclose(arq);
}

Disciplina *cad_disciplina(int num_disc){

    Disciplina *disciplinas = malloc(5 * (sizeof(Disciplina)));

    for(int i = 0; i < num_disc; i++){
        printf("Nome da disciplina: ");
        scanf(" %[^\n]s", disciplinas[i].nome);

        printf("Codigo: ");
        scanf("%i",&disciplinas[i].codigo);

        printf("Ano: ");
        scanf("%i",&disciplinas[i].ano);

        printf("Semestre: ");
        scanf("%i",&disciplinas[i].semestre);
        fprintf(fdisciplina,"%i\n",disciplinas[i].semestre);

        printf("Quantidade de Alunos: ");
        scanf("%i",&disciplinas[i].qtd_alunos);
        fprintf(fdisciplina,"%i\n", disciplinas[i].qtd_alunos);

        printf("Quantidade de Trabalhos: ");
        scanf("%i",&disciplinas[i].qtd_trabalhos);
        fprintf(fdisciplina,"%i\n", disciplinas[i].qtd_trabalhos);

        printf("Carga Horaria: ");
        scanf("%i",&disciplinas[i].carga_horaria);
        fprintf(fdisciplina,"%i\n", disciplinas[i].carga_horaria);

        printf("Carga Horaria Realizada: ");
        scanf("%i",&disciplinas[i].carga_hor_realizada);
        fprintf(fdisciplina,"%i\n", disciplinas[i].carga_hor_realizada);

        printf("Nota minima: ");
        scanf("%f",&disciplinas[i].nota_minima);
        fprintf(fdisciplina,"%f\n", disciplinas[i].nota_minima);

        printf("Frequencia para aprovação: ");
        scanf("%f",&disciplinas[i].frequencia);
        fprintf(fdisciplina,"%f\n", disciplinas[i].frequencia);

        cad_aluno(disciplinas[i].alunos, disciplinas->qtd_alunos);
    }
    return disciplinas;
}

void cad_aluno(Aluno alunos[], int TAM)
{
    FILE *falunos = fopen("arquivos/falunos.dat", "w");

    if(!falunos){
        printf("Erro ao Criar arquivo!\n");
        exit(1);
    } 

    for(int i = 0; i < TAM; i++){
        printf("Matricula: ");
        scanf("%i",&alunos->matricula);//entender pq seta e nao ponto!!!!!
        fprintf(falunos,"%i\n",alunos->matricula);

        printf("Nome Aluno: ");
        scanf(" %[^\n]s",alunos->nome_aluno);
        fprintf(falunos,"%s\n",alunos->nome_aluno);

        cad_prova_trab(alunos->prova_trab);

        cad_aula(&alunos->aula);
    }
}

void cad_prova_trab(Prova_trab *prova_trab)
{
    FILE *fprova_trab = fopen("arquivos/fprova_trab.dat", "w");

    if(!fprova_trab){
        printf("Erro ao Criar arquivo!\n");
        exit(1);
    } 

    printf("Nome da Avaliação: ");
    scanf(" %[^\n]s", prova_trab->nome);
    fprintf(fprova_trab,"%s\n", prova_trab->nome);

    printf("Tipo de Avaliação: ");
    scanf(" %c",&prova_trab->tipo);
    fprintf(fprova_trab,"%c\n",prova_trab->tipo);

    printf("Data da Avaliação: ");
    scanf("%i%i%i",&prova_trab->data.dia, &prova_trab->data.mes, &prova_trab->data.ano);
    fprintf(fprova_trab,"%i %i %i\n",prova_trab->data.dia, prova_trab->data.mes, prova_trab->data.ano);

    printf("Peso da Avaliação: ");
    scanf("%f",&prova_trab->peso);
    fprintf(fprova_trab,"%f\n",prova_trab->peso);

    printf("Nota da Avaliação: ");
    scanf("%f",&prova_trab->notas);
    fprintf(fprova_trab,"%f\n",prova_trab->notas);

    return;
}

void cad_aula(Aula *aula)
{
    /*Não é necessario a aula estar dentro da struct aluno
    apenas precisamos para cada aula de uma lista de presença*/

    FILE *faula = fopen("arquivos/faula.dat", "w");

    if(!faula){
        printf("Erro ao Criar arquivo!\n");
        exit(1);
    } 

    printf("Numero de ordem: ");
    scanf("%i", &aula->num_ordem);
    fprintf(faula,"%i\n", aula->num_ordem);

    printf("Data: ");
    scanf("%i%i%i", &aula->data.dia, &aula->data.mes, &aula->data.ano);
    fprintf(faula,"%i %i %i\n", aula->data.dia, aula->data.mes, aula->data.ano);

    printf("Quantidade de Horas de Aula: ");
    scanf("%i", &aula->qtd_horas_aula);
    fprintf(faula,"%i\n", aula->qtd_horas_aula);

    printf("Conteudo da aula: ");
    scanf(" %[^\n]s", aula->conteudo);
    fprintf(faula,"%s\n", aula->conteudo);

    printf("Presença ");            //Fazer uma lista de presença
    scanf(" %c", &aula->presenca);
    fprintf(faula,"%c\n", aula->presenca);

    return;
}

void salvar_displina(Disciplina disciplina[], int num_disc)
{

    FILE *fdisciplina = fopen("arquivos/fdiscilina.dat", "w");

    if(!fdisciplina){
        printf("Erro ao Criar arquivo!\n");
        exit(1);
    } 

    for(int i = 0; i < num_disc ;i++)
    {
       fprintf(fdisciplina,"%s\n",disciplinas[i].nome);
       fprintf(fdisciplina,"%i\n",disciplinas[i].codigo);
       fprintf(fdisciplina,"%i\n",disciplinas[i].ano);
    } 
}

/* 
*   ------> Lendo Registros
*/
void load_professor(Professor *professor) {
    FILE *arq_professor = fopen("arquivos/professor.dat", "r");

    fscanf(arq_professor, "%[^\n]s", professor->nome);
    fscanf(arq_professor, "%i", &professor->num_disc);

    fclose(arq_professor);
}

Disciplina *load_disciplinas(int num_disc)
{
    Disciplina *disciplinas = malloc(num_disc * (sizeof(Disciplina)));

    FILE *ler_discipinas = fopen("arquivos/fdisciplina.dat","r");

    if(!ler_discipinas){
        printf("Erro ao ler arquivo fdisciplinas\n");
    }
    
    for(int i = 0; i < num_disc ; i++){
        fscanf(ler_discipinas,"%[^\n]s", disciplinas[i].nome);
        fscanf(ler_discipinas,"%i", &disciplinas[i].codigo);
        fscanf(ler_discipinas,"%i", &disciplinas[i].ano);
        fscanf(ler_discipinas,"%i", &disciplinas[i].semestre);
        fscanf(ler_discipinas,"%i", &disciplinas[i].qtd_alunos);
        fscanf(ler_discipinas,"%i", &disciplinas[i].qtd_trabalhos);
        fscanf(ler_discipinas,"%i", &disciplinas[i].carga_horaria);
        fscanf(ler_discipinas,"%i", &disciplinas[i].carga_hor_realizada);
        fscanf(ler_discipinas,"%f", &disciplinas[i].nota_minima);
        fscanf(ler_discipinas,"%f", &disciplinas[i].frequencia);
        load_alunos(disciplinas[i].alunos, disciplinas[i].qtd_alunos);
    }
    return disciplinas;
}

void load_alunos(Aluno *alunos, int TAM)
{
    FILE *ler_aluno = fopen("arquivos/falunos.dat", "r");

    if(!ler_aluno){
        printf("Erro ao ler arquivo falunos\n");
    }

    for(int i = 0; i < TAM; i++)
    {
        fscanf(ler_aluno, "%i",&alunos->matricula);
        fscanf(ler_aluno, "%[^\n]s",alunos->nome_aluno);
        load_prova_trab(alunos->prova_trab);
        load_aula(&alunos->aula);
    }
}

void load_prova_trab (Prova_trab *prova_trab)
{
    FILE *ler_prova_trab = fopen("arquivos/fprova_trab.dat", "r");

    if(!ler_prova_trab){
        printf("Erro ao abrir arquivos fprova_trab\n");
    }

    fscanf(ler_prova_trab, "%[^\n]s",prova_trab->nome);
    fscanf(ler_prova_trab, "%c", &prova_trab->tipo);
    fscanf(ler_prova_trab, "%i%i%i", &prova_trab->data.dia, &prova_trab->data.mes, &prova_trab->data.ano);
    fscanf(ler_prova_trab, "%f", &prova_trab->peso);
    fscanf(ler_prova_trab, "%f", &prova_trab->notas);
    return;
}

void load_aula(Aula *aula)
{
    FILE *ler_aula = fopen("arquivos/faula.dat", "r");

    if(!ler_aula){
        printf("Erro ao abrir arquivo faula\n");
    }

    fscanf(ler_aula, "%i",&aula->num_ordem);
    fscanf(ler_aula, "%i%i%i",&aula->data.dia, &aula->data.mes, &aula->data.ano);
    fscanf(ler_aula, "%i",&aula->qtd_horas_aula);
    fscanf(ler_aula, "%[^\n]s",aula->conteudo);
    fscanf(ler_aula, "%c",&aula->presenca);

    return;
}

Disciplina *edit_disciplina(int ){


    FILE *fdisciplina = fopen("arquivos/fdiscilina.dat", "w");

    int op;

    if(!fdisciplina){
        printf("Erro ao abrir arquivo!\n");
        exit(1);

        printf("Nome da disciplina: ");
        scanf(" %[^\n]s", disciplinas[i].nome);
        fprintf(fdisciplina,"%s\n",disciplinas[i].nome);

        printf("Codigo: ");
        scanf("%i",&disciplinas[i].codigo);
        fprintf(fdisciplina,"%i\n",disciplinas[i].codigo);

        printf("Ano: ");
        scanf("%i",&disciplinas[i].ano);
        fprintf(fdisciplina,"%i\n",disciplinas[i].ano);

        printf("Semestre: ");
        scanf("%i",&disciplinas[i].semestre);
        fprintf(fdisciplina,"%i\n",disciplinas[i].semestre);

        printf("Quantidade de Alunos: ");
        scanf("%i",&disciplinas[i].qtd_alunos);
        fprintf(fdisciplina,"%i\n", disciplinas[i].qtd_alunos);

        printf("Quantidade de Trabalhos: ");
        scanf("%i",&disciplinas[i].qtd_trabalhos);
        fprintf(fdisciplina,"%i\n", disciplinas[i].qtd_trabalhos);

        printf("Carga Horaria: ");
        scanf("%i",&disciplinas[i].carga_horaria);
        fprintf(fdisciplina,"%i\n", disciplinas[i].carga_horaria);

        printf("Carga Horaria Realizada: ");
        scanf("%i",&disciplinas[i].carga_hor_realizada);
        fprintf(fdisciplina,"%i\n", disciplinas[i].carga_hor_realizada);

        printf("Nota minima: ");
        scanf("%f",&disciplinas[i].nota_minima);
        fprintf(fdisciplina,"%f\n", disciplinas[i].nota_minima);

        printf("Frequencia para aprovação: ");
        scanf("%f",&disciplinas[i].frequencia);
        fprintf(fdisciplina,"%f\n", disciplinas[i].frequencia);

        printf("Deseja recadastrar a turma?\nSIM (1) NAO (0)\n");
            scanf("%i",&op);

        if(op == 1)
            cad_aluno(disciplinas[i].alunos, disciplinas->qtd_alunos);
    }
    return disciplinas;
}

void menu(Professor *professor, Disciplina *disciplinas)
{
    int op, aux;

    printf("########### Gerenciador ###########\n\n");
    printf("* (1) Editar Professor\n");
    printf("* (2) Editar Displina\n");
    printf("Digite a opção desejada: ");
    scanf("%i", &op);

    switch (op)
    {
    case 1:
        *professor = cad_professor();
        break;
    
    case 2:
        printf("Qual Disciplina deseja Editar?\n");
        for (int i = 0; i < professor->num_disc; i++)
            printf("%i %s\n", i+1, disciplinas[i]->nome);

        scanf("%i", &aux);
        disciplinas = edit_disciplina(aux-1);
        
        break;
    case 3:

        break;
    }
}