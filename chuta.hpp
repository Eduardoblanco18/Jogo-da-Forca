#pragma once
#include <map>
#include <array>
#include <string>

void chuta(std::string palavra_secreta, std::map<char, bool>& chutou, std::array<char, 5>& chutes_errados, int quant_de_erros);