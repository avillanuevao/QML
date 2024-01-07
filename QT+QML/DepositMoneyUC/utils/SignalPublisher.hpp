#ifndef SIGNALPUBLISHER_HPP
#define SIGNALPUBLISHER_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

#include <utils/SignalSubscriber.hpp>

namespace utils {

template <class Signal>
class SignalPublisher
{
    public:
        SignalPublisher() = default;

        void addSubscriber(SignalSubscriber<Signal>& subscriber)
        {
            m_subscribers.push_back(subscriber);
        }

        void notifySubscribers(const Signal& signal)
        {
            if(m_subscribers.size() > 0)
            {
                for (std::reference_wrapper<SignalSubscriber<Signal>>& subscriber : m_subscribers)
                {
                    subscriber.get().update(signal);
                }
            }
        }

private:
        std::vector<std::reference_wrapper<SignalSubscriber<Signal>>> m_subscribers;
};

}

#endif // SIGNALPUBLISHER_HPP
