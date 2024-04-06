#pragma once

#include <functional> // Para std::function
#include <utility>    // Para std::move

#include "../solucion/solucion.h"
#include "../problema/problema.h"
#include "../algoritmos_min_TCT/algoritmos_min_TCT.h"
#include "../controlador_tiempo/controlador_tiempo.h"

std::pair<std::vector<Solucion>, int> ejecutarAlgoritmo(AlgoritmoMinimizarTCT*, int, Problema&);