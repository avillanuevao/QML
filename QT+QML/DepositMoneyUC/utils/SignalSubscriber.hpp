#ifndef SIGNALSUBSCRIBER_HPP
#define SIGNALSUBSCRIBER_HPP

namespace utils {

template <class Signal>
class SignalSubscriber
{
    public:
        SignalSubscriber() = default;
        virtual void update(Signal signal) = 0;
};

}

#endif // SIGNALSUBSCRIBER_HPP
