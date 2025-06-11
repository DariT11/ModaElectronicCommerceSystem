#include "Client.h"

Cart& Client::getCart() 
{
    return cart;
}

double Client::getWallet() const
{
    return wallet;
}

unsigned Client::getPoints() const
{
    return points;
}

Role Client::getRole() 
{
    return role;
}

MyString Client::getUsername() const
{
    return User::getUsername();
}

void Client::deductFromWallet(double amount)
{
    wallet -= amount;
}

void Client::addToWallet(double amount)
{
    wallet += amount;
}

void Client::deductPoints(unsigned points)
{
    points -= points;
}

void Client::addPoints(unsigned points)
{
    points += points;
}

void Client::executeCommand(Command* command)
{
    command->execute();
}
