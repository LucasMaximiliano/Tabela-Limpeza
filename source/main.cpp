/* TO-DO:
 *      - Criar repo;
 *      - Lógica limpeza profunda;
 *      - Path p/windows;
 *      - Função print;
 */


#include <fstream>
#include "classes.h"
#include "util.h"

int main() {
    // SEMANA 0 - BASE ===============================================================================
    Ciclic_list_node quarto1("Cozinha",&quarto1);
    Ciclic_list lista(&quarto1);
    // anchor_node==quarto1
    Ciclic_list_node quarto2("Banheiro Grande",&quarto2);
    Ciclic_list_node quarto3("Banheirinho",&quarto3);
    lista.pushback(quarto2);
    lista.pushback(quarto3);
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
    // Criar obj ofstream & abrir arquivo tabela.txt
    std::ofstream fw("../data/tabela.txt", std::ofstream::out);
    if(fw.is_open()) {
        fw << "SEMANA " << 1 << "\n";
        fw << "  Lucas: " << lucas->get_quarto() << "\n";
        fw << "  Paula: " << paula->get_quarto() << "\n";
        fw << "  Felps: " << felps->get_quarto() << "\n";
        
        for(int i=2; i<=n_semanas; i++) {
            // Rotações
            lucas = lucas->get_next();
            paula = paula->get_next();
            felps = felps->get_next();

            fw << "SEMANA " << i << "\n";
            fw << "  Lucas: " << lucas->get_quarto() << "\n";
            fw << "  Paula: " << paula->get_quarto() << "\n";
            fw << "  Felps: " << felps->get_quarto() << "\n";
        }
        fw.close();
    } else {
        std::cout << "Problema ao abrir arquivo *.txt" << std::endl;
    }
    
    return 0;
}
