#include <string>
#include <iostream>
#include <coroutine>

///// Generator c++ 20 ///////////////
template<typename T>
struct Generator
{
    struct promise_type
    {
        T current_value;
        Generator GetReturnObject()
        {
            return Generator
            {
                std::coroutine_handle<promise_type>::from_promise(*this)
            };
        }
        std::suspend_always initial_suspend(){return {};}
        std::suspend_always final_suspend() noexcept {return{};}
        std::suspend_always yield_value(T value)
        {
            current_value = value;
            return {};
        }
        void return_void(){}
        void unhandled_exception(){std::exit(1);}
    };

    using handle_type = std::coroutine_handle<promise_type>;
    handle_type handle;

    explicit Generator(handle_type h) : handle(h){}
    ~Generator(){ if ( handle) handle.destroy();}
    
};