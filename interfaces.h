/**
 * @file interfaces.h
 * @brief Declaração das interfaces que fazem a conexão entre as camadas de serviço e de apresentação
 */

#ifndef KANBAN_INTERFACES_H
#define KANBAN_INTERFACES_H

#include "dominios.h"
#include "entidades.h"
#include <list>

/**
 * @brief Interface dos serviços de pessoa
 *
 * Especifica os serviços de pessoa providos pela camada de serviço e usados pela camada de apresentação, incluindo a autenticação de usuário
 */
class IServicosPessoas {
    public:
        virtual ~IServicosPessoas() = default;

        /**
         * @brief Cria uma pessoa (cria a conta do usuário)
         * @param pessoa Pessoa a ser criada
         * @retval true Pessoa criada com sucesso
         * @retval false Pessoa já existe ou dados inconsistentes
         */
        virtual bool criar(const Pessoa& pessoa) = 0;

        /**
         * @brief Lê os dados de uma pessoa
         * @param pessoa Ponteiro para a pessoa, que entra com o email e sai com os dados preenchidos
         * @retval true Pessoa encontrada
         * @retval false Pessoa não encontrada
         */
        virtual bool ler(Pessoa* pessoa) = 0;

        /**
         * @brief Atualiza os dados de uma pessoa
         *
         * O email identifica a pessoa e não pode ser alterado
         *
         * @param pessoa Pessoa com o email da pessoa existente e os novos dados
         * @retval true Pessoa atualizada com sucesso
         * @retval false Pessoa não encontrada ou dados inconsistentes
         */
        virtual bool atualizar(const Pessoa& pessoa) = 0;

        /**
         * @brief Exclui uma pessoa
         * @param email Email da pessoa a ser excluída
         * @retval true Pessoa excluída com sucesso
         * @retval false Pessoa não encontrada ou exclusão causaria inconsistência
         */
        virtual bool excluir(const Email& email) = 0;

        /**
         * @brief Lista os identificadores (emails) das pessoas cadastradas
         * @param[out] emails Lista que recebe o email de cada pessoa cadastrada
         * @retval true Listagem realizada com sucesso
         * @retval false Falha na listagem
         */
        virtual bool listar(list<Email>* emails) = 0;

        /**
         * @brief Autentica um usuário
         * @param[in] email Email informado pelo usuário
         * @param[in] senha Senha informada pelo usuário
         * @param[out] papel Papel do usuário autenticado
         * @retval true Usuário autenticado com sucesso
         * @retval false Pessoa não encontrada ou senha incorreta
         */
        virtual bool autenticar(const Email& email, const Senha& senha, Papel* papel) = 0;
};

/**
 * @brief Interface da apresentação de pessoas
 *
 * Especifica o serviço de interação com o usuário para pessoas
 */
class IUPessoas {
    public:
        virtual ~IUPessoas() = default;

        /**
         * @brief Executa a interação com o usuário para pessoas
         * @retval true Interação concluída com sucesso
         * @retval false Falha durante a interação
         */
        virtual bool executar() = 0;

        /**
         * @brief Define a controladora de serviços de pessoa
         * @param cntr Ponteiro para a controladora que realiza IServicosPessoas
         */
        virtual void setCntrServicosPessoas(IServicosPessoas* cntr) = 0;
};

/**
 * @brief Interface dos serviços de quadro
 *
 * Especifica os serviços de quadro providos pela camada de serviço e usados pela camada de apresentação
 */
class IServicosQuadros {
    public:
        virtual ~IServicosQuadros() = default;

        /**
         * @brief Cria um quadro
         * @param quadro Quadro a ser criado
         * @retval true Quadro criado com sucesso
         * @retval false Quadro já existe ou dados inconsistentes
         */
        virtual bool criar(const Quadro& quadro) = 0;

        /**
         * @brief Lê os dados de um quadro
         * @param quadro Ponteiro para o quadro, que entra com o identificador e sai com os dados preenchidos
         * @retval true Quadro encontrado
         * @retval false Quadro não encontrado
         */
        virtual bool ler(Quadro* quadro) = 0;

        /**
         * @brief Atualiza os dados de um quadro
         * @param quadro Quadro com o identificador do quadro existente e os novos dados
         * @retval true Quadro atualizado com sucesso
         * @retval false Quadro não encontrado ou dados inconsistentes
         */
        virtual bool atualizar(Quadro& quadro) = 0;

        /**
         * @brief Exclui um quadro
         * @param identificador Identificador do quadro a ser excluído
         * @retval true Quadro excluído com sucesso
         * @retval false Quadro não encontrado ou exclusão causaria inconsistência
         */
        virtual bool excluir(const Identificador& identificador) = 0;

        /**
         * @brief Lista os identificadores dos quadros cadastrados
         * @retval true Listagem realizada com sucesso
         * @retval false Falha na listagem
         */
        virtual bool listar() = 0;
};

/**
 * @brief Interface da apresentação de quadros
 *
 * Especifica o serviço de interação com o usuário para quadros
 */
class IUQuadros {
    public:
        virtual ~IUQuadros() = default;

        /**
         * @brief Executa a interação com o usuário para quadros
         * @retval true Interação concluída com sucesso
         * @retval false Falha durante a interação
         */
        virtual bool executar() = 0;

        /**
         * @brief Define a controladora de serviços de quadro
         * @param cntr Ponteiro para a controladora que realiza IServicosQuadros
         */
        virtual void setCntrServicosQuadros(IServicosQuadros* cntr) = 0;
};

/**
 * @brief Interface dos serviços de cartão de atividade
 *
 * Especifica os serviços de cartão de atividade providos pela camada de serviço e usados pela camada de apresentação, incluindo a movimentação entre colunas e as métricas
 */
class IServicosCartaoDeAtividade {
    public:
        virtual ~IServicosCartaoDeAtividade() = default;

        /**
         * @brief Cria um cartão de atividade
         * @param cartao Cartão a ser criado
         * @retval true Cartão criado com sucesso
         * @retval false Cartão já existe ou dados inconsistentes
         */
        virtual bool criar(const CartaoDeAtividade& cartao) = 0;

        /**
         * @brief Lê os dados de um cartão de atividade
         * @param cartao Ponteiro para o cartão, que entra com o identificador e sai com os dados preenchidos
         * @retval true Cartão encontrado
         * @retval false Cartão não encontrado
         */
        virtual bool ler(CartaoDeAtividade* cartao) = 0;

        /**
         * @brief Atualiza os dados de um cartão de atividade
         * @param cartao Cartão com o identificador do cartão existente e os novos dados
         * @retval true Cartão atualizado com sucesso
         * @retval false Cartão não encontrado ou dados inconsistentes
         */
        virtual bool atualizar(const CartaoDeAtividade& cartao) = 0;

        /**
         * @brief Exclui um cartão de atividade
         * @param identificador Identificador do cartão a ser excluído
         * @retval true Cartão excluído com sucesso
         * @retval false Cartão não encontrado
         */
        virtual bool excluir(const Identificador& identificador) = 0;

        /**
         * @brief Lista os identificadores dos cartões cadastrados
         * @retval true Listagem realizada com sucesso
         * @retval false Falha na listagem
         */
        virtual bool listar() = 0;

        /**
         * @brief Move um cartão para outra coluna do quadro
         *
         * As movimentações possíveis são A FAZER para FAZENDO e FAZENDO para FEITO
         *
         * @param identificador Identificador do cartão a ser movido
         * @param estado Estado de destino
         * @retval true Cartão movido com sucesso
         * @retval false Cartão não encontrado, movimentação inválida ou limite de WIP excedido
         */
        virtual bool mover(const Identificador& identificador, const Estado& estado) = 0;

        /**
         * @brief Lê o tempo de ciclo de um cartão
         *
         * Tempo entre a entrada do cartão na coluna FAZENDO e a chegada à coluna FEITO
         *
         * @param[in] identificadorCartao Identificador do cartão
         * @param[out] tempo Tempo de ciclo do cartão
         * @retval true Leitura realizada com sucesso
         * @retval false Cartão não encontrado ou ainda não concluído
         */
        virtual bool lerTempoCiclo(const Identificador& identificadorCartao, double& tempo) = 0;

        /**
         * @brief Lê o tempo de ciclo médio dos cartões de um quadro
         * @param[in] identificadorQuadro Identificador do quadro
         * @param[out] tempoMedio Média dos tempos de ciclo das atividades do quadro
         * @retval true Leitura realizada com sucesso
         * @retval false Quadro não encontrado ou sem cartões concluídos
         */
        virtual bool lerTempoCicloMedio(const Identificador& identificadorQuadro, double& tempoMedio) = 0;

        /**
         * @brief Lê o lead time de um cartão
         *
         * Tempo entre a entrada do cartão na coluna A FAZER e a chegada à coluna FEITO
         *
         * @param[in] identificadorCartao Identificador do cartão
         * @param[out] tempo Lead time do cartão
         * @retval true Leitura realizada com sucesso
         * @retval false Cartão não encontrado ou ainda não concluído
         */
        virtual bool lerLeadTime(const Identificador& identificadorCartao, double& tempo) = 0;

        /**
         * @brief Lê o lead time médio dos cartões de um quadro
         * @param[in] identificadorQuadro Identificador do quadro
         * @param[out] tempoMedio Média dos lead times das atividades do quadro
         * @retval true Leitura realizada com sucesso
         * @retval false Quadro não encontrado ou sem cartões concluídos
         */
        virtual bool lerLeadTimeMedio(const Identificador& identificadorQuadro, double& tempoMedio) = 0;

        /**
         * @brief Lê o work in progress (WIP) de um quadro
         * @param[in] identificadorQuadro Identificador do quadro
         * @param[out] wip Número de cartões na coluna FAZENDO
         * @retval true Leitura realizada com sucesso
         * @retval false Quadro não encontrado
         */
        virtual bool lerWip(const Identificador& identificadorQuadro, int& wip) = 0;
};

/**
 * @brief Interface da apresentação de cartões de atividade
 *
 * Especifica o serviço de interação com o usuário para cartões de atividade
 */
class UICartaoDeAtividade {
    public:
        virtual ~UICartaoDeAtividade() = default;

        /**
         * @brief Executa a interação com o usuário para cartões de atividade
         * @retval true Interação concluída com sucesso
         * @retval false Falha durante a interação
         */
        virtual bool executar() = 0;

        /**
         * @brief Define a controladora de serviços de cartão de atividade
         * @param cntr Ponteiro para a controladora que realiza IServicosCartaoDeAtividade
         */
        virtual void setCntrCartaoDeAtividade(IServicosCartaoDeAtividade* cntr) = 0;
};
/**
 * @brief Interface dos serviços de projeto
 *
 * Especifica os serviços de projeto providos pela camada de serviço e usados pela camada de apresentação
 */
class IServicosProjetos {
    public:
        virtual ~IServicosProjetos() = default;

        /**
         * @brief Cria um projeto
         * @param projeto Projeto a ser criado
         * @retval true Projeto criado com sucesso
         * @retval false Projeto já existe ou dados inconsistentes
         */
        virtual bool criar(const Projeto& projeto) = 0;

        /**
         * @brief Lê os dados de um projeto
         * @param projeto Ponteiro para o projeto, que entra com o identificador e sai com os dados preenchidos
         * @retval true Projeto encontrado
         * @retval false Projeto não encontrado
         */
        virtual bool ler(Projeto* projeto) = 0;

        /**
         * @brief Atualiza os dados de um projeto
         * @param projeto Projeto com o identificador do projeto existente e os novos dados
         * @retval true Projeto atualizado com sucesso
         * @retval false Projeto não encontrado ou dados inconsistentes
         */
        virtual bool atualizar(const Projeto& projeto) = 0;

        /**
         * @brief Exclui um projeto
         * @param identificador Identificador do projeto a ser excluído
         * @retval true Projeto excluído com sucesso
         * @retval false Projeto não encontrado
         */
        virtual bool excluir(const Identificador& identificador) = 0;

        /**
         * @brief Lista os identificadores dos projetos cadastrados
         * @retval true Listagem realizada com sucesso
         * @retval false Falha na listagem
         */
        virtual bool listar() = 0;
};

/**
 * @brief Interface da apresentação de projetos
 *
 * Especifica o serviço de interação com o usuário para projetos
 */
class IUProjetos {
    public:
        virtual ~IUProjetos() = default;

        /**
         * @brief Executa a interação com o usuário para projetos
         * @retval true Interação concluída com sucesso
         * @retval false Falha durante a interação
         */
        virtual bool executar() = 0;

        /**
         * @brief Define a controladora de serviços de projeto
         * @param cntr Ponteiro para a controladora que realiza IServicosProjetos
         */
        virtual void setCntrServicosProjetos(IServicosProjetos* cntr) = 0;
};

#endif // KANBAN_INTERFACES_H