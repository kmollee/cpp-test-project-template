#include "Currency.h"

std::string currencyToStr(Currency currency)
{
        switch (currency) {
        case Currency::FRANC:
                return "FRANC";
        case Currency::USD:
                return "USD";

        case Currency::TWD:
                return "TWD";
        default:
                return "DEFAULT";
        }
}

Money::Money(Currency currency, int amount)
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

int Money::getAmount() const
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

// Money &Money::operator+=(const Money &rhs)
// {
//         m_amount += rhs.m_amount;
//         return *this;
// }

Currency Money::currency() const
{
        return m_currency;
}

Money MoneyFactory::getMoney(Currency currency, int amount)
{
        return Money(currency, amount);
}

Money MoneyFactory::Dollar(int amount)
{
        return getMoney(Currency::USD, amount);
}
Money MoneyFactory::Franc(int amount)
{
        return getMoney(Currency::FRANC, amount);
}

Money Bank::reduce(const Expr &expr, Currency to) const
{
        return expr.reduceTo(*this, to);
}

Money Bank::reduce(const Money &money, Currency to) const
{
        return Expr(money).reduceTo(*this, to);
}

void Bank::registRate(Currency from, Currency to, float exchage_rate)
{
        m_exchangeMap[{ from, to }] = exchage_rate;
}

float Bank::getRete(Currency from, Currency to) const
{
        if (from == to) {
                return 1.0;
        }
        return m_exchangeMap.at({ from, to });
}

Expr::Expr(const Money &agugent, const Money &addend)
        : agugent(agugent), addend(addend)
{
}

Expr::Expr(const Money &agugent) : agugent(agugent)
{
}

Expr &Expr::times(int scale)
{
        agugent = agugent.times(scale);
        addend = addend.times(scale);
        return *this;
}

Expr operator+(const Money &lhs, const Money &rhs)
{
        return Expr(lhs, rhs);
}

Money Expr::reduceTo(const Bank &bank, Currency to) const
{
        return Money(to, bank.getRete(agugent.currency(), to) *
                                         agugent.getAmount() +
                                 bank.getRete(addend.currency(), to) *
                                         addend.getAmount());
}