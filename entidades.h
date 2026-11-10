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

// ------------------------------------------------------------
// Entidade: Pessoa
// Atributos: email (PK), nome, senha, papel
// ------------------------------------------------------------
/** @brief Entidade Pessoa: usuario do sistema (gestor ou desenvolvedor).
 *  O email e a chave primaria e nao deve ser alterado apos o cadastro. */
class Pessoa {
private:
    Email email;
    Nome nome;
    Senha senha;
    Papel papel;
public:
    /** @brief Define o email (chave primaria). */
    void setEmail(const Email&);
    /** @brief Retorna o email. */
    Email getEmail() const;

    /** @brief Define o nome. */
    void setNome(const Nome&);
    /** @brief Retorna o nome. */
    Nome getNome() const;

    /** @brief Define a senha. */
    void setSenha(const Senha&);
    /** @brief Retorna a senha. */
    Senha getSenha() const;

    /** @brief Define o papel (GESTOR ou DESENVOLVEDOR). */
    void setPapel(const Papel&);
    /** @brief Retorna o papel. */
    Papel getPapel() const;
};

#endif //KANBAN_ENTIDADES_H