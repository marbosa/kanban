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

#endif //KANBAN_INTERFACES_H
