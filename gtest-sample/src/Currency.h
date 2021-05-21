#pragma once

#include <string>
#include <ostream>
#include <map>
#include <tuple>

enum class Currency { USD, FRANC };
struct Expr;
class Money;
class Bank;

std::string currencyToStr(Currency currency);
class Money {
    public:
        Money()
        {
        }
        Money(Currency currency, int amount);
        virtual ~Money();

        Money times(int) const;
        int getAmount() const;

        bool operator==(const Money &another) const;
        bool operator!=(const Money &another) const;

        // Money &operator+=(const Money &rhs);

        // // friends defined inside class body are inline and are hidden from non-ADL lookup
        // friend Money operator+(
        //         Money lhs, // passing lhs by value helps optimize chained a+b+c
        //         const Money &
        //                 rhs) // otherwise, both parameters may be const references
        // {
        //         lhs += rhs; // reuse compound assignment
        //         return lhs; // return the result by value (uses move constructor)
        // }

        Currency currency() const;

        friend std::ostream &operator<<(std::ostream &os, const Money &money)
        {
                os << money.m_amount << " " << currencyToStr(money.m_currency);
                return os;
        }

    private:
        int m_amount = 0;
        Currency m_currency = Currency::USD;
};

class MoneyFactory {
    public:
        static Money getMoney(Currency currency, int amount);
        static Money Dollar(int amount);
        static Money Franc(int amount);
};

class Bank {
    public:
        Money reduce(const Expr &, Currency to) const;
        Money reduce(const Money &, Currency to) const;
        void registRate(Currency from, Currency to, float exchage_rate);
        float getRete(Currency from, Currency to) const;

    private:
        std::map<std::tuple<Currency, Currency>, float> m_exchangeMap;
};

struct Expr {
        Expr(const Money &agugent, const Money &addend);
        Expr(const Money &agugent);

        Money agugent;
        Money addend;

        Expr &times(int scale);

        Money reduceTo(const Bank &bank, Currency to) const;
};

Expr operator+(const Money &lhs, const Money &rhs);