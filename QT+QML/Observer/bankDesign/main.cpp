#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <view/View.hpp>
#include <model/Model.hpp>
#include <memory>

int main()
{

    std::shared_ptr<model::Model> model = std::shared_ptr<model::Model>(new model::Model());
    std::shared_ptr<View> view = std::shared_ptr<View>(new View(model));

    model->addSubscriber(view);

    model.reset();
    //    model::Model model = model::Model();

    //    View view = View(&model);

    //    model.addSubscriber(&view);
    //Introduccion de subs es determinante, ya que indica el orden de ejecucion.

    //    model.setAmount(10);

    //    std::shared_ptr<model::Model> modelA = std::shared_ptr<model::Model>(new model::Model());

    //    std::unique_ptr<View> view2 = std::unique_ptr<View>(new View(modelA));
    //    std::shared_ptr<model::Model> modelB = modelA;

    //    view2->doSomething();

    //    view2.reset();
    ////    view2 = NULL;

    //    modelA.reset();


}
