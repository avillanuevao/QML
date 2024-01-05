#ifndef VIEW_HPP
#define VIEW_HPP

#include <utils/SignalSubscriber.hpp>
#include <model/Model.hpp>
#include <model/signals/Signal.hpp>
#include <iostream>
#include <memory>

class View : public SignalSubscriber<Signal>
{
    public:
        View(std::shared_ptr<model::Model> model);
        virtual ~View();
        void update(Signal signal);
        void doSomething()
        {
            std::cout << "Signal recieved: " << m_model->getAmount() << std::endl;
        }

    private:
        const std::shared_ptr<model::Model> m_model;

};

#endif // VIEW_HPP
