/*
    Functional Factory for Robot creation
*/
#include <string>
#include <iostream>
#include <functional>
#include <memory>

// abstract item
struct Machine{
        virtual void Assembly()=0;
        virtual ~Machine()=default;
};
// concrete items
struct Worker: Machine{
    void Assembly() override {
        std::cout << "I am Assembled as Worker" << std::endl;
    }
};
struct Cleaner: Machine{
    void Assembly() override {
        std::cout << "I am Assembled as Cleaner" << std::endl;
    }
};

// abstract Factory
class MachineFactory
{
    public:
    virtual std::unique_ptr<Machine> Create(const std::string& name, int number)=0;
    virtual ~MachineFactory()=default;
};

// Concrete factories
class WorkerFactory : public MachineFactory{
    public:
        std::unique_ptr<Machine> Create(const std::string& name,int number){
            std::cout << name << " : " << " Now we are :" << number << std::endl;
            return std::make_unique<Worker>();
        }
};
class CleanerFactory : public MachineFactory{
    public:
        std::unique_ptr<Machine> Create(const std::string& name,int number){
            std::cout << name << " : " << " Now we are :" << number << std::endl;
            return std::make_unique<Cleaner>();
        }
};