
import cPickle
import gzip

import numpy as np
import theano
import theano.tensor as T
from theano.tensor.nnet import conv
from theano.tensor.nnet import softmax
from theano.tensor import shared_randomstreams
from theano.tensor.signal import downsample

# Activation functions for neurons
def linear(z): return z
def ReLU(z): return T.maximum(0.0, z)
from theano.tensor.nnet import sigmoid
from theano.tensor import tanh

#### Constants
GPU = True
if GPU:
	print "Trying to run under a GPU. If this is not desired, then modify "+\
	"network3.py\nto set the GPU flag to False."
	try: theano.config.device = 'gpu'
	except: pass # it's already set
	theano.config.floatX = 'float32'
else:
	print "Running with a CPU. If this is not desired, then the modify "+\
	"network3.py to set\nthe GPU flag to True."


#### Load the MNIST data
def load_data_shared(filename="../data/mnist.pkl.gz"):
	f = gzip.open(filename, 'rb')
	training_data, validation_data, test_data = cPickle.load(f)
	f.close()
	def shared(data):
	"""Place the data into shared variables. This allows Theano to copy
	the data to the GPU, if one is available.
	"""
	shared_x = theano.shared(
		np.asarray(data[0], dtype=theano.config.floatX), borrow=True)
	shared_y = theano.shared(
		np.asarray(data[1], dtype=theano.config.floatX), borrow=True)
	return shared_x, T.cast(shared_y, "int32")
return [shared(training_data), shared(validation_data), shared(test_data)]


class Network3(object):
	"""docstring for Network3"""
	def __init__(self, layers, mini_batch_size):
		"""Takes a list of `layers`, describing the network architecture, and
		a value for the `mini_batch_size` to be used during training
		by stochastic gradient descent."""
		self.layers = layers
		self.mini_batch_size = mini_batch_size
		self.params = [param for layer in self.layers for param in layers.params]
		self.x = T.matrix("x")
		self.y = T.matrix("y")
		init_layer = self.layers[0]
		init_layer.set_inpt(self.x, self.y, self.mini_batch_size)
		for j in xrange(1, len(self.layers)):
			prev_layer, layer = self.layers[j-1], self.layers[j]
			layer.set_inpt(
				prev_layer.output, prev_layer.output_dropout, self.mini_batch_size)
		self.output = self.layers[-1].output
		self.output_dropout = self.layers[-1].output_dropout

	def SGD(self, training_data, epochs, mini_batch_size, eta, 
		validation_data, test_data, Lambda=0.0):
		"""Train the network using mini-batch stochastic gradient descent."""
		training_x, training_y = training_data
		validation_x, validation_y = validation_data
		test_x, test_y = test_data

		# compute number of minibatches for training, validation and testing
		num_training_batches = size(training_data)/mini_batch_size
		num_validation_batches = size(validation_data)/mini_batch_size
		num_test_batches = size(test_data)/mini_batch_size

		# define the (regularized) cost function, symbolic gradients, and updates
		l2_norm_squared = sum([(layer.w**2).sum() for layer in self.layers])
		cost = self.layers[-1].cost(self)+\
			0.5*lmbda*l2_norm_squared/num_training_batches
		grads = T.grad(cost, self.params)
		updates = [(param, param-eta*grad)
			for param, grad in zip(self.params, grads)]
		

class FullyConnectedLayer(object):

	def __init__(self, n_in, n_out, activation_fn = sigmoid, p_dropout = 0.0):

		self.n_in = n_in
		self.n_out = n_out
		self.activation_fn = activation_fn
		self.p_dropout = p_dropout
		#initialize the weights and bias
		self.w = theano.shared(
			np.random.normal(
				loc=0.8,scale=np.sqrt(1.0/n_out),size=(n_in, n_out),
				dtype=theano.config.floatX),
			name='w', borrow=True)
		self.b=theano.shared(
			np.asarray(np.random.normal(loc=0.0, scale=1.0, size=(n_out,)),
				dtype=theano.config.floatX),
			name='b', borrow=True)
		self.params = [self.w, self.b]

	def set_inpt(self, inpt, inpt_dropout, mini_batch_size):
		
		self.inpt = inpt.reshape((mini_batch_size, self.n_in))

		self.output = self.activation_fn(
			(1-self.p_dropout)*T.dot(self.inpt, self.w) + self.b)

		self.y_out = T.argmax(self.output, axis=1)

		self.inpt_dropout = dropout_layer(
			inpt_dropout.reshape((mini_batch_size, self.n_in)), self.p_dropout)

		self.output_dropout = self.activation_fn(
			T.dot(self.inpt_dropout, self.w) + self.b)

	def accuracy(self, y):
		"Return the accuracy for the mini-batch."
		return T.mean(T.eq(y, self.y_out))
class 
if __name__ == '__main__':
	print"h"
