#include "View.hpp"

View::View(std::shared_ptr<model::Model> model) :
    m_model(model)
{

}

View::~View()
{

}

void View::update(Signal signal)
{
    std::cout << "Signal recieved: " << m_model->getAmount() << std::endl;
}
