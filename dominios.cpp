#include "dominios.h"
#include <stdexcept>

using namespace std;

// ============================================================
// DOMINIOS DA ENTIDADE PESSOA: Email, Senha, Papel
// ============================================================


// ============================================================
// DOMINIOS DA ENTIDADE PROJETO: Texto, Identificador
// ============================================================


// ============================================================
// DOMINIOS DA ENTIDADE QUADRO: Nome, Limite
// ============================================================
void Limite::validar(const int valor) {
    if (valor < LIMITE_MIN || valor > LIMITE_MAX) {
        throw invalid_argument("Limite invalido!");
    }
}

int Limite::getLimite() const {
    return valor;
}

// ============================================================
// DOMINIOS DA ENTIDADE CARTAO DE ATIVIDADE: Timestamp, Prioridade, Estado, Tamanho
// ============================================================
