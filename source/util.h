#ifndef _UTIL_H_
#define _UTIL_H_

#include "classes.h"
#include <fstream>

int anoBissexto(const int ano);
// Calcula dias decorridos desde 01.01.00
int diasDecorridos(const int ano, const int mes, const int dia);
int inputData(int& ano, int& mes, int& dia, int& n_semanas);
void printTabela(Ciclic_list_node* ptr1, Ciclic_list_node* ptr2, Ciclic_list_node* ptr3,
    const int count, const char path[19]);

#endif