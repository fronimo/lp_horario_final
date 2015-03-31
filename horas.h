#ifndef HORAS_H
#define HORAS_H


class Horas
{
    public:

    int h_ini;
    int h_fin;
    int m_ini;
    int m_fin;
    Horas();
    Horas(int h_i, int m_i, int h_f, int m_f)
    {
        h_ini = h_i;
        m_ini = m_i;
        h_fin = h_f;
        m_fin = m_f;
    }

    virtual ~Horas();

    protected:
    private:
};

#endif // HORAS_H
