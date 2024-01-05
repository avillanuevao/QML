#ifndef MODEL_HPP
#define MODEL_HPP

#include <utils/SignalPublisher.hpp>
#include <model/signals/Signal.hpp>

namespace model
{
    class Model : public SignalPublisher<Signal>
    {
        public:
            Model();

            int getAmount() const;
            void setAmount(int newAmount);

        private:
            int m_amount;
    };
}


#endif // MODEL_HPP
