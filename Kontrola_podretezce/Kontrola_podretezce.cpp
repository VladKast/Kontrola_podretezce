#include <iostream>
#include <string>

class Fronta
{
    // struktura fronty
    struct Tstruct {
        int value;
        Tstruct* next;
    };

    Tstruct* HEAD, * TAIL;                  // pointer na head a tail fronty
public:
    Fronta() {
        // constuctor který spustí frontu
        HEAD = NULL;                        // nastavení HEADu na nulu
        TAIL = NULL;                        // nastavení TAILu na nulu
    }

    // funkce enqueue: vloží novou hodnotu do TAILu fronty
    void Enqueue(int VALUE) {
        Tstruct* l_hlp;                     // Helping pointer

        try                                 // zkusit alocovat paměť
        {
            l_hlp = new Tstruct;
        }
        catch (const std::bad_alloc& e) {
            throw std::runtime_error(e.what());

        }

        l_hlp->value = VALUE;              // uchová hodnotu
        l_hlp->next = NULL;                // poslední element na NULL
        if (TAIL) TAIL->next = l_hlp;      // next of recent TAIL pints to the new element
        TAIL = l_hlp;                      // nový člen se stane novým TAILem
        if (HEAD == NULL) HEAD = l_hlp;    // pokud je fronta prázdná, nový element je také HEAD

    }

    int Dequeue() {                       // funkce Denqueue: vyloží  hodnotu z HEAD fronty
        if (HEAD == NULL)
        {
            throw std::runtime_error("Fronta je prazdna");
            return 0;
        }


        int l_val;                        // Pomocná proměnná
        Tstruct* l_hlp;                   // Pomocná proměnná
        l_hlp = HEAD;                     // uloží pointer do HEADu
        l_val = HEAD->value;              // uloží hodnotu z HEADu
        HEAD = l_hlp->next;               // element který následuje za HEAD se stane novym HEADem
        if (HEAD == NULL) TAIL = NULL;    // pokud byl poslední element vyřazen z fronty, pak TAIL musí být NULL 
        delete l_hlp;
        return l_val;

    };


    int Show() {                        // funkce Show - vrátí hodnotu z HEADu fronty bez toho aniž by proběhlo ji vyprázdnilo
        if (HEAD)
        {
            return HEAD->value;
        }
        else
        {
            throw std::runtime_error("Fronta je prazdna");
            return 0;
        }

    };

    bool IsEmpty() {                  // funkce IsEmtpy vráří true nebo false pokud je nebo není prázdná

        return !bool(HEAD);
    }

    void Empty() {                    // funkce Empty - vyprázdní frontu 
        while (!IsEmpty()) Dequeue();

    }

    ~Fronta() {
        Empty();
        delete(HEAD);
        delete(TAIL);
    };

};

int main()
{
    Fronta fronta;
    int delkaRetezce;                         // proměnná pro zapsání počtu znaků
    char retezcec_k_porovnani[20];            // proměnná pro zapsání řetězce k porovnání 

    std::cout << "Napis retezec se sudym poctem znaku a bez mezer: " << '\n';
    std::cin >> retezcec_k_porovnani;                    // řětězec k porovnání 
    delkaRetezce = strlen(retezcec_k_porovnani);         // zjištění délky vloženého řetězce
    std::cout << "zadany retezec k porovnani je " << retezcec_k_porovnani << '\n';

    if (delkaRetezce % 2 != false)
    {
        std::cout << "retezec je lichy a tudiz nemuze obsahovat zasebou jdouci identicke podretezce." << '\n';
        return 0;
    }

    int index1, index2;                      // hodnoty fronty 

    index1 != true;
    for (index1 = false; index1 <= delkaRetezce; index1++) fronta.Enqueue(retezcec_k_porovnani[index1]);
    {
        index2 == false;
    }

    bool hledaniShody;

    index2 == false;
    for (index2 = false; index2 <= (delkaRetezce / 2 - 1) || fronta.IsEmpty(); index2++)
        if (retezcec_k_porovnani[(delkaRetezce / 2) + index2] == fronta.Show())
        {
            hledaniShody = true;
            fronta.Dequeue();
        }
        else
        {
            hledaniShody = false;
            break;
        }


    if (hledaniShody == false)
    {
        std::cout << "A zadany retezec nobsahuje za sebou jdouci identicke podretezce." << '\n';
    }
    else
    {
        std::cout << "A zadany retezec obsahuje za sebou jdouci identicke podretezce." << '\n';
    }
    return 0;
}

