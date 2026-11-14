/**
 * @file entidades.h
 * @brief Declaração das classes de entidade do sistema Kanban
 *
 * @author Nome do autor (matrícula 000000)
 */

#ifndef KANBAN_ENTIDADES_H
#define KANBAN_ENTIDADES_H

#include "dominios.h"

/**
 * @brief Entidade Projeto
 *
 * Representa um projeto
 *
 * Atributos: identificador, nome, descricao, inicio, termino
 *
 * Métodos: setIdentificador e getIdentificador; setNome e getNome; setDescricao e getDescricao; setInicio e getInicio; setTermino e getTermino
 */
class Projeto {
    private:
        Identificador identificador;
        Nome nome;
        Texto descricao;
        Timestamp inicio;
        Timestamp termino;
    public:
        /**
         * @brief Define o identificador do projeto
         * @param identificador Identificador do projeto
         */
        void setIdentificador(const Identificador& identificador);

        /**
         * @brief Obtém o identificador do projeto
         * @return Identificador do projeto
         */
        Identificador getIdentificador() const;

        /**
         * @brief Define o nome do projeto
         * @param nome Nome do projeto
         */
        void setNome(const Nome& nome);

        /**
         * @brief Obtém o nome do projeto
         * @return Nome do projeto
         */
        Nome getNome() const;

        /**
         * @brief Define a descrição do projeto
         * @param descricao Texto com a descrição do projeto
         */
        void setDescricao(const Texto& descricao);

        /**
         * @brief Obtém a descrição do projeto
         * @return Texto com a descrição do projeto
         */
        Texto getDescricao() const;

        /**
         * @brief Define a data e o horário de início do projeto
         * @param inicio Timestamp de início
         */
        void setInicio(const Timestamp& inicio);

        /**
         * @brief Obtém a data e o horário de início do projeto
         * @return Timestamp de início
         */
        Timestamp getInicio() const;

        /**
         * @brief Define a data e o horário de término do projeto
         * @param termino Timestamp de término
         */
        void setTermino(const Timestamp& termino);

        /**
         * @brief Obtém a data e o horário de término do projeto
         * @return Timestamp de término
         */
        Timestamp getTermino() const;
};

/**
 * @brief Entidade Quadro
 *
 * Representa um quadro Kanban, composto pelas colunas A FAZER, FAZENDO e FEITO
 *
 * Atributos: identificador; nome; limite
 *
 * Métodos: setIdentificador e getIdentificador; setNome e getNome; setLimite e getLimite
 */
class Quadro {
    private:
        Identificador identificador;
        Nome nome;
        Limite limite;
    public:
        /**
         * @brief Define o identificador do quadro (chave primária)
         * @param identificador Identificador do quadro
         */
        void setIdentificador(const Identificador& identificador);

        /**
         * @brief Obtém o identificador do quadro
         * @return Identificador do quadro
         */
        Identificador getIdentificador() const;

        /**
         * @brief Define o nome do quadro
         * @param nome Nome do quadro
         */
        void setNome(const Nome& nome);

        /**
         * @brief Obtém o nome do quadro
         * @return Nome do quadro
         */
        Nome getNome() const;

        /**
         * @brief Define o limite de work in progress do quadro
         * @param limite Máximo de cartões simultâneos na coluna FAZENDO
         */
        void setLimite(const Limite& limite);

        /**
         * @brief Obtém o limite de work in progress do quadro
         * @return Máximo de cartões simultâneos na coluna FAZENDO
         */
        Limite getLimite() const;
};

/**
 * @brief Entidade Cartão de Atividade
 *
 * Representa uma atividade registrada em um quadro. Os campos entrada, início e término servem de base para o cálculo de lead time e de tempo de ciclo
 *
 * Atributos: identificador; nome; descricao; prioridade; estado; tamanho; entrada; inicio; termino
 *
 * Métodos: setIdentificador e getIdentificador; setNome e getNome; setDescricao e getDescricao; setPrioridade e getPrioridade; setEstado e getEstado; setTamanho e getTamanho; setEntrada e getEntrada; setInicio e getInicio; setTermino e getTermino
 */
class CartaoDeAtividade {
    private:
        Identificador identificador;
        Nome nome;
        Texto descricao;
        Prioridade prioridade;
        Estado estado;
        Tamanho tamanho;
        Timestamp entrada;
        Timestamp inicio;
        Timestamp termino;
    public:
        /**
         * @brief Define o identificador do cartão
         * @param identificador Identificador do cartão
         */
        void setIdentificador(const Identificador& identificador);

        /**
         * @brief Obtém o identificador do cartão
         * @return Identificador do cartão
         */
        Identificador getIdentificador() const;

        /**
         * @brief Define o nome do cartão
         * @param nome Nome do cartão
         */
        void setNome(const Nome& nome);

        /**
         * @brief Obtém o nome do cartão
         * @return Nome do cartão
         */
        Nome getNome() const;

        /**
         * @brief Define a descrição do cartão
         * @param descricao Texto com a descrição da atividade
         */
        void setDescricao(const Texto& descricao);

        /**
         * @brief Obtém a descrição do cartão
         * @return Texto com a descrição da atividade
         */
        Texto getDescricao() const;

        /**
         * @brief Define a prioridade do cartão
         * @param prioridade Prioridade da atividade (ALTA, MEDIA ou BAIXA)
         */
        void setPrioridade(const Prioridade& prioridade);

        /**
         * @brief Obtém a prioridade do cartão
         * @return Prioridade da atividade
         */
        Prioridade getPrioridade() const;

        /**
         * @brief Define o estado do cartão
         * @param estado Estado da atividade (A FAZER, FAZENDO ou FEITO)
         */
        void setEstado(const Estado& estado);

        /**
         * @brief Obtém o estado do cartão
         * @return Estado da atividade
         */
        Estado getEstado() const;

        /**
         * @brief Define o tamanho do cartão
         * @param tamanho Tamanho da atividade (GRANDE, MEDIO ou PEQUENO)
         */
        void setTamanho(const Tamanho& tamanho);

        /**
         * @brief Obtém o tamanho do cartão
         * @return Tamanho da atividade
         */
        Tamanho getTamanho() const;

        /**
         * @brief Define o momento em que o cartão entrou na coluna A FAZER
         * @param entrada Timestamp de entrada
         */
        void setEntrada(const Timestamp& entrada);

        /**
         * @brief Obtém o momento em que o cartão entrou na coluna A FAZER
         * @return Timestamp de entrada
         */
        Timestamp getEntrada() const;

        /**
         * @brief Define o momento em que o cartão entrou na coluna FAZENDO
         * @param inicio Timestamp de início do trabalho
         */
        void setInicio(const Timestamp& inicio);

        /**
         * @brief Obtém o momento em que o cartão entrou na coluna FAZENDO
         * @return Timestamp de início do trabalho
         */
        Timestamp getInicio() const;

        /**
         * @brief Define o momento em que o cartão chegou à coluna FEITO
         * @param termino Timestamp de conclusão
         */
        void setTermino(const Timestamp& termino);

        /**
         * @brief Obtém o momento em que o cartão chegou à coluna FEITO
         * @return Timestamp de conclusão
         */
        Timestamp getTermino() const;
};

#endif // KANBAN_ENTIDADES_H