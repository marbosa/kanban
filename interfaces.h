/**
 * @file interfaces.h
 * @brief Declaração das interfaces que fazem a conexão entre as camadas de serviço e de apresentação
 */

#ifndef KANBAN_INTERFACES_H
#define KANBAN_INTERFACES_H

#include "dominios.h"
#include "entidades.h"

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

#endif // KANBAN_INTERFACES_H