import quandl
import numpy as np
from sklearn import preprocessing
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
import pickle
import os


df = quandl.get('WIKI/GOOGL')

df = df[['Adj. Open', 'Adj. High', 'Adj. Low', 'Adj. Close', 'Adj. Volume']]

df['HL_Percent'] = ((df['Adj. High'] - df['Adj. Close']) / df['Adj. Close']) * 100
df['Percent_Change'] = ((df['Adj. Close'] - df['Adj. Open']) / df['Adj. Open']) * 100

df = df[['Adj. Close', 'HL_Percent', 'Percent_Change', 'Adj. Volume']]

forecast_col = 'Adj. Close'

df.fillna(-99999, inplace=True)

future_days = 10
df['label'] = df[forecast_col].shift(-future_days)

X = np.array(df.drop(['label'], 1))

X = preprocessing.scale(X)

predict_X = X[-future_days:]

X = X[:-future_days]

df.dropna(inplace=True)

y = np.array(df['label'])

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2)

pickle_file_name = 'linear_regression_sklearn.pickle'

if os.path.isfile('./' + pickle_file_name):

    pickle_file = open(pickle_file_name, 'rb')
    clf = pickle.load(pickle_file)

else:
    clf = LinearRegression(n_jobs=-1)

    clf.fit(X_train, y_train)

    with open(pickle_file_name, 'wb') as f:
        pickle.dump(clf, f)



accuracy = clf.score(X_test, y_test)
print('Accuracy on test data:', accuracy)

predictions = clf.predict(predict_X)
print('Predictions for next 10 days: ')
print(predictions)
