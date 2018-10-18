#ifndef RND_H
#define RND_H


class Rnd
{
public:
    static const unsigned long long MULTIPLIER = 762939453125L;
    static const unsigned long long MODULATOR = 0xFFFFFFFFFFL;
    constexpr static const double DIVISOR = 1.0 / 1099511627776.0;
    unsigned long long a;
    Rnd();
    void setSeed(unsigned long long seed);
    int rnd(unsigned long long n);
    double rnd();
};

#endif // RND_H
