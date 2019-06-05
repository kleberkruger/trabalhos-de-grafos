#include "flowsapp.h"

/**
 * Executa a aplicação de acordo com os parâmetros de inicialização.
 *
 * <algorithm> <filepath-in> <filepath-out>
 *
 * <algorithm>: algoritmo de execução ("ford-fulkerson" ou "edmonds-karp");
 * <filepath-in>: arquivo de entrada que contém as informações do grafo;
 * <filepath-out>: arquivo de saída onde será exibido o resultado.
 *
 * Exemplos:
 * ./main ford-fulkerson in.txt out.txt
 * ./main edmonds-karp in.txt out.txt
 *
 * @param argc quantidade de parâmetros
 * @param argv valores dos parâmetros
 *
 * @return 0 caso execute com sucesso; outro valor caso ocorra algum erro.
 */
int main(int argc, char *argv[]) {
    if (argc != 4) {
        throw std::invalid_argument("Run: <algorithm> <filepath-in> <filepath-out>");
    }

    FlowsApp().start(argv[2], argv[3], argv[1]);

    return EXIT_SUCCESS;
}