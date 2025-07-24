#include <stdio.h>

typedef struct {
    int den;
    int num;
}RACIONAL;

float real(int a, int b)
{
    return a / b;
}

int MDC(int a, int b) // calculo do mdc
{
    int r;
    while (b)
    {
        r= a%b;
        a = b;
        b = r;
    }
    return a;
}
RACIONAL real(RACIONAL RE)
{
    
}

RACIONAL simplifica(RACIONAL R)
{
    int mdc = MDC(R.num, R.den);
    R.num /= mdc; 
    R.den /= mdc;
    
    if (R.den < 0) {
        R.num *= -1;
        R.den *= -1;
    }
    return R;
}
RACIONAL somaRAC(RACIONAL R1, RACIONAL R2)
{
    RACIONAL s;
    
    s.den = R1.den*R2.den;
    s.num = (R1.num* R2.den) + (R2.num*R1.den);
    return simplifica(s);
}
RACIONAL subRAC(RACIONAL R1, RACIONAL R2)
{
    RACIONAL s;
    
    s.den = R1.den*R2.den;
    s.num = (R1.num* R2.den) - (R2.num*R1.den);
    return simplifica(s);
}
RACIONAL multRAC(RACIONAL R1, RACIONAL R2)
{
    RACIONAL m;
    
    m.num = R1.num*R2.num;
    m.den = R1.den*R2.den;
    return simplifica(m);
}
RACIONAL divRAC(RACIONAL R1, RACIONAL R2)
{
    RACIONAL d;
    
    d.num = R1.num*R2.num;
    d.den = R1.den*R2.num;
    return simplifica(d);
}


int main()
{
    RACIONAL A, B;
    RACIONAL C;
    
    scanf("%d/%d %d/%d", &A.num, &A.den, &B.num, &B.den);
    printf("%d", somaRAC(RACIONAL A, RACIONAL B));
    
}