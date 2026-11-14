/**
 * @file entidades.cpp
 * @brief Implementação das classes de Entidades do sistema Kanban
 */
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

// ------------------------------------------------------------
// Entidade: CartaoDeAtividade
// Atributos: identificador, nome, descricao, prioridade, estado, tamanho, entrada, inicio, termino
// ------------------------------------------------------------
void CartaoDeAtividade::setIdentificador(const Identificador& identificador) {
    this->identificador = identificador;
}

Identificador CartaoDeAtividade::getIdentificador() const {
    return identificador;
}

void CartaoDeAtividade::setNome(const Nome& nome) {
    this->nome = nome;
}

Nome CartaoDeAtividade::getNome() const {
    return nome;
}

void CartaoDeAtividade::setDescricao(const Texto& descricao) {
    this->descricao = descricao;
}

Texto CartaoDeAtividade::getDescricao() const {
    return descricao;
}

void CartaoDeAtividade::setPrioridade(const Prioridade& prioridade) {
    this->prioridade = prioridade;
}

Prioridade CartaoDeAtividade::getPrioridade() const {
    return prioridade;
}

void CartaoDeAtividade::setEstado(const Estado& estado) {
    this->estado = estado;
}

Estado CartaoDeAtividade::getEstado() const {
    return estado;
}

void CartaoDeAtividade::setTamanho(const Tamanho& tamanho) {
    this->tamanho = tamanho;
}

Tamanho CartaoDeAtividade::getTamanho() const {
    return tamanho;
}

void CartaoDeAtividade::setInicio(const Timestamp& timestamp) {
    this->inicio = timestamp;
}

Timestamp CartaoDeAtividade::getInicio() const {
    return inicio;
}

void CartaoDeAtividade::setTermino(const Timestamp& timestamp) {
    this->termino = timestamp;
}

Timestamp CartaoDeAtividade::getTermino() const {
    return termino;
}

void CartaoDeAtividade::setEntrada(const Timestamp& timestamp) {
    this->entrada = timestamp;
}

Timestamp CartaoDeAtividade::getEntrada() const {
    return entrada;
}