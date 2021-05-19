#include "Currency.h"

Money::Money(const std::string &currency, int amount)
        : m_currency{ currency }, m_amount{ amount }
{
}

Money::~Money()
{
}

Money Money::times(int scale) const
{
        return Money(m_currency, m_amount * scale);
}

int Money::getAmount()
{
        return m_amount;
}

bool Money::operator==(const Money &another) const
{
        return m_currency == another.m_currency && m_amount == another.m_amount;
}

bool Money::operator!=(const Money &another) const
{
        return m_currency != another.m_currency || m_amount != another.m_amount;
}

Money &Money::operator+=(const Money &rhs)
{
        m_amount += rhs.m_amount;
        return *this;
}

std::string Money::currency() const
{
        return m_currency;
}

Money MoneyFactory::getMoney(const std::string &currency, int amount)
{
        return Money(currency, amount);
}

Money MoneyFactory::Dollar(int amount)
{
        return getMoney("USD", amount);
}
Money MoneyFactory::Franc(int amount)
{
        return getMoney("Franc", amount);
}