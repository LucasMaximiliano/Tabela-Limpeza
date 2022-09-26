#ifndef _UTIL_H_
#define _UTIL_H_

#include <stdio.h>

int anoBissexto(const int ano);
// Calcula dias decorridos desde 01.01.00
int diasDecorridos(const int ano, const int mes, const int dia);
int inputData(int& ano, int& mes, int& dia, int& n_semanas);

#endif