#ifndef __LIMIT_H__
#define __LIMIT_H__

/**
 * estrutura de dados de um limite
 * ele só possui o final e inicial
 * low and high
 */

class Limit {
private:
    double l;
    double h;
public:
    Limit(double l, double h);
    ~Limit();

    friend std::ostream& operator<<(std::ostream& stream, const Limit& limit);
};

#endif // __LIMIT_H__