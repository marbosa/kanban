#include <iostream>
#include <string>
#include "dominios.h"
#include "entidades.h"
#include "servico_pessoa.h"
#include "apresentacao_pessoa.h"

using namespace std;

int main() {
    CntrServicoPessoa servicoPessoa;
    CntrApresentacaoPessoa apPessoa;
    CntrApresentacaoAutenticacao apAutenticacao;
    apPessoa.setCntrServico(&servicoPessoa);
    apAutenticacao.setCntrServico(&servicoPessoa);

    while (true) {
        cout << "\n=== KANBAN ===\n1 Criar conta\n2 Entrar\n0 Sair\nOpcao: ";
        string op;
        getline(cin, op);
        if (op == "1") {
            apPessoa.cadastrar();
        } else if (op == "2") {
            Email e;
            Papel p;
            if (apAutenticacao.autenticar(&e, &p)) {
                cout << "Autenticado como " << p.getValor() << "." << endl;
                apPessoa.executar(e);
            }
        } else if (op == "0") {
            break;
        }
    }
    return 0;
}
