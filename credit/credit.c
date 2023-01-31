#include <cs50.h>
#include <stdio.h>

long get_creditcard(void);
int imprimir(int l, int pref);
int get_algo(long card);
int type_card(int i, long c);

int main(void)
{
    long card = get_creditcard();
    int len = get_algo(card);
    int pref = type_card(len, card);
    imprimir(len, pref);
}

long get_creditcard(void)
{
    long card;
    card = get_long("Number: ");
card)
    return card;
}
int get_algo(long card)
{
    int m;
    int m1 = 0 ;
    int m2 = 0 ;
    int i = 0;
    while (card > 0)
    {
        m = card % 10;
        card = card / 10;
        i++;
        if (i % 2 == 0)
        {
            m = m * 2;
            if (m > 9)
            {
                m = (m % 10) + (m / 10) ;
            }
            m2 = m2 + m;
        }
        else
        {
            m1 = m1 + m ;
        }
    }
    m = m1 + m2;
    if (m % 10 == 0)
    {
        return i;
    }
    else
    {
        return 0;
    }
}
int type_card(int i, long c)
{
    while (i > 2)
    {
        c = c / 10;
        i--;
    }
    return c;
}
int imprimir(int l, int pref)
{
    if ((l == 13 || l == 16) && (pref >= 40 && pref < 50))
    {
        printf("VISA");
    }
    else if ((l == 15) && (pref == 34 || pref == 37))
    {
        printf("AMEX");
    }
    else if ((l == 16) && (pref > 50 && pref <= 55))
    {
        printf("MASTERCARD");
    }
    else
    {
        printf("INVALID");
    }
    printf("\n");
    return 0;
}