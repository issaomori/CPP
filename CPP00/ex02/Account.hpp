// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //


#pragma once
// O once serve para que o compilador não compile o arquivo mais de uma vez. Caso contrário, ele iria compilar o arquivo mais de uma vez e isso iria gerar erros de redefinição de variáveis e funções.
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class Account {
// Classe que representa uma conta bancária.

public:
// Métodos públicos da classe Account. Esses métodos podem ser acessados por qualquer classe.

	typedef Account		t;
	// typedef é uma palavra-chave que serve para criar um atalho(alias) para um tipo de dado. Neste caso, o atalho(alias) é t e o tipo de dado é Account.

	//O que é um método estático?
	//Um método estático é um método que pode ser chamado sem a necessidade de instanciar um objeto da classe. Ou seja, ele pode ser chamado diretamente pela classe. Por exemplo, Account::getNbAccounts(). Neste caso, não preciso instanciar um objeto da classe Account para chamar o método getNbAccounts().
	//Ex: Account account1;
	//	account1.getNbAccounts();
	//Por isso tem de vantagem o fato de não precisar instanciar um objeto da classe para chamar o método. E tem de desvantagem o fato de não poder acessar variáveis de membro da classe, pois não há um objeto da classe instanciado. Por exemplo, não posso acessar a variável de membro _amount, pois não há um objeto da classe instanciado. E se eu tentar acessar, o compilador vai me retornar um erro.
	static int	getNbAccounts( void );
	//método estático que retorna o número de contas.
	static int	getTotalAmount( void );
	//método estático que retorna o total de dinheiro.
	static int	getNbDeposits( void );
	//método estático que retorna o número de depósitos.
	static int	getNbWithdrawals( void );
	//método estático que retorna o número de saques.
	static void	displayAccountsInfos( void );
	//método estático que printa na tela o número de contas, o total de dinheiro, o número de depósitos e o número de saques.

	Account( int initial_deposit );
	//construtor da classe Account que serve para inicializar as variáveis de membro da classe. Neste caso, o construtor recebe um inteiro que será o valor inicial da conta.
	~Account( void );
	//destrutor da classe Account que serve para destruir as variáveis de membro da classe. Neste caso, não há alocação dinâmica de memória e por isso não preciso preencher o destrutor.

	void	makeDeposit( int deposit );
	//método responsável por fazer um depósito na conta.
	bool	makeWithdrawal( int withdrawal );
	//método responsável por fazer um saque na conta.
	int		checkAmount( void ) const;
	//método responsável por verificar o saldo da conta.
	void	displayStatus( void ) const;
	//método responsável por printar na tela o índice da conta, o saldo da conta e o número de depósitos e saques.


private:

	static int	_nbAccounts;
	static int	_totalAmount;
	static int	_totalNbDeposits;
	static int	_totalNbWithdrawals;

	static void	_displayTimestamp( void );
	//método estático responsável por printar na tela o timestamp.

	int				_accountIndex;
	int				_amount;
	int				_nbDeposits;
	int				_nbWithdrawals;

	Account( void );
	//construtor da classe Account que serve para inicializar as variáveis de membro da classe. Neste caso, o construtor não recebe nenhum argumento.
	//Por que tenho dois construtores? Um publico e um privado?
	//Porque o construtor público é responsável por inicializar as variáveis de membro da classe quando eu instanciar um objeto da classe. E o construtor privado é responsável por inicializar as variáveis de membro da classe quando eu chamar o método estático displayAccountsInfos(). Neste caso, o construtor privado é responsável por inicializar as variáveis de membro da classe quando eu chamar o método estático displayAccountsInfos(). Porque o método estático displayAccountsInfos() não pode acessar as variáveis de membro da classe, pois não há um objeto da classe instanciado. E se eu tentar acessar, o compilador vai me retornar um erro.
};



// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */
