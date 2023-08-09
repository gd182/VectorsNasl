

#include <iostream>
#include <math.h>

class Vector {
public:
    virtual double VLong() = 0;
};

class VectorOne : public Vector
{
public:
    VectorOne()
    {
        this->x1 = 0;
    }

    VectorOne(double x1)
    {
        this->x1 = x1;
    }

    double VLong() override
    {
        return fabs(x1);
    }
protected:
    double x1;
};

class VectorTwo : public Vector
{
public:
    VectorTwo()
    {
        this->x1 = 0;
        this->x2 = 0;
    }

    VectorTwo(double x1, double x2)
    {
        this->x1 = x1;
        this->x2 = x2;
    }
    double VLong() override
    {
        return sqrt(x1 * x1 + x2 * x2);
    }
protected:
    double x1;
    double x2;
};

template <typename T>
struct Element {
    Element* NextElem;
    T* Elem;
};

template <typename T>
class OneList {
public:
    OneList() {
        Elem = nullptr;
        FirstElem = nullptr;
        EndElem = nullptr;
    }

    T* Get()
    {
        return Elem->Elem;
    }

    void Add(T* Vect)
    {
        Element<T>* NewElem = new Element<T>;
        NewElem->Elem = Vect;
        NewElem->NextElem = nullptr;
        if (FirstElem == nullptr)
        {
            FirstElem = NewElem;
            Elem = NewElem;
        }
        else
        {
            EndElem->NextElem = NewElem;
        }
        EndElem = NewElem;
    }

    void PrintVect() {
        First();
        do {
            T* Elem = Get();
            std::cout << Elem->VLong() << std::endl;
        } while (Next());
    }

    bool First()
    {
        if (FirstElem == nullptr) { return false; }
        Elem = FirstElem;
        return true;
    }

    bool Next()
    {
        if (Elem->NextElem == nullptr) { return false; }
        Elem = Elem->NextElem;
        return true;
    }

    ~OneList()
    {
        while (FirstElem != nullptr)
        {
            Elem = FirstElem->NextElem;
            delete FirstElem;
            FirstElem = Elem;
        }

    }

    Element<T>* Elem;
private:
    Element<T>* FirstElem;
    Element<T>* EndElem;
};

template <typename T>
void PrintVect(OneList<T>& List) {
    List->First();
    do {
        T* Elem = List->Get();
        std::cout << Elem->VLong << std::endl;
    } while (List->Next());
}

int main()
{
    OneList<Vector> CVector;
    VectorTwo a1(1, 3.4);
    VectorOne a2(2);
    VectorTwo a3(40, 3.8);
    VectorTwo a4(1, 10.4);
    VectorTwo a5(80, 13.7);
    VectorOne a6(1);
    CVector.Add(&a1);
    CVector.Add(&a2);
    CVector.Add(&a3);
    CVector.Add(&a4);
    CVector.Add(&a5);
    CVector.Add(&a6);
    CVector.PrintVect();
    //CVector.Add(&a6);
    //PrintVect<VectorTwo>((OneList<VectorTwo>)CVector);
}
