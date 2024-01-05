#ifndef SIGNALSUBSCRIBER_HPP
#define SIGNALSUBSCRIBER_HPP

template <class Signal>
class SignalSubscriber
{
public:
    SignalSubscriber() = default;
    virtual ~SignalSubscriber(){}

    virtual void update(Signal signal) = 0;
};

#endif // SIGNALSUBSCRIBER_HPP
