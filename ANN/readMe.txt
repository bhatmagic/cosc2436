/* ************************************************************************
Name: David Boyd and Jacob Reola
Assignment: 09_nNetwork
Purpose: Read Me file
Notes:
      To run program: argv == "and", "or", "xor", <filename.ext>
Date: 2018.12.11
************************************************************************ */

This is a vector neural network testing and, or, xor.

How to run:

To compile, please use command line:: $ g++ std=c++1z -o main *.cpp

To run program, please use command line:: * ./main and

	Replace "main" with declared program's compiled name
    
	To run "and.dat": $ ./main and 
        To run "or.dat" : $ ./main or
        To run "xor.dat": $ ./main xor
        To run <filename>:$ ./main filename.ext

How it works:
  After testing, weights will be saved to a weights.txt file.

SOURCES: 

Smoothing Factor resources: 

	http://www.princeton.edu/~stengel/TNN2005.pdf
	https://www.quora.com/What-does-it-mean-for-a-function-to-be-smooth-in-a-neural-networks-context

Momentum:

	https://www.quora.com/What-does-momentum-mean-in-neural-networks

Backpropagation:
	http://neuralnetworksanddeeplearning.com/chap2.html
	https://en.wikipedia.org/wiki/Backpropagation
	https://en.wikipedia.org/wiki/Gradient
	https://en.wikipedia.org/wiki/Loss_function
	https://theclevermachine.wordpress.com/2014/09/06/derivation-error-backpropagation-gradient-descent-for-neural-networks/

Training:

	http://neuralnetworksanddeeplearning.com/chap5.html
	https://towardsdatascience.com/multi-layer-nural-networks-with-sigmoid-function-deep-learning-for-rookies-2-bf464f09eb7f
	https://cs230.stanford.edu/files/Notation.pdf
	https://stats.stackexchange.com/questions/277086/what-is-the-meaning-of-the-error-rate-in-neural-networks

Gits:

	https://github.com/huangzehao/SimpleNeuralNetwork/blob/master/src/neural-net.cpp\
	https://github.com/GarethRichards/Machine-Learning-CPP/blob/master/Chapter1/NeuralNet1.cpp\

DeltaRule and functions:

	https://en.wikipedia.org/wiki/Delta_rule
	https://www.quora.com/What-is-the-sigmoid-function-and-what-is-its-use-in-machine-learnings-neural-networks-How-about-the-sigmoid-derivative-function

Neurons:

	https://stats.stackexchange.com/questions/241888/what-are-neurons-in-neural-networks-how-do-they-work

General Knowledge:
	https://www.youtube.com/channel/UCYO_jab_esuFRV4b17AJtAw/playlists

// END README.TXT
