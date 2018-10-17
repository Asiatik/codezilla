
#include "Utility.h"

using namespace std;

vector<double> Predict(vector<double> x, pair<double, double> model){
    int numDataPoints = x.size();
    vector<double> predictions(numDataPoints);
    for(int i = 0; i < numDataPoints; ++i){
        predictions[i] = x[i] * model.first + model.second;
    }
    return predictions;
}

pair<double, double> LinearRegression(vector<double> x, vector<double> y, unsigned int epochs, double learningRate){
    // Initialize our linear regression model as: 0x + 0.
    pair<double, double> model(0, 0);
    for(int i = 0; i < epochs; ++i){
        auto predictions = Predict(x, model);

        // Calculate gradiants for x and y intercept.
        int numSamples = x.size();
        double gradientX = 0.0;
        double gradientY = 0.0;

        for(int k = 0; k < numSamples; ++k){
            double error = y[k] - predictions[k];
            gradientX += ((-2.0) / (double) numSamples) * error *y[k];
            gradientY += ((-2.0) / (double) numSamples) * error;
        }

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
    pair<vector<double>, vector<double>> data = GetLinearFunctionData(range, 2, 5);
    vector<double> xData = data.first;
    vector<double> yData = data.second;

    pair<double, double> model = LinearRegression(xData, yData, 10000, 0.0001);
    auto predictions = Predict(xData, model);

    cout << "Data generating function: 2x + 5" << endl;
    // Mean squared error: 2.37223.
    cout << "Mean squared error: " << MSE(yData, predictions) << endl;
    // Learned model: 2.04665x + 1.94324.
    cout << "Learned model: " << model.first << "x + " << model.second << endl;

    return 0;
}