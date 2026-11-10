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
// Entidade: Pessoa
// Atributos: email, nome, senha, papel
// ------------------------------------------------------------

void Pessoa::setEmail(const Email& e) {
    email = e;
}

Email Pessoa::getEmail() const {
    return email;
}

void Pessoa::setNome(const Nome& n) {
    nome = n;
}

Nome Pessoa::getNome() const {
    return nome;
}

void Pessoa::setSenha(const Senha& s) {
    senha = s;
}

Senha Pessoa::getSenha() const {
    return senha;
}

void Pessoa::setPapel(const Papel& p) {
    papel = p;
}

Papel Pessoa::getPapel() const {
    return papel;
}
