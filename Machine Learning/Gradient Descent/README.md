
# Gradient Descent Optimisation Algorithm

This explanation of the algorithm will not go into details with the mathematics, however, it is an important part but it is better explained online and in books. Instead, the focus is more on a high-level explanation of the algorithm.

Gradient descent is a mathematical optimization algorithm. It is essentially a hill-climbing algorithm that follows the gradient of the function being optimized in order to search for optimal values. It is called gradient descent because we minimize a function by incrementally following the gradient towards a local minimum. And it is often used when training machine learning models.

A gradient is basically the derivative for multi-variable functions, but it is a vector rather than a scaler. The gradient vector encapsulates the partial derivatives of a multi-variable function with respect to its parameters. The gradient of a function with respect to its input tells us something about how it behaves when we change the input, and for gradient descent we exploit a property, that is, the gradient vector points towards the steepest ascent. Hence, minimizing a function in iterations is simply calculating the gradient and moving in the opposite direction.

Practically, we derive the partial derivative of our error function with respect to our model parameters, calculate the partial derivative for each weight and incrementally update each parameter in the opposite sign of the corresponding partial derivative.

## Pseudocode
Where lr is the learning rate, epochs is the number of iterations, and w are the model parameters.

        for i to num_epochs:
            for w_i in w:
                w_i = w_i - lr * partial_derivative(loss, w_i)
