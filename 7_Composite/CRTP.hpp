#pragma once
/*
    Composite pattern applying CRTP : 
    Curiously recurring template pattern =
    Is an idiom, originally in C++, in which a class X derives from a class 
    template instantiation using X itself as a template argument.[1] 
    More generally it is known as F-bound polymorphism, and it is a 
    form of F-bounded quantification. 
*/
#include <vector>
#include <ostream>
#include <iostream>

// forward declaration to resolves the circular dependency 
struct Neuron;

// CRTP 
template<typename Self>
struct SomeNeurons
{
    template<typename T>
    void ConnectTo(T& Other);
};

struct Neuron : SomeNeurons<Neuron>
{
    std::vector<Neuron*> in; 
    std::vector<Neuron*> out;
    unsigned int id;
    static int id_counter;
    Neuron()
    {
        this->id = id_counter++;
    }

    Neuron* begin() { return this;}
    Neuron* end() {return this+1;}

    friend std::ostream& operator<<(std::ostream& os, const Neuron& obj)
    {
        for(Neuron* n : obj.in)
        {
            os << n->id << "\t-->\t[" << obj.id << "]" << '\n';
        }
        for (Neuron* n : obj.out)
        {
            os << "[" << obj.id << "]\t-->\t" << n->id << '\n';
        }
        return os;
    }
};

int Neuron::id_counter = 1;

// CRTP
template<typename Self>
template<typename T>
void SomeNeurons<Self>::ConnectTo(T& Other)
{
    for(Neuron& from : *static_cast<Self*>(this))
    {
        for (Neuron& to : Other)
        {
            from.out.emplace_back(&to);
            to.in.emplace_back(&from);
        }
    }
}

struct NeuronLayer : std::vector<Neuron>, SomeNeurons<NeuronLayer>
{
    NeuronLayer(int count)
    {
        while (count-- > 0)
        {
            emplace_back(Neuron{});
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const NeuronLayer& obj)
    {
        for(const auto& n : obj) 
            os << n;
        return os;
    }
};

void ExecuteTest()
{
    Neuron n1, n2;
    n1.ConnectTo(n2);
    std::cout << n1 << n2 << '\n';
    NeuronLayer layer1{2}, layer2{3};
    n1.ConnectTo(layer1);
    layer2.ConnectTo(n2);
    layer1.ConnectTo(layer2);
    std::cout << layer1 << '\n';
    std::cout << layer2 << '\n';
}