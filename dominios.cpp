#include "dominios.h"
#include <stdexcept>
#include <string>

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

void Limite::setLimite(int valor) {
    validar(valor);
    this->valor = valor;
}

int Limite::getLimite() const {
    return valor;
}

void Nome::validar(const string& nome) {
    const string CARACTERES_PERMITIDOS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz ";

    if (nome.size() < NOME_MIN || nome.size() > NOME_MAX) {
        throw invalid_argument("Nome invalido!");
    }

    if (nome.front() == ' ' || nome.back() == ' ') {
        throw invalid_argument("Nome invalido!");
    }

    for (size_t i = 0; i < nome.size(); i++) {
        if (CARACTERES_PERMITIDOS.find(nome[i]) == string::npos) {
            throw invalid_argument("Nome invalido!");
        }
        if (nome[i] == ' ') {
            if (nome[i + 1] == ' ') {
                throw invalid_argument("Nome invalido!");
            }
        }
    }
}

void Nome::setNome(const string& nome) {
    validar(nome);
    this->nome = nome;
}

string Nome::getNome() const {
    return nome;
}

// ============================================================
// DOMINIOS DA ENTIDADE CARTAO DE ATIVIDADE: Timestamp, Prioridade, Estado, Tamanho
// ============================================================
void Prioridade::validar(const string& prioridade) {
    for (const char* OPCAO : OPCOES) {
        if (prioridade == OPCAO) {
            return;
        }
    }

    throw invalid_argument("Prioridade invalida!");
}

void Prioridade::setPrioridade(const string& prioridade) {
    validar(prioridade);
    this->prioridade = prioridade;
}

string Prioridade::getPrioridade() const {
    return prioridade;
}

void Estado::validar(const string& estado) {
    for (const char* OPCAO : OPCOES) {
        if (estado == OPCAO) {
            return;
        }
    }

    throw invalid_argument("Estado invalido!");
}

void Estado::setEstado(const string& estado) {
    validar(estado);
    this->estado = estado;
}

string Estado::getEstado() const {
    return estado;
}

void Tamanho::validar(const string& tamanho) {
    for (const char* OPCAO : OPCOES) {
        if (tamanho == OPCAO) {
            return;
        }
    }

    throw invalid_argument("Tamanho invalido!");
}

void Tamanho::setTamanho(const string& tamanho) {
    validar(tamanho);
    this->tamanho = tamanho;
}

string Tamanho::getTamanho() const {
    return tamanho;
}