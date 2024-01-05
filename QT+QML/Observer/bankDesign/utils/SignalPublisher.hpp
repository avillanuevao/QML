#ifndef SIGNALPUBLISHER_HPP
#define SIGNALPUBLISHER_HPP

#include <algorithm>
#include <vector>
#include <memory>
#include <utils/SignalSubscriber.hpp>   //Utilizar rutas absolutas

template <class Signal>
class SignalPublisher
{
    public:
        SignalPublisher() = default;

        void addSubscriber(std::shared_ptr<SignalSubscriber<Signal>> subscriber)
        {
            m_subscribers.push_back(subscriber);
        }

        void removeSubscriber(std::shared_ptr<SignalSubscriber<Signal>> subscriber)
        {
            m_subscribers.erase(std::remove(m_subscribers.begin(), m_subscribers.end(), *subscriber), m_subscribers.end());
        }

        void notifySubscribers(Signal signal)
        {
            for (std::shared_ptr<SignalSubscriber<Signal>> subscriber : m_subscribers)
            {
                subscriber->update(signal);
            }
        }

    private:
        std::vector<std::shared_ptr<SignalSubscriber<Signal>>> m_subscribers;
};

#endif // SIGNALPUBLISHER_HPP
