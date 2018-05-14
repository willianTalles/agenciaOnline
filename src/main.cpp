#include <iostream>
#include <memory>

#include "contaCorrente.h"
#include "movimentacao.h"
#include "agenciaOnline.h"

using namespace std;

int main(int argc, char const *argv[]){

    AgenciaOnline * agencia = new AgenciaOnline();

    agencia->run();

    // shared_ptr<ContaCorrente> contaCorrente = make_shared<ContaCorrente >( "Willian Talles", "00001-9", "868631-9", 490, "Nao e especial", 490);
    // cout << *contaCorrente << endl;
    // shared_ptr<Movimentacao> movimentacao = make_shared<Movimentacao>("Transicao", 50, "credito");
    // contaCorrente->setMovimentacao(movimentacao);
    // cout << *contaCorrente << endl;
    return 0;
}
