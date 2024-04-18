#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
#include <filesystem>

namespace fs = std::filesystem;

std::vector<std::string> extraerFicherosEjemplo(const std::string&);
const int cuantosFicherosAEjecutar(const std::string&);
const int cantidadMaximaFicheros(const std::string&);