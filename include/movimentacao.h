/** 
 * @file    movimentacao.h
 * @brief   classe resposável por representar uma movimentacao bancaria
 * @author  Willian Talles M. Dantas 
 * @since   12/005/2018 
 * @date    13/005/2018  
 */

#ifndef _MOVIMENTACAO_H_
#define _MOVIMENTACAO_H_

#include <iostream>
#include <string>

using std::string;
/**@class classe resposável por representar uma movimentacao bancaria  */
class Movimentacao{
    private:
        /**@var define a descrição do movimento  */
        string descricao;
        /**@var define o valor do movimento  */
        double valor;
        /**@var define o tipo do movimento  */
        string tipo;

    public:
        /**@brief Construtor default  */
        Movimentacao();
        /**@brief Construtor paramentrizado */
        Movimentacao( string descricao, double valor, string tipo );
        /**@brief destrutor */
        ~Movimentacao();

        /**@brief metodo setter do atributo descricao */
        void setDescricao( string descricao );
        /**@brief metodo setter do atributo valor */
        void setValor( double valor );
        /**@brief metodo setter do atributo tipo */
        void setTipo( string tipo );

        /**@brief metodo getter do atributo descricao */
        string getDescricao();
        /**@brief metodo getter do atributo valor */
        double getValor();
        /**@brief metodo getter do atributo tipo */
        string getTipo();

        /**@brief sobrecarga do operador <<  */
        friend std::ostream& operator<< (std::ostream &o, Movimentacao &m);
};
#endif