
#include "Utility.h"

using namespace std;

vector<double> Predict(vector<double> data, pair<double, double> model){
    int numDataPoints = data.size();
    vector<double> predictions(numDataPoints);
    for(int i = 0; i < numDataPoints; ++i){
        predictions[i] = i * model.first + model.second;
    }
    return predictions;
}

pair<double, double> GradientDescent(vector<double> data, double learningRate, pair<double, double> model){
    return pair<double, double>(0.0, 0.0);
}

pair<double, double> LinearRegression(vector<double> data, unsigned int epochs, double learningRate){
    // Initialize our linear regression model as: 1x + 1.
    pair<double, double> model(0, 0);
    for(int i = 0; i < epochs; ++i){
        auto predictions = Predict(data, model);

        // Calculate gradiants for x and y intercept.
        int numSamples = data.size();
        double gradientX = 0;
        double gradientY = 0;
        for(int k = 0; k < numSamples; ++k){
            double loss = data[k] - predictions[k];
            gradientY -= loss;
            gradientX -= loss * data[k];
        }
        gradientX *= (double) 2/numSamples;
        gradientY *= (double) 2/numSamples;

        // Perform gradient descent step.
        model.first = model.first - (learningRate * gradientX);
        model.second = model.second - (learningRate * gradientY);
    }
    return model;
}

int main(){
    // Define the x range for data generation. 
    pair<int,int> range = pair<int,int>(0,100);

    // Get data from the following linear function: 2x + 5. 
    vector<double> data = GetLinearFunctionData(range, 2, 5);

    pair<double, double> model = LinearRegression(data, 100000, 0.0001);
    auto predictions = Predict(data, model);

    cout << "Data generating function: 2x + 5" << endl;
    cout << "Mean squared error: " << MSE(data, predictions) << endl;
    cout << "Learned model: " << model.first << "x + " << model.second << endl;

    return 0;
}