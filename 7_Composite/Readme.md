# Composite Pattern

## CRTP

    Use of the Curiously recurring template pattern (CRTP) to resolved the API between the obj (Neuron) and the group of objs (NeuronLayer), for this Neuron is treated as a vector of one object (this is why we declare the begin() and end() functions).

## Array_backed

    An Array backed is a data structure where the underlying values are stored in an array.
    In the example we declare an enum with some stats and a count that will hold the amount of stats inside the enum,
    and in the array<int,count> where in is the value of each stat and count the amount if stats.
    