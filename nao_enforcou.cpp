#include <vector>
#include "nao_enforcou.hpp"

extern std::vector<char> chutes_errados;

bool nao_enforcou() {
    return chutes_errados.size() < 5;
}