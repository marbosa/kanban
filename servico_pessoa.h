#ifndef KANBAN_SERVICO_PESSOA_H
#define KANBAN_SERVICO_PESSOA_H

#include <map>
#include <string>
#include "interfaces.h"

/**
 * @file servico_pessoa.h
 * @brief Camada de servico: container e controladora de Pessoa.
 */

/** @brief Container que armazena Pessoa em memoria, indexada pelo email. */
class ContainerPessoa {
private:
    map<string, Pessoa> dados;
public:
    /** @brief Inclui pessoa. @return false se o email ja existe. */
    bool incluir(const Pessoa&);
    /** @brief Remove pessoa. @return false se nao existe. */
    bool remover(const Email&);
    /** @brief Busca pela chave (email). @param pessoa Entrada/saida. @return true se achou. */
    bool pesquisar(Pessoa*) const;
    /** @brief Atualiza pessoa existente. @return false se nao existe. */
    bool atualizar(const Pessoa&);
    /** @brief Retorna todos os emails cadastrados. */
    list<Email> listar() const;
};

/** @brief Controladora de servico de Pessoa: realiza IServicoPessoa. */
class CntrServicoPessoa : public IServicoPessoa {
private:
    ContainerPessoa container;
    // Gancho de integridade referencial: consultar Projeto/Cartao aqui
    // para impedir exclusao que gere inconsistencia.
    bool podeExcluir(const Email&) const;
public:
    bool criar(const Pessoa&) override;
    bool ler(Pessoa*) override;
    bool atualizar(const Pessoa&) override;
    bool excluir(const Email&) override;
    bool listar(list<Email>*) override;
    bool autenticar(const Email&, const Senha&, Papel*) override;
};

#endif // KANBAN_SERVICO_PESSOA_H
