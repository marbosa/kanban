#ifndef KANBAN_APRESENTACAO_PESSOA_H
#define KANBAN_APRESENTACAO_PESSOA_H

#include "interfaces.h"

/**
 * @file apresentacao_pessoa.h
 * @brief Camada de apresentacao: controladoras de Pessoa e Autenticacao (cin/cout).
 *
 * Validam os dados de entrada (via classes dominio) e dependem apenas de IServicoPessoa.
 */

/** @brief Controladora de apresentacao de autenticacao. */
class CntrApresentacaoAutenticacao : public IApresentacaoAutenticacao {
private:
    IServicoPessoa* cntrServico = nullptr;
public:
    bool autenticar(Email*, Papel*) override;
    void setCntrServico(IServicoPessoa* cntr) override { cntrServico = cntr; }
};

/** @brief Controladora de apresentacao dos servicos de Pessoa. */
class CntrApresentacaoPessoa : public IApresentacaoPessoa {
private:
    IServicoPessoa* cntrServico = nullptr;
    void ler();
    void atualizar(const Email&);
    bool excluir(const Email&);
    void listar();
public:
    void cadastrar() override;
    bool executar(const Email&) override;
    void setCntrServico(IServicoPessoa* cntr) override { cntrServico = cntr; }
};

#endif // KANBAN_APRESENTACAO_PESSOA_H
