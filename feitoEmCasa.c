#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int pass;
    int total;
} Class;

// Função para calcular o aumento na taxa de aprovação ao adicionar um aluno
double calculaAumento(Class c) {
    return (double)(c.pass + 1) / (c.total + 1) - (double)c.pass / c.total;
}

// Função de comparação para o qsort
int compara(const void* a, const void* b) {
    Class* classA = (Class*)a;
    Class* classB = (Class*)b;
    double aumentoA = calculaAumento(*classA);
    double aumentoB = calculaAumento(*classB);
    if (aumentoA < aumentoB) return 1;
    if (aumentoA > aumentoB) return -1;
    return 0;
}


// Função principal para calcular a máxima média de taxa de aprovação
double maxAverageRatio(int** classes, int classesSize, int* classesColSize, int extraStudents) {
    // Converte o array de arrays para um array de Class
    Class* classArray = (Class*)malloc(classesSize * sizeof(Class));
    int i;
    for (i = 0; i < classesSize; i++) {
        classArray[i].pass = classes[i][0];
        classArray[i].total = classes[i][1];
    }

    // Ordena as turmas pelo maior aumento na taxa de aprovação
    qsort(classArray, classesSize, sizeof(Class), compara);

    // Adiciona os alunos extras
    for (i = 0; i < extraStudents; i++) {
        // Adiciona o aluno extra à turma que proporciona o maior aumento
        classArray[0].pass++;
        classArray[0].total++;

        // Reordena o array para garantir que a próxima adição seja feita corretamente
        qsort(classArray, classesSize, sizeof(Class), compara);
    }

    // Calcula a média das taxas de aprovação
    double sum = 0;
    for (i = 0; i < classesSize; i++) {
        sum += (double)classArray[i].pass / classArray[i].total;
    }
    free(classArray);
    return sum / classesSize;
}

int main() {
    // Exemplo de entrada
    int* classes[] = {
        (int[]){1, 2},
        (int[]){3, 5},
        (int[]){2, 2}
    };
    int classesSize = 3;
    int classesColSize[] = {2, 2, 2};
    int extraStudents = 2;

    double result = maxAverageRatio(classes, classesSize, classesColSize, extraStudents);
    printf("A máxima média de taxa de aprovação é: %.5f\n", result);

    return 0;
}