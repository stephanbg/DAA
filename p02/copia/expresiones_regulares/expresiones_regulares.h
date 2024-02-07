#include <regex>

class ExpresionesRegulares {
public:
    const std::regex& get_patron_constante() const { return kPatronConstante; }
    const std::regex& get_patron_directo() const { return kPatronDirecto; }
    const std::regex& get_patron_indirecto() const { return kPatronIndirecto; }
    const std::regex& get_patron_directo_no_R0() const { return kPatronDirectoNoAceptaR0; }
    const std::regex& get_patron_etiquetas() const { return kPatronEtiquetas; }
private:
  const std::string K32Registros = "([0-9]|[1-2][0-9]|3[0-1])";
  const std::string K32RegistrosMenosR0 = "([1-9]|[1-2][0-9]|3[0-1])";

  const std::regex kPatronConstante{"^=[-+]?\\d+([,.]?\\d+|\\d*)$"}; // Empieza por '=' y acaba por uno o más dígitos
  const std::regex kPatronDirecto{"^" + K32Registros + "$"}; // permite 0-31 registros
  const std::regex kPatronIndirecto{"^\\*" + K32Registros + "$"}; // Empieza por '*' y acaba por uno o más dígitos
  const std::regex kPatronDirectoNoAceptaR0{"^" + K32RegistrosMenosR0 + "$"}; // Empieza por 0's + [1-9]'s o [1-9]'s
  const std::regex kPatronEtiquetas{"^=\\d+$"}; // Empieza por '*' + 0's + [1-9]'s o [1-9]'s 

  //const std::regex kPatron2("^([0-9]|[1-9][0-9]{1,2}|10[0-1][0-9]|102[0-3])$"); // permite 0-1023 registros
  //const std::regex kPatron4("^=[-+]?" + K32Registros + "[,.]?\\d+$"); // Empieza por '=' + 0's + [1-9]'s o [1-9]'s
};