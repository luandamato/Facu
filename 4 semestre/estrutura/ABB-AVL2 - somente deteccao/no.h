#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED

class No {

private:
    int valor;
    No * fesq;
    No * fdir;
    int pesq;
    int pdir;
public:
    No(int v);
    int getValor();
    No * getFesq();
    No * getFdir();
    void setFesq(No * n);
    void setFdir(No * n);
    int getPesq();
    int getPdir();
    void setPesq(int v);
    void setPdir(int v);
};



#endif // NO_H_INCLUDED
