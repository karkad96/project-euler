#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

class bigint
{
private:
	std::vector<int> num;
    static const int base = 1000000000;
    bool positive;
    int zeros;

public:
    bigint();
    bigint(long long int);
    bigint(std::string);
    bigint(const bigint& b);

    //bigint& operator=(const bigint&);

    bigint operator+(bigint const&) const;
    bigint& operator+=(bigint const&);
    bigint operator+(long long int const&) const;
    bigint& operator+=(long long int);

    bigint operator-(bigint const&) const;
    bigint& operator-=(bigint const&);

    bigint operator*(bigint const&);
    bigint& operator*=(bigint const&);
    bigint operator*(long long const&);
    bigint& operator*=(long long int const&);

    bool operator<(const bigint&) const;
    bool operator>(const bigint&) const;
    bool operator<=(const bigint&) const;
    bool operator>=(const bigint&) const;
    bool operator==(const bigint&) const;
    bool operator!=(const bigint&) const;
    
    int operator[](int const&);

    friend std::ostream& operator<<(std::ostream&, bigint const&);
    friend std::istream& operator>>(std::istream&, bigint&);

private:
    int compare(bigint const&) const;
    std::string to_string(bigint const&);
};

