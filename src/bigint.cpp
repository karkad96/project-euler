#include "bigint.h"

bigint::bigint()
{
    num.push_back(0);
    positive = true;
    zeros = 0;
}

bigint::bigint(long long int b)
{
    positive = true;
    zeros = 0;

    if (b < 0)
    {
        positive = false;
        b = -b;
    }

    while (b)
    {
        num.push_back((int)b % base);
        b /= base;
    }
}

bigint::bigint(string s)
{
    positive = (s[0] == '-') ? false : true;
    zeros = 0;

    if (s[0] == '-')
        s.erase(s.begin());

    int size = s.size();

    for (int i = size - 1; i >= 0; i -= 9)
    {
        int res = 0;
        int ten_power = 1;

        for (int j = i; j > i - 9 and j >= 0; j--)
        {
            res += (s[j] - '0') * ten_power;
            ten_power *= 10;
        }

        num.push_back(res);
    }
}

bigint::bigint(const bigint& b)
    : num(b.num), positive(b.positive), zeros(b.zeros) {}

bigint bigint::operator+(bigint const& b) const
{
    bigint c = *this;
    c += b;

    return c;
}

bigint& bigint::operator+=(bigint const& b)
{
    if (!b.positive)
        return *this -= b;

    while (num.size() < b.num.size())
        num.push_back(0);

    auto i = num.begin();
    auto j = b.num.begin();
    
    int carry = 0;

    while (i != num.end() and j != b.num.end())
    {
        int res = *i + *j;
        *i = (res + carry) % base;
        carry = (res + carry) / base;
        i++;
        j++;
    }

    if (carry)
    {
        while (carry and i != num.end())
        {
            int res = *i;
            *i = (res + carry) % base;
            carry = (res + carry) / base;
            i++;
        }

        if (carry)
            num.push_back(carry);
    }

    return *this;
}

bigint bigint::operator+(long long int const& b) const
{
    bigint c = *this;
    c += b;

    return c;
}

bigint& bigint::operator+=(long long int b)
{
    int carry = 0;
    unsigned int size = (int)ceil((log10(b) + 1) / 9.0);

    while (num.size() < size + zeros)
        num.push_back(0);

    auto i = num.begin() + zeros;

    while (i != num.end() and b)
    {
        int res = *i + (b % base);
        *i = (res + carry) % base;
        carry = (res + carry) / base;
        b /= base;
        i++;
    }

    if (carry)
    {
        while (carry and i != num.end())
        {
            int res = *i;
            *i = (res + carry) % base;
            carry = (res + carry) / base;
            i++;
        }

        if (carry)
            num.push_back(carry);
    }

    while (num[num.size() - 1] == 0)
        num.pop_back();

    return *this;
}

bigint bigint::operator-(bigint const& b) const
{
    bigint c = *this;
    c -= b;


    return c;
}

bigint& bigint::operator-=(bigint const& b)
{
    vector<int> res;

    int carry = 0;

    if (*this == b)
    {
        num.clear();
        num.push_back(0);
        return *this;
    }
    else if (*this > b)
    {
        vector<int>::iterator it = num.begin();
        vector<int>::const_iterator jt = b.num.begin();

        while (jt != b.num.end())
        {
            int sub = *(it)-*(jt)-carry;

            if (sub < 0)
            {
                sub = sub + base;
                carry = 1;
            }
            else
                carry = 0;

            res.push_back(sub);

            it++;
            jt++;
        }

        while (it != num.end())
        {
            if (*it == 0 && carry)
            {
                res.push_back(base - 1);
                it++;
                continue;
            }

            int sub = *it - carry;

            if (it != num.end() - 1 || sub > 0)
                res.push_back(sub);
            carry = 0;

            it++;
        }
    }

    else
    {
        positive = false;

        vector<int>::const_iterator it = b.num.begin();
        vector<int>::iterator jt = num.begin();

        while (jt != num.end())
        {
            int sub = *(it)-*(jt)-carry;

            if (sub < 0)
            {
                sub = sub + base;
                carry = 1;
            }
            else
                carry = 0;

            res.push_back(sub);

            it++;
            jt++;
        }

        while (it != b.num.end())
        {
            if (*it == 0 && carry)
            {
                res.push_back(base - 1);
                it++;
                continue;
            }

            int sub = *it - carry;

            if (it != b.num.end() - 1 || sub > 0)
                res.push_back(sub);
            carry = 0;

            it++;
        }
    }


    num = res;

    while (num[num.size() - 1] == 0)
        num.pop_back();

    return *this;
}

bigint bigint::operator*(bigint const& b)
{
    bigint c;

    for (auto i = num.begin(); i != num.end(); i++)
    {
        for (auto j = b.num.begin(); j != b.num.end(); j++)
        {
            c.zeros = (i - num.begin()) + (j - b.num.begin());
            c += (long long int)(*i) * (*j);
        }
    }

    c.zeros = 0;

    return c;
}

bigint& bigint::operator*=(bigint const& b)
{
    *this = *this * b;

    return *this;
}

bigint bigint::operator*(long long const&)
{

    return *this;
}

bigint& bigint::operator*=(int const&)
{
    return *this;
}

bool bigint::operator<(const bigint& b) const
{
    return compare(b) == -1;
}

bool bigint::operator>(const bigint& b) const
{
    return compare(b) == 1;
}

bool bigint::operator<=(const bigint& b) const
{
    int c = compare(b);

    return c == -1 or c == 0;
}

bool bigint::operator>=(const bigint& b) const
{
    int c = compare(b);

    return c == 1 or c == 0;
}

bool bigint::operator==(const bigint& b) const
{
    return compare(b) == 0;
}

bool bigint::operator!=(const bigint& b) const
{
    return compare(b) != 0;
}

int bigint::operator[](int const& b)
{
    return to_string(*this)[b] - '0';
}

int bigint::compare(bigint const& b) const
{
    if (positive && !b.positive) return 1;
    if (!positive && b.positive) return -1;

    int check = 1;

    if (!positive && !b.positive) check = -1;

    if (num.size() < b.num.size()) return -1 * check;
    if (num.size() > b.num.size()) return check;

    for (int i = num.size() - 1; i >= 0; i--) 
    {
        if (num[i] < b.num[i]) return -1 * check;
        if (num[i] > b.num[i]) return check;
    }

    return 0;
}

string bigint::to_string(bigint const& b)
{
    ostringstream stream;

    stream << b;
    
    return stream.str();
}

ostream& operator<<(ostream& stream, bigint const& b)
{
    int size = b.num.size() - 2;

    if (!b.positive)
        stream << '-' << b.num[b.num.size() - 1];
    else
        stream << b.num[b.num.size() - 1];

    for (int i = size; i >= 0; i--)
    {
        int tmp = b.num[i];

        if (tmp == 0)
            for (int j = 0; j < 9; j++)
                stream << 0;
        else
        {
            while (tmp < b.base / 10)
            {
                tmp *= 10;
                stream << 0;
            }

            stream << b.num[i];
        }
    }

    return stream;
}

istream& operator>>(istream& stream, bigint& b)
{
    string str;
    stream >> str;

    b = str;

    return stream;
}
