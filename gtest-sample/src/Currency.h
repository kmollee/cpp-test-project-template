#include <string>
#include <ostream>

class Money {
    public:
        Money(const std::string &currency, int amount);
        virtual ~Money();

        Money times(int) const;
        int getAmount();

        bool operator==(const Money &another) const;
        bool operator!=(const Money &another) const;

        Money &operator+=(const Money &rhs);

        // friends defined inside class body are inline and are hidden from non-ADL lookup
        friend Money operator+(
                Money lhs, // passing lhs by value helps optimize chained a+b+c
                const Money &
                        rhs) // otherwise, both parameters may be const references
        {
                lhs += rhs; // reuse compound assignment
                return lhs; // return the result by value (uses move constructor)
        }

        std::string currency() const;

        friend std::ostream &operator<<(std::ostream &os, const Money &money)
        {
                os << money.m_amount << " " << money.m_currency;
                return os;
        }

    private:
        int m_amount;
        std::string m_currency;
};

class MoneyFactory {
    public:
        static Money getMoney(const std::string &current, int amount);
        static Money Dollar(int amount);
        static Money Franc(int amount);
};
