/** 
 * @file    contaCorrent.cpp
 * @brief   Implementacao da classe resposável por representar uma conta Corrent bancaria
 * @author  Willian Talles M. Dantas 
 * @since   12/05/2018 
 * @date    13/05/2018  
 */
#include "contaCorrente.h"

using namespace std;
/**@brief Construtor paramentrizado */
ContaCorrente::ContaCorrente(
    string nome,
    string agencia, 
    string numero, 
    double saldo, 
    string status, 
    double limite ):
        nome( nome ),
        agencia( agencia ),
        numero( numero ),
        saldo( saldo ),
        status( status ),
        limite( limite ) {}
/**@brief destrutor */
ContaCorrente::~ContaCorrente() {}

/**@brief metodo setter do atributo nome */
void ContaCorrente::setNome( string nome ){
    this->nome = nome;
}
/**@brief metodo setter do atributo agencia */
void ContaCorrente::setAgencia( string agencia ){
    this->agencia = agencia;
}
/**@brief metodo setter do atributo numero */
void ContaCorrente::setNumero( string numero ){
    this->numero = numero;
}
/**@brief metodo setter do atributo saldo */
void ContaCorrente::setSaldo( double saldo ){
    this->saldo = saldo;
}
/**@brief metodo setter do atributo status */
void ContaCorrente::setStatus( string status ){
    this->status = status;
}
/**@brief metodo setter do atributo limite */
void ContaCorrente::setLimite( double limite ){
    this->limite = limite;
}
/**@brief metodo setter do atributo vetor movimentao */
void ContaCorrente::setMovimentacao( shared_ptr< Movimentacao > movimentacao ){
    this->movimentacao.push_back(movimentacao);
}
/**@brief metodo getter do atributo nome */
string  ContaCorrente::getNome(){
    return this->nome;
}
/**@brief metodo getter do atributo agencia */
string  ContaCorrente::getAgencia(){
    return this->agencia;
}
 /**@brief metodo getter do atributo numero */
string  ContaCorrente::getNumero(){
    return this->numero;
}
/**@brief metodo getter do atributo saldo */
double  ContaCorrente::getSaldo(){
    return this->saldo;
}
/**@brief metodo getter do atributo status */
string  ContaCorrente::getStatus(){
    return this->status;
}
/**@brief metodo getter do atributo limite */
double  ContaCorrente::getLimite(){
    return this->limite;
}
/**@brief metodo que imprimi os movimentos da conta */
void ContaCorrente::printMovimentacao(){
    cout << "_____________________________________" << endl
        <<  "EXTRATO" << endl 
        << "_____________________________________" << endl;
    if(!this->movimentacao.empty()){
        for(auto i = this->movimentacao.begin(); i != this->movimentacao.end(); i++ ){
            cout << (**i) << endl;
        }
    }else{
        cout << "Nao houve movimentacoes nessa conta!"<<endl;
    }

    cout <<"Seu saldo e de " << this->saldo << " reais" << endl;
}
/**@brief sobrecarga do operador <<  */
ostream& operator<< ( ostream &o, ContaCorrente &cc ) {
    o << "_____________________________________" << endl
        <<  "DADOS DA POOPYCONTA" << endl 
        << "_____________________________________" << endl;
    o   << "Nome:               " << cc.getNome() << endl
        << "Agencia:            " << cc.getAgencia() << endl
        << "Numero da conta:    " << cc.getNumero() << endl
        << "Saldo:              " << cc.getSaldo() << endl
        << "Status:             " << cc.getStatus() << endl
        << "Limite:             " << cc.getLimite() << endl;
    return o;
}