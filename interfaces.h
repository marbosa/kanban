#ifndef KANBAN_INTERFACES_H
#define KANBAN_INTERFACES_H

#include <list>
#include "dominios.h"
#include "entidades.h"

/**
 * @file interfaces.h
 * @brief Interfaces (classes abstratas) entre os modulos - parte Pessoa.
 */

// ------------------------------------------------------------
// Camada de servico: modulo Pessoas
// ------------------------------------------------------------
/** @brief Servicos de Pessoa providos pela camada de servico. */
class IServicoPessoa {
public:
    /** @brief Cria uma pessoa.
     *  @return true se criada; false se ja existe pessoa com o mesmo email. */
    virtual bool criar(const Pessoa&) = 0;
    /** @brief Le os dados de uma pessoa.
     *  @param pessoa Entrada: email preenchido. Saida: demais dados preenchidos.
     *  @return true se encontrada. */
    virtual bool ler(Pessoa*) = 0;
    /** @brief Atualiza nome, senha e papel (o email identifica a pessoa e nao muda).
     *  @return true se atualizada; false se nao existe. */
    virtual bool atualizar(const Pessoa&) = 0;
    /** @brief Exclui uma pessoa.
     *  @return true se excluida; false se nao existe ou se geraria inconsistencia. */
    virtual bool excluir(const Email&) = 0;
    /** @brief Lista os identificadores (emails) de todas as pessoas. */
    virtual bool listar(list<Email>*) = 0;
    /** @brief Autentica um usuario.
     *  @param papel Saida: papel do usuario autenticado.
     *  @return true se email e senha conferem. */
    virtual bool autenticar(const Email&, const Senha&, Papel*) = 0;
    virtual ~IServicoPessoa() {}
};

// ------------------------------------------------------------
// Camada de apresentacao: modulo Pessoas
// ------------------------------------------------------------
/** @brief Interface de apresentacao para autenticacao de usuario. */
class IApresentacaoAutenticacao {
public:
    /** @brief Solicita credenciais e autentica.
     *  @param email Saida: email do usuario autenticado.
     *  @param papel Saida: papel do usuario autenticado.
     *  @return true se autenticado. */
    virtual bool autenticar(Email*, Papel*) = 0;
    /** @brief Define a interface de servico utilizada. */
    virtual void setCntrServico(IServicoPessoa*) = 0;
    virtual ~IApresentacaoAutenticacao() {}
};

/** @brief Interface de apresentacao dos servicos de Pessoa. */
class IApresentacaoPessoa {
public:
    /** @brief Fluxo de criacao de conta (nao exige autenticacao). */
    virtual void cadastrar() = 0;
    /** @brief Menu de servicos de Pessoa para usuario autenticado.
     *  @return false se a conta foi excluida (o usuario deve sair); true caso contrario. */
    virtual bool executar(const Email&) = 0;
    /** @brief Define a interface de servico utilizada. */
    virtual void setCntrServico(IServicoPessoa*) = 0;
    virtual ~IApresentacaoPessoa() {}
};

#endif // KANBAN_INTERFACES_H
