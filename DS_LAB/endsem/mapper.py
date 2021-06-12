import sys
import pandas as pd
df = pd.read_csv('countries.csv')  # read the dataset
df = df.dropna()
words1 = list(df['country'].values)  # column for country
words2 = list(df['population'].values)  # column for total population
# Mapper output
for (word1, word2) in zip(words1, words2):
print(f'{word1} \t {word2}')
