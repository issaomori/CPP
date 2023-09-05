//Neste exercício, você aprenderá a usar classes e métodos estáticos.

#include "Account.hpp"
#include <iostream>
//biblioteca para usar o std::string, std::cout.
#include <string>
//biblioteca para usar o std::string
#include <ctime>
//biblioteca para usar o std::time_t, std::time, std::strftime, std::localtime

//Por que estou inicializando as variaveis aqui?
//Porque elas são variáveis estáticas e não podem ser inicializadas dentro da classe. Como elas podem ser acessadas por qualquer classe, elas precisam ser inicializadas fora da classe.
int Account::_nbAccounts = 0;
//variável estática que armazena o número de contas.
int Account::_totalAmount = 0;
//variável estática que armazena o total de dinheiro.
int Account::_totalNbDeposits = 0;
//variável estática que armazena o número de depósitos.
int Account::_totalNbWithdrawals = 0;
//variável estática que armazena o número de saques.

Account::Account(){}
//construtor da classe Account que serve para inicializar as variáveis de membro da classe. Neste caso, o construtor não recebe nenhum argumento.
Account::~Account(){
    //destrutor da classe Account que serve para destruir as variáveis de membro da classe.
    _displayTimestamp();
    //chama o método estático _displayTimestamp() para printar na tela o timestamp.
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
    //printa na tela o índice da conta, o saldo da conta e a mensagem "closed".
    _nbAccounts--;
    //decrementa a variável estática _nbAccounts para indicar que uma conta foi fechada.
    _totalAmount -= _amount;
    //decrementa a variável estática _totalAmount para indicar que o saldo da conta foi retirado do total de dinheiro.
}

Account::Account(int initial_deposit) {
    //construtor da classe Account que serve para inicializar as variáveis de membro da classe. Neste caso, o construtor recebe um inteiro que será o valor inicial da conta.
    _accountIndex = _nbAccounts;
    //inicializa a variável de membro _accountIndex com o valor da variável estática _nbAccounts. Neste caso, a variável de membro _accountIndex vai receber o valor 0, pois a variável estática _nbAccounts foi inicializada com o valor 0.
    _amount = initial_deposit;
    //inicializa a variável de membro _amount com o valor do argumento initial_deposit. Neste caso, a variável de membro _amount vai receber o valor do argumento initial_deposit.
    _nbDeposits = 0;
    //inicializa a variável de membro _nbDeposits com o valor 0.
    _nbWithdrawals = 0;
    //inicializa a variável de membro _nbWithdrawals com o valor 0.
    _nbAccounts++;
    //incrementa a variável estática _nbAccounts para indicar que uma conta foi criada.
    _totalAmount += initial_deposit;
    //incrementa a variável estática _totalAmount para indicar que o saldo da conta foi adicionado ao total de dinheiro.
    _displayTimestamp();
    //chama o método estático _displayTimestamp() para printar na tela o timestamp.
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
    //printa na tela o índice da conta, o saldo da conta e a mensagem "created".
}

int Account::getNbAccounts( void ) {
    //método estático que retorna o número de contas.
    return _nbAccounts;
    //retorna o valor da variável estática _nbAccounts.
}

int Account::getTotalAmount( void ) {
    //método estático que retorna o total de dinheiro.
    return _totalAmount;
    //retorna o valor da variável estática _totalAmount.
}

int Account::getNbDeposits( void ) {
    //método estático que retorna o número de depósitos.
    return _totalNbDeposits;
    //retorna o valor da variável estática _totalNbDeposits.
}

int Account::getNbWithdrawals( void ) {
    //método estático que retorna o número de saques.
    return _totalNbWithdrawals;
    //retorna o valor da variável estática _totalNbWithdrawals.
}

void Account::displayAccountsInfos( void ) {
    //método estático que printa na tela o número de contas, o total de dinheiro, o número de depósitos e o número de saques.
    Account::_displayTimestamp();
    //chama o método estático _displayTimestamp() para printar na tela o timestamp.
    std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
    //printa na tela o número de contas, o total de dinheiro, o número de depósitos e o número de saques.
}

void Account::makeDeposit( int deposit ){
    //método responsável por fazer um depósito na conta.
    Account::_displayTimestamp();
    //chama o método estático _displayTimestamp() para printar na tela o timestamp.
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit << ";amount:" << _amount + deposit << ";nb_deposits:" << _nbDeposits + 1 << std::endl;
    //printa na tela o índice da conta, o saldo da conta, o valor do depósito, o novo saldo da conta e o número de depósitos.
    _amount += deposit;
    //incrementa a variável de membro _amount com o valor do argumento deposit.
    _nbDeposits++;
    //incrementa a variável de membro _nbDeposits para indicar que um depósito foi feito.
    _totalAmount += deposit;
    //incrementa a variável estática _totalAmount para indicar que o saldo da conta foi adicionado ao total de dinheiro.
    _totalNbDeposits++;
    //incrementa a variável estática _totalNbDeposits para indicar que um depósito foi feito.
}

bool	Account::makeWithdrawal( int withdrawal ){
    //método responsável por fazer um saque na conta. Se retornar true, o saque foi feito. Se retornar false, o saque não foi feito.
    Account::_displayTimestamp();
    //chama o método estático _displayTimestamp() para printar na tela o timestamp.
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
    //printa na tela o índice da conta e o saldo da conta.
    if (_amount - withdrawal < 0) {
        //verifica se o saldo da conta menos o valor do saque é menor que 0.
        std::cout << "refused" << std::endl;
        //printa na tela a mensagem "refused".
        return false;
        //retorna false para indicar que o saque não foi feito.
    }
    std::cout << withdrawal << ";amount:" << _amount - withdrawal << ";nb_withdrawals:" << _nbWithdrawals + 1 << std::endl;
    //printa na tela o valor do saque, o novo saldo da conta e o número de saques.
    _amount -= withdrawal;
    //decrementa a variável de membro _amount com o valor do argumento withdrawal porque o saque foi feito.
    _nbWithdrawals++;
    //incrementa a variável de membro _nbWithdrawals para indicar que um saque foi feito.
    _totalAmount -= withdrawal;
    //decrementa a variável estática _totalAmount para indicar que o saldo da conta foi retirado do total de dinheiro.
    _totalNbWithdrawals++;
    //incrementa a variável estática _totalNbWithdrawals para indicar que um saque foi feito.
    return true;
    //retorna true para indicar que o saque foi feito.
}
    
int		Account::checkAmount( void ) const{
    //método responsável por verificar o saldo da conta.
    return _amount;
    //retorna o valor da variável de membro _amount para indicar o saldo da conta.
}

void	Account::displayStatus( void ) const{
    //método responsável por printar na tela o índice da conta, o saldo da conta e o número de depósitos e saques.
    Account::_displayTimestamp();
    //chama o método estático _displayTimestamp() para printar na tela o timestamp.
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
    //printa na tela o índice da conta, o saldo da conta e o número de depósitos e saques.
}

void    Account::_displayTimestamp(void) {
    //método estático responsável por printar na tela o timestamp.
    
    const std::time_t    time = std::time(NULL);
    //variável estática que armazena o timestamp porque o timestamp não muda.
    const std::string    format = "%Y%m%d_%H%M%S";
    //variável estática que armazena o formato do timestamp.
    char timestamp[16];
    //variável estática que armazena o timestamp.
    
    std::strftime(timestamp, 16, format.c_str(), std::localtime(&time));
    //pega o timestamp e armazena na variável timestamp.
    std::cout << "[" << timestamp << "] ";
    //printa na tela o timestamp.
}
