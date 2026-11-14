#ifndef KANBAN_INTERFACES_H
#define KANBAN_INTERFACES_H

#include "dominios.h"
#include "entidades.h"


class IServicosQuadros {
    public:
        virtual ~IServicosQuadros() = default;

        virtual bool criar(const Quadro& quadro ) = 0;
        virtual bool ler(Quadro* quadro) = 0;
        virtual bool atualizar(Quadro& quadro) = 0;
        virtual bool excluir(const Identificador& identificador) = 0;
        virtual bool listar() = 0;
};

class IUQuadros {
    public:
        virtual ~IUQuadros() = default;

        virtual bool executar() = 0;
        virtual void setCntrServicosQuadros(IServicosQuadros* cntr) = 0;
};

class IServicosCartaoDeAtividade {
    public:
        virtual ~IServicosCartaoDeAtividade() = default;

        virtual bool criar(const CartaoDeAtividade& cartao ) = 0;
        virtual bool ler(CartaoDeAtividade* cartao) = 0;
        virtual bool atualizar(const CartaoDeAtividade& cartao) = 0;
        virtual bool excluir(const Identificador& identificador) = 0;
        virtual bool listar() = 0;

        virtual bool mover(const Identificador& identificador, const Estado& estado) = 0;
        virtual bool lerTempoCiclo(const Identificador& identificadorCartao, double& tempo) = 0;
        virtual bool lerTempoCicloMedio(const Identificador& identificadorQuadro, double& tempoMedio) = 0;
        virtual bool lerLeadTime(const Identificador& identificadorCartao, double& tempo) = 0;
        virtual bool lerLeadTimeMedio(const Identificador& identificadorQuadro, double& tempoMedio) = 0;
        virtual bool lerWip(const Identificador& identificadorQuadro, int& wip) = 0;
};

class UICartaoDeAtividade {
    public:
        virtual ~UICartaoDeAtividade() = default;

        virtual bool executar() = 0;
        virtual void setCntrCartaoDeAtividade(IServicosCartaoDeAtividade* cntr) = 0;
};

#endif //KANBAN_INTERFACES_H
