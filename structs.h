#ifndef STRUCTS
#define STRUCTS

typedef struct
{
    char nome[51];
    int num_disc;
}Professor;

typedef struct TData
{
    int dia;
    int mes;
    int ano;
}Data;

typedef struct
{
    int num_ordem;
    Data data;
    int qtd_horas_aula;
    char conteudo[256];
    char presenca;
} Aula;

typedef struct
{
    char nome[51];
    char tipo;
    Data data; 
    float peso;
    float notas;
} Prova_trab;

typedef struct TAluno
{
    int matricula;
    char nome_aluno[51];
    Prova_trab prova_trab[15]; // a ideia inicial e que de os indices de 0 - 3 comtenham provas e de 4 -13 trabalhos, 14 - Exame
    Aula aula;
} Aluno;

typedef struct TDisciplina
{
    char nome[51];
    int codigo;
    int ano;
    int semestre;
    int qtd_alunos;
    int qtd_provas;
    int qtd_trabalhos;
    int carga_horaria;
    int carga_hor_realizada;
    float nota_minima;
    float frequencia; // Percentual de freq p/ aprovação
    Aluno alunos[35];

}Disciplina;

#endif
