import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
%matplotlib inline

df_feat = pd.read_csv("DB.csv")
df_feat.head()

from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test = train_test_split(df_feat, df_feat['Dx'], test_size=0.20,random_state=2)


from sklearn.svm import SVC
model = SVC()
model.fit(X_train,y_train)

predictions = model.predict(X_test)

from sklearn.metrics import classification_report,confusion_matrix
print(confusion_matrix(y_test,predictions))

print(classification_report(y_test,predictions))

param_grid = {'C': [0.0000001,0.000001,0.00001,0.0001,0.001,0.01,0.1,1, 10, 100, 1000,10000], 
              'gamma': [1000000,100000,10000,1000,100,10,1,0.1,0.01,0.001,0.0001], 
              'kernel': ['rbf']} 
              
from sklearn.model_selection import train_test_split
from sklearn.metrics import roc_curve
from sklearn.metrics import roc_auc_score
from matplotlib import pyplot

auc = roc_auc_score(y_test, predictions)
print('AUC: %.3f' % auc)
fpr, tpr, thresholds = roc_curve(y_test, predictions)
pyplot.plot([0, 1], [0, 1], linestyle='--')
pyplot.plot(fpr, tpr, marker='.')
pyplot.show()

from sklearn.model_selection import GridSearchCV
grid = GridSearchCV(SVC(),param_grid,refit=True,verbose=3)
grid.fit(X_train,y_train)

grid.best_params_
grid.best_estimator_
grid.best_score_
grid.best_estimator_

grid_predictions = grid.predict(X_test)
print(confusion_matrix(y_test,grid_predictions))
print(classification_report(y_test,grid_predictions))


