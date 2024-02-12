#include "debug.h"
#include "debug_0.h"
#include "debug_1.h"
#include "debug_2.h"

Debug* crear_debug(const std::string kValorDebug) {
  Debug* debugger;
  switch (std::stoi(kValorDebug)) {
    case 0: debugger = new Debug0(); break;
    case 1: debugger = new Debug1(); break;
    case 2: debugger = new Debug2(); break;
    default:  debugger = nullptr;
  }
  return debugger;
}