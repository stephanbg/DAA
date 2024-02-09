#pragma once

#include <regex>
#include <algorithm>

int ContarDecimales(const long double);
bool EsNumero(const std::string&);
const std::string ConvertirAMayusculas(const std::string&);
void RotarUnoHaciaDerecha(std::vector<std::string>&);
const std::string QuitarEspacios(const std::string&);
void EliminarCoincidencias(const std::vector<std::string>&, std::string&);
bool sonTodoDigitos(const std::string&);