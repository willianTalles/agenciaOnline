/** 
 * @file    contaCorrent.h
 * @brief   Classe resposável por representar uma conta Corrent bancaria
 * @author  Willian Talles M. Dantas 
 * @since   12/05/2018 
 * @date    13/05/2018  
 */
#ifndef _CONTACORRENTE_H_
#define _CONTACORRENTE_H_

#include <iostream>
#include <string>
#include <memory>
#include <vector>

#include "movimentacao.h"

using std::string;
using std::vector;
/**@class Classe resposável por representar uma conta Corrent bancaria  */
class ContaCorrente{
    private:
        /**@var define o nome do usuário da conta  */
        string nome;
        /**@var define a agencia da conta  */
        string agencia;
        /**@var define o numero da conta  */
        string numero;
        /**@var define o saldo da conta  */
        double saldo;
        /**@var define o status da conta  */
        string status;
        /**@var define o limite da conta  */
        double limite;
        /**@var define um conjunto de movimentação da conta  */
        vector< std::shared_ptr< Movimentacao > > movimentacao;
    
    public:
        /**@brief Construtor paramentrizado */
        ContaCorrente( string nome, string agencia, string numero, double saldo, string status, double limite );
        /**@brief destrutor */
        ~ContaCorrente();

        /**@brief metodo setter do atributo nome */
        void setNome( string nome );
        /**@brief metodo setter do atributo agencia */
        void setAgencia( string agencia );
        /**@brief metodo setter do atributo numero */
        void setNumero( string numero );
        /**@brief metodo setter do atributo saldo */
        void setSaldo( double saldo );
        /**@brief metodo setter do atributo status */
        void setStatus( string status );
        /**@brief metodo setter do atributo limite */
        void setLimite( double limite );
        /**@brief metodo setter do atributo vetor movimentao */
        void setMovimentacao( std::shared_ptr< Movimentacao > movimentacao );
        
        /**@brief metodo getter do atributo nome */
        string  getNome();
        /**@brief metodo getter do atributo agencia */
        string  getAgencia();
        /**@brief metodo getter do atributo numero */
        string  getNumero();
        /**@brief metodo getter do atributo saldo */
        double  getSaldo();
        /**@brief metodo getter do atributo status */
        string  getStatus();
        /**@brief metodo getter do atributo limite */
        double  getLimite();

        /**@brief metodo que imprimi os movimentos da conta */
        void printMovimentacao();

        /**@brief sobrecarga do operador <<  */
        friend std::ostream& operator<< (std::ostream &o, ContaCorrente &cc);
};
#endif