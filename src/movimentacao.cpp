/** 
 * @file    movimentacao.cpp
 * @brief   Implementação da classe resposável por representar uma movimentacao bancaria
 * @author  Willian Talles M. Dantas 
 * @since   12/005/2018 
 * @date    13/005/2018  
 */
#include "movimentacao.h"

using namespace std;
/**@brief Construtor default  */
Movimentacao::Movimentacao(){}
/**@brief Construtor paramentrizado */
Movimentacao::Movimentacao( 
    string descricao, 
    double valor, 
    string tipo ): 
    descricao( descricao ),
    valor( valor ),
    tipo( tipo ) {}
/**@brief destrutor */
Movimentacao::~Movimentacao(){}
/**@brief metodo setter do atributo descricao */
void Movimentacao::setDescricao( string descricao ){
    this->descricao = descricao;
}
/**@brief metodo setter do atributo valor */
void Movimentacao::setValor( double valor ){
    this->valor = valor;
}
/**@brief metodo setter do atributo tipo */
void Movimentacao::setTipo( string tipo ){
    this->tipo = tipo;
}
/**@brief metodo getter do atributo descricao */
string Movimentacao::getDescricao(){
    return this->descricao;
}
/**@brief metodo getter do atributo valor */
double Movimentacao::getValor(){
    return this->valor;
}
/**@brief metodo getter do atributo tipo */
string Movimentacao::getTipo(){
    return this->tipo;
}
/**@brief sobrecarga do operador <<  */
ostream& operator<< ( ostream &o, Movimentacao &m ) {
    o   << "Descricao:  " << m.getDescricao() << endl
        << "Valor:      " << m.getValor() << endl 
        << "Tipo:       " << m.getTipo() << endl;
    
    return o;
}