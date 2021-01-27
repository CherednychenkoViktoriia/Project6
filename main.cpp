#include "Reference.h"
#include "Passport.h"
#include "Currency.h"

int main()
{
    Passport passport1("Horbatenko Alla", "03/07/1995", "Ukrainian", "05/08/2001", 1221, 27089765);
    Passport copyOfpassport(passport1);
    Passport passport2("Poltavets Anna", "26/04/1997", "Ukrainian", "07/01/2004", 1223, 28075389);
    Passport passport3("Demchenko Igor", "05/10/1999", "Ukrainian", "14/08/2007", 1222, 31053489);
    Currency cur1(25000, 54);
    Currency cur2 (45663, 90);
    Currency cur3(64666, 87);
    Currency cur4(7623, 21);
    cur2 = std::move(cur4);
    Reference reference1(passport1, cur1);
    Reference reference2(passport2, cur2);
    Reference reference3(std::move(reference1));
    Reference reference4(passport3, cur3);
    reference4 = reference2;
    Reference reference5(reference3);
}