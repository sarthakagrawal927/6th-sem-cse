#import string
import fileinput
for line in fileinput.input():
    data = line.strip().split("\t")
    if len(data) == 6:
        date, time, location, item, cost, payment = data
        print("{0}\t{1}".format(location, cost))
# for heart disease file
        age, sex, cp, trestbps, chol, fbs, restecg, thalach, exang, oldpeak, slope, ca, that, target = data
        print('{0}\t{1}'.format(age, chol))
# for covid file
        SNo, ObservationDate, Province_State, Country_Region, Last_Update, Confirmed, Deaths, Recovered = data
        print('{0}\t{1}'.format(Country_Region, Deaths))
# for credit file
        Creditability, CreditAmount, DurationOfCreditInMonths = data
        print('{0}\t{1}'.format(Creditability, DurationOfCreditInMonths))
