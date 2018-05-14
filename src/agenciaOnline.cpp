/** 
 * @file    agenciaOnline.h
 * @brief   Classe resposável por realizar todas operações de uma agencia online.
 * @author  Willian Talles M. Dantas 
 * @since   12/05/2018 
 * @date    13/05/2018  
 */
#include "agenciaOnline.h"

using namespace std;
/**@brief Construtor default  */
AgenciaOnline::AgenciaOnline():rd(), gen(rd()), dis(00000, 999999){}
/**@brief destrutor */
AgenciaOnline::~AgenciaOnline(){}
/** @fn void criarConta()
    @brief cria uma conta corrente
    Cria uma conta corrente com o nome e saldo informado pelo usuário
    e gera automaticamente o numero da conta. a agencia é sempre defina com o
    valor 00001-97.
**/
void AgenciaOnline::criarConta(){
    /**@var para define um nome, numero de conta, status sempre não especial */
    string nome, numeroConta, status = "Nao e especial";
    /**@var para define um saldo   */
    double saldo;
    /**@var para define um valor aleatório   */
    stringstream numero;

    numero << round(dis(gen));
    numero >> numeroConta;
    numeroConta += "-97";
    
    cin.ignore();

    cout << "_____________________________________" << endl
        <<  "ABERTURA DA POOPYCONTA" << endl 
        << "_____________________________________" << endl;

    cout << "Digite seu nome: ";
    getline(cin, nome); ///< recebe do usuário o seu nome

    cout << "digite seu saldo inicial (sim, aqui voce pode!): ";
    cin >> saldo; ///< recebe do usuário o seu saldo inicial

    contaCorrente.push_back( make_shared<ContaCorrente >( nome , "00001-97", numeroConta, saldo, status, saldo ) ); ///< adiciona aconta no vetor contaCorrente com os dados informado

    int size = contaCorrente.size(); ///< captura a quantidade de contas que banco tem cadastrada.
    cout << *contaCorrente[size-1]; ///< Imprimi os dados da conta que foi criada.

    cout << "_____________________________________" << endl;

}
/** @fn void emissaoSaldo()
    @brief emite o saldo
    Imprimi o saldo do usuário na tela caso ele seja cliente.
**/
void AgenciaOnline::emissaoSaldo(){
    /** @var para define um nome */
    string nome;
    /** @var variável aux para informa se o usuário foi encontrado */
    bool encontrado = false;

    cin.ignore();

    cout << "_____________________________________" << endl
        <<  "SALDO" << endl 
        << "_____________________________________" << endl;

    cout <<  "Digite seu nome: " ;
    getline(cin, nome); ///< recebe o nome do usuário para realizar a operação

    /** @brief for que pecorre todo vetor **/ 
    for(auto i = contaCorrente.begin(); i != contaCorrente.end() ; i++){
        /** @brief if que verifica se o nome está cadastrado **/
        if( (*i)->getNome() == nome ){
            encontrado = true; 
            cout << "Seu saldo atual e de " << (*i)->getSaldo() << " reais" << endl;
        }    
    }

    /** @brief if que verifica se o usuário foi encontrado **/
    if(!encontrado){
        cout << "Usuario nao encontrado" << endl;
    }

    cout << "_____________________________________" << endl;   
}
/** @fn void emissaoExtrato()
    @brief emite as movimentações
    Imprimi as movimentações e o saldo do usuário na tela caso ele seja cliente.
**/
void AgenciaOnline::emissaoExtrato(){
    /** @var para define um nome */
    string nome;
    /** @var variável aux para informa se o usuário foi encontrado */
    bool encontrado = false;

    cin.ignore();

    cout <<  "Digite seu nome: " ;
    getline(cin, nome); ///< recebe o nome do usuário para realizar a operação
    
    /** @brief for que pecorre todo vetor **/ 
    for(auto i = contaCorrente.begin(); i != contaCorrente.end() ; i++){
        /** @brief if que verifica se o nome está cadastrado **/
        if( (*i)->getNome() == nome ){
            encontrado = true;
            (*i)->printMovimentacao();
        }    
    }

    /** @brief if que verifica se o usuário foi encontrado **/
    if(!encontrado){
        cout << "Usuario nao encontrado" << endl;
    }


    cout << "_____________________________________" << endl;
}
/** @fn void saque()
    @brief realiza uma operação de saque
    Subtrai o valor informado no saldo so usuario caso ele sela cliente.
**/
void AgenciaOnline::saque(){
    /** @var para define um nome */
    string nome;
    /** @var variável aux para informa se o usuário foi encontrado */
    bool encontrado = false;
    /** @var variáveis auxiliares */
    double saque, saldo;

    cout << "_____________________________________" << endl
        <<  "SAQUE" << endl 
        << "_____________________________________" << endl;

    cin.ignore();

    cout <<  "Digite seu nome: " ;
    getline(cin, nome); ///< recebe o nome do usuário para realizar a operação
    /** @brief for que pecorre todo vetor **/ 
    for(auto i = contaCorrente.begin(); i != contaCorrente.end() ; i++){
        /** @brief if que verifica se o nome está cadastrado **/
        if( (*i)->getNome() == nome ){
            cout << "Digite o valor que deseja retirar: ";
            cin >> saque; ///< valor a ser retirado pelo usuario.

            /** @brief is para verificar se o cliente tem o valor para ser retirado */
            if( (*i)->getSaldo() >= saque ) {
                encontrado = true;
                saldo = (*i)->getSaldo();
                (*i)->setSaldo( saldo - saque );

                movimentacao = make_shared<Movimentacao>("Saque", saque, "Debito"); ///< ponteio auxiliar recebe a movimentação realizada pelo cliente.

                (*i)->setMovimentacao(movimentacao); ///< adiciona a movimentação na conta corrente do cliente.
                
                cout <<"Saque realizado com sucesso! o dinheiro saira pela entrada USB" << endl;
            }else{
                cout << "Voce achou mesmo que eu deixaria tirar um valor que voce nao tem?" << endl;
            }
        }    
    }

    /** @brief if que verifica se o usuário foi encontrado **/
    if(!encontrado){
        cout << "Usuario nao encontrado" << endl;
    }

    cout << "_____________________________________" << endl;
}
/** @fn void deposito()
    @brief Deposito de valor
    Adiciona o valor informado no saldo do usuario caso ele seja cliente.
**/
void AgenciaOnline::deposito(){
    /** @var para define um nome */
    string nome;
    /** @var variável aux para informa se o usuário foi encontrado */
    bool encontrado = false;
    /** @var variáveis auxiliares */
    double valor, saldo;

    cout << "_____________________________________" << endl
        <<  "DEPOSITO" << endl 
        << "_____________________________________" << endl;

    cin.ignore();

    cout <<  "Digite seu nome: " ;
    getline(cin, nome);///< recebe o nome do usuário para realizar a operação

    /** @brief for que pecorre todo vetor **/ 
    for(auto i = contaCorrente.begin(); i != contaCorrente.end() ; i++){
        /** @brief if que verifica se o nome está cadastrado **/
        if( (*i)->getNome() == nome ){
            encontrado = true;

            cout << "Digite o valor que deseja Depositar: ";
            cin >> valor; ///< valor que o usuário deseja depositar.

            saldo = (*i)->getSaldo();
            (*i)->setSaldo( saldo + valor );

            movimentacao = make_shared<Movimentacao>("Deposito", valor, "Debito");///< ponteio auxiliar recebe a movimentação realizada pelo cliente.

            (*i)->setMovimentacao(movimentacao); ///< adiciona a movimentação na conta corrente do cliente.
            
            cout <<"Deposito realizado com sucesso! Obrigado por confiar no POOPY BANK" << endl;
        }    
    }
    
    /** @brief if que verifica se o usuário foi encontrado **/
    if(!encontrado){
        cout << "Usuario nao encontrado" << endl;
    }

    cout << "_____________________________________" << endl;
}
/** @fn void run()
    @brief realiza a execução da agencia online
    metodo que contem um menu que chamaas as funções escolhidas.
**/
void AgenciaOnline::run(){
    int opcao = 0;

    while(opcao != 97){
        cout    << "_________________POOPY BANK_________________" << endl << endl
                << " MENU " << endl
                << "Digite o numero da opcao que deseja: " << endl
                << "1 - Abrir uma POOPYConta" << endl
                << "2 - ver seu saldo" << endl
                << "3 - ver seu extrato" << endl
                << "4 - tirar a grana" << endl
                << "5 - colocar mais grana" << endl
                << "97 - Sair"<< endl << endl ;
        cin >> opcao;
        cout << "_____________________________________" << endl;
        switch( opcao ){
            case 1:
                criarConta();
                break;
            case 2:
                emissaoSaldo();
                break;
            case 3:
                emissaoExtrato();
                break;
            case 4:
                saque();
                break;
            case 5:
                deposito();
                break;
        }
        
    }

    cout << "********** OBRIGAGO POR PREFERIR O POOPY BANK **********" << endl;
}