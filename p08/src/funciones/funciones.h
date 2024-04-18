#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
#include <cmath>
#include <limits>
#include <filesystem>

namespace fs = std::filesystem;

std::vector<std::string> extraerFicherosEjemplo(const std::string&);
const int cuantosFicherosAEjecutar(const std::string&);
const int cantidadMaximaFicheros(const std::string&);
const std::string reemplazarComaDecimalPorPunto(const std::string&);
const int contarDecimales(const double, const int);