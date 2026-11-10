#include "servico_pessoa.h"

// ------------------------------------------------------------
// ContainerPessoa
// ------------------------------------------------------------
bool ContainerPessoa::incluir(const Pessoa& p) {
    return dados.insert(make_pair(p.getEmail().getValor(), p)).second;
}

bool ContainerPessoa::remover(const Email& e) {
    return dados.erase(e.getValor()) > 0;
}

bool ContainerPessoa::pesquisar(Pessoa* p) const {
    auto it = dados.find(p->getEmail().getValor());
    if (it == dados.end()) {
        return false;
    }
    *p = it->second;
    return true;
}

bool ContainerPessoa::atualizar(const Pessoa& p) {
    auto it = dados.find(p.getEmail().getValor());
    if (it == dados.end()) {
        return false;
    }
    it->second = p;
    return true;
}

list<Email> ContainerPessoa::listar() const {
    list<Email> r;
    for (const auto& par : dados) {
        r.push_back(par.second.getEmail());
    }
    return r;
}

// ------------------------------------------------------------
// CntrServicoPessoa
// ------------------------------------------------------------
bool CntrServicoPessoa::podeExcluir(const Email&) const {
    // TODO (integracao): retornar false se a pessoa for gestora de projeto
    // ou desenvolvedora de cartao de atividade existente.
    return true;
}

bool CntrServicoPessoa::criar(const Pessoa& p) {
    return container.incluir(p);
}

bool CntrServicoPessoa::ler(Pessoa* p) {
    return container.pesquisar(p);
}

bool CntrServicoPessoa::atualizar(const Pessoa& p) {
    return container.atualizar(p);
}

bool CntrServicoPessoa::excluir(const Email& e) {
    if (!podeExcluir(e)) {
        return false;
    }
    return container.remover(e);
}

bool CntrServicoPessoa::listar(list<Email>* l) {
    *l = container.listar();
    return true;
}

bool CntrServicoPessoa::autenticar(const Email& e, const Senha& s, Papel* papel) {
    Pessoa p;
    p.setEmail(e);
    if (!container.pesquisar(&p)) {
        return false;
    }
    if (p.getSenha().getValor() != s.getValor()) {
        return false;
    }
    *papel = p.getPapel();
    return true;
}
