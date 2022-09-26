/* TO-DO:
 *      - Lógica limpeza profunda;
 *      - Path p/windows;
 */


#include <fstream>
#include "classes.h"
#include "util.h"

int main() {
    // SEMANA 0 - BASE ===============================================================================
    Ciclic_list_node room1("Cozinha",&room1);
    Ciclic_list lista(&room1);
    // anchor_node==room1
    Ciclic_list_node room2("Banheiro Grande",&room2);
    Ciclic_list_node room3("Banheirinho",&room3);
    lista.pushback(room2);
    lista.pushback(room3);
    /* Teste: lista.print_list();*/

    // FAXINEIROS ====================================================================================
    Ciclic_list_node* lucas;
    Ciclic_list_node* paula;
    Ciclic_list_node* felps;

    // INPUT =========================================================================================
    int ano, mes, dia, n_semanas = 0;
    while(inputData(ano,mes,dia,n_semanas)) {}
    int dias_base = diasDecorridos(2022,9,24);  // Usar data correta
    int dias_atual = diasDecorridos(ano,mes,dia);
    int dias_decorridos = dias_atual - dias_base;

    // UPDATE BASE =====================================================================================
    int rot = (dias_decorridos/7)%3;
    lucas = lista.get_anchor();
    // Rotações
    for(int i=0; i<rot; i++) {
        lucas = lucas->get_next();
    }
    paula = lucas->get_next();
    felps = paula->get_next();
    
    // PRINT LISTA ===================================================================================
    const char data_path[19] = "../data/tabela.txt";
    printTabela(lucas,paula,felps,n_semanas,data_path);
    
    return 0;
}
