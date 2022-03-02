#include "Layer.hpp"

// Backpropagation Notes
/*
1. Change the bias. Move the bias an amount which is proportional to the 
"cost" of the output node.

2. Change the weights. If we want the output HIGH, then increase the 
weights between the output neuron, and the previous layer's neurons 
which are already high. Change must be proportional to the neuron's 
value (since they are multiplied). So if you have a high "cost" 
(difference),  change the weight a lot. If you have a low "cost", change 
it less.

3. Change the previous layer's neurons. Change the neuron's value 
proportionally to the weight connecting that neuron and the current 
neuron. We can't directly change it, so we save the desired change, 
and loop through all the output neurons, adding up all their desired 
changes. Once all the desired changes are collected, add the changes 
together to get a desired change for each node. Then go through the whole 
process again.
*/

typedef std::initializer_list<layer_s> SizeList;

class Network {
private:
	std::vector<Layer> layers;

public:
	// Constructor
	Network(layer_s, SizeList, layer_s);

	// Methods
	Vector askNetwork(Vector);
	Vector train(Vector, Vector);
	void backPropagate(Vector, Vector, int);
	static float calculateNetworkCost(Vector, Vector);
	static void PrintNeurons(Vector);
};