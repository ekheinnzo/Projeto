#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "funcoes.h"

int main()
{
    Professor professor;
    Disciplina *disciplinas;

    //Criando diretório para os arquivos
    system("mkdir arquivos");

    //Checando se tem Usuario cadastrado se nao houver cria o usuario
    if(!fopen("arquivos/professor.dat", "r")){
        professor = cad_professor();
        disciplinas = cad_disciplina(professor.num_disc);
    }
    else{
        load_professor(&professor);
        disciplinas = load_disciplinas(professor.num_disc);
    }
    menu(&professor, disciplinas);

    return 0;
}

