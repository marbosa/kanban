#include "entidades.h"

// ============================================================
// ENTIDADES
// ============================================================

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