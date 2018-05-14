/** 
 * @file    agenciaOnline.h
 * @brief   Classe resposável por realizar todas operações de uma agencia online.
 * @author  Willian Talles M. Dantas 
 * @since   12/05/2018 
 * @date    13/05/2018  
 */
#ifndef _AGENCIAONLINE_H_
#define _AGENCIAONLINE_H_

#include <iostream>
#include <sstream>
#include <string>
#include <memory>
#include <vector>
#include <random>

#include "contaCorrente.h"
#include "movimentacao.h"

/**@class Classe resposável por realizar todas operações de uma agencia online.  */
class AgenciaOnline{
    private:
        /**@var para define um valor aleatório   */
    	std::random_device rd;
        /**@var para define um valor aleatório   */
		std::default_random_engine gen;
        /**@var para define um valor aleatório   */
		std::uniform_int_distribution<> dis;

        /**@var define um conjunto de contas para um banco */
        vector< std::shared_ptr< ContaCorrente > > contaCorrente;
        /**@var variável auxilar para adicionar uma movimentação em uma conta corrente*/
        std::shared_ptr<Movimentacao> movimentacao;
    public:
        /**@brief Construtor default  */
        AgenciaOnline();
        /**@brief destrutor */
        ~AgenciaOnline();

        /** @fn void deposito()
            @brief Deposito de valor
            Adiciona o valor informado no saldo do usuario caso ele seja cliente.
        **/
        void deposito();
        /** @fn void emissaoSaldo()
            @brief emite o saldo
            Imprimi o saldo do usuário na tela caso ele seja cliente.
        **/
        void emissaoSaldo();
        /** @fn void emissaoExtrato()
            @brief emite as movimentações
            Imprimi as movimentações e o saldo do usuário na tela caso ele seja cliente.
        **/
        void emissaoExtrato();
        /** @fn void criarConta()
            @brief cria uma conta corrente
            Cria uma conta corrente com o nome e saldo informado pelo usuário
            e gera automaticamente o numero da conta. a agencia é sempre defina com o
            valor 00001-97.
        **/
        void criarConta();
        /** @fn void saque()
            @brief realiza uma operação de saque
            Subtrai o valor informado no saldo so usuario caso ele sela cliente.
        **/
        void saque();
        /** @fn void run()
            @brief realiza a execução da agencia online
            metodo que contem um menu que chamaas as funções escolhidas.
        **/
        void run();
};

#endif