//
// Created by wmatheus-de-nyx on
#ifndef KANBAN_ENTIDADES_H
#define KANBAN_ENTIDADES_H

#include "dominios.h"
// ------------------------------------------------------------
// Entidade: Projeto
// Atributos: identificador, nome, descricao, inicio, termino
// ---------------------------------------------------

class Projeto {
private:
    Identificador identificador;
    Nome nome;
    Texto descricao;
    Timestamp inicio;
    Timestamp termino;
public:
    void setIdentificador(const Identificador&);
    Identificador getIdentificador() const;

    void setNome(const Nome&);
    Nome getNome() const;

    void setDescricao(const Texto&);
    Texto getDescricao() const;

    void setInicio(const Timestamp&);
    Timestamp getInicio() const;

    void setTermino(const Timestamp&);
    Timestamp getTermino() const;
};

#endif //KANBAN_ENTIDADES_H