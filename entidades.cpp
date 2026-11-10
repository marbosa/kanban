#include "entidades.h"

// ------------------------------------------------------------
// Entidade: Projeto
// Atributos: identificador, nome, descricao, inicio, termino
// ------------------------------------------------------------

// Identificador
void Projeto::setIdentificador(const Identificador& id) {
    identificador = id;
}

Identificador Projeto::getIdentificador() const {
    return identificador;
}

// Nome
void Projeto::setNome(const Nome& n) {
    nome = n;
}

Nome Projeto::getNome() const {
    return nome;
}

// Descricao (depende do dominio Texto)
void Projeto::setDescricao(const Texto& d) {
    descricao = d;
}

Texto Projeto::getDescricao() const {
    return descricao;
}

// Inicio (depende do dominio Timestamp)
void Projeto::setInicio(const Timestamp& t) {
    inicio = t;
}

Timestamp Projeto::getInicio() const {
    return inicio;
}

// Termino (depende do dominio Timestamp)
void Projeto::setTermino(const Timestamp& t) {
    termino = t;
}

Timestamp Projeto::getTermino() const {
    return termino;
}

// ------------------------------------------------------------
// Entidade: Quadros
// Métodos: setIdentificador, getIdentificador, setNome, getNome, setLimite, getLimite
// ---------------------------------------------------
void Quadro::setIdentificador(const Identificador& identificador) {
    this->identificador = identificador;
}

Identificador Quadro::getIdentificador() const {
    return identificador;
}

void Quadro::setNome(const Nome& nome) {
    this->nome = nome;
}

Nome Quadro::getNome() const {
    return nome;
}

void Quadro::setLimite(const Limite& limite) {
    this->limite = limite;
}

Limite Quadro::getLimite() const {
    return limite;
}