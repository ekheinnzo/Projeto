#ifndef FUNCOES
#define FUNCOES

//Pensei em ao inves de void as funçoes retornarem um inteiro para sabermos se a escrita de certo.

//>>>>>> Funções para a criação de arquivos <<<<<<
Professor cad_professor();
Disciplina *cad_disciplina(int num_disc);
    void cad_aluno(Aluno alunos[], int TAM);
        void cad_prova_trab(Prova_trab *prova_trab);
            void cad_aula(Aula *aula);

//>>>>>> Funções para Leitura de arquivos <<<<<<
void load_professor(Professor *professor);
Disciplina *load_disciplinas(int num_disc);
    void load_alunos(Aluno *alunos, int TAM);
        void load_prova_trab (Prova_trab *prova_trab);
            void load_aula(Aula *aula);

void menu(Professor *professor, Disciplina *disciplinas, FILE *save_professor);
Disciplina *edit_disciplina(int num_disc);

#endif