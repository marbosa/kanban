#include "utilitarios.h"
#include <stdexcept>

using namespace std;

bool ehBissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

bool ehLetra(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool ehDigito(char c) {
    return c >= '0' && c <= '9';
}

int paraInt(const string& s) {
    if (s.empty()) {
        throw invalid_argument("Numero invalido.");
    }
    int r = 0;
    for (size_t i = 0; i < s.size(); i++) {
        if (!ehDigito(s[i])) {
            throw invalid_argument("Numero invalido.");
        }
        r = r * 10 + (s[i] - '0');
    }
    return r;
}

bool ehPontuacao(char c) {
    return c == ',' || c == ';' || c == '.' ||
           c == ':' || c == '?' || c == '!';
}
