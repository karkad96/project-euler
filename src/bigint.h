#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class bigint
{
private:
	vector<int> num;
    static const int base = 1000000000;
    bool positive;
public:
    bigint();
    bigint(long long int);
    bigint(string);
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
    bigint& operator*=(int const&);

    bool operator<(const bigint&) const;
    bool operator>(const bigint&) const;
    bool operator<=(const bigint&) const;
    bool operator>=(const bigint&) const;
    bool operator==(const bigint&) const;
    bool operator!=(const bigint&) const;
    
    friend ostream& operator<<(ostream&, bigint const&);

private:
    int compare(bigint const&) const;
};

