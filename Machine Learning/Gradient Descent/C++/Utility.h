
/* Header-only utility functions used for gradient descent */

#include <iostream>
#include <vector>
#include <cmath>
#include <boost/iterator/zip_iterator.hpp>
#include <boost/range.hpp>

using namespace std;
using namespace boost;

// Generating data from a linear function.
vector<double> GetLinearFunctionData(pair<int,int> range, double x, double yIntercept){
    vector<double> data(range.second);
    for(int i = 0; i < range.second; ++i){
        data[i] = (i + range.first) * x + yIntercept;
    }
    return data;
}

// Sum of squared erros.
double MSE(vector<double> actual, vector<double> predicted){
    auto actualItt = actual.begin();
    auto predictedItt = predicted.begin();
    double sum = 0;
    for( ; actualItt != actual.end(), predictedItt != predicted.end(); ++actualItt, ++predictedItt){
        sum += pow(*actualItt - *predictedItt, 2);
    }
    return sum/actual.size();
}