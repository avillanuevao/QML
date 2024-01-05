#include "Model.hpp"

namespace model
{
    Model::Model()
    {
        m_amount = 33;
    }

    int Model::getAmount() const //Solo lectura
    {
        return m_amount;
    }

    void Model::setAmount(int newAmount)
    {
        m_amount = newAmount;
        Signal signal = Signal();

        notifySubscribers(signal);
    }
}

