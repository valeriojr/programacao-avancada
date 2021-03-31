import decimal
 
 
def score(hand):
  score = 0
  for i in range(1, 10):
    score += i * (10 ** hand.count(i))
  
  return score
  
 
k = int(input())
s = [int(c) for c in input()[:-1]]
t = [int(c) for c in input()[:-1]]
total = [k for i in range(1, 10)]
win = 0
sample_space = 0
 
s.append(0)
t.append(0) 
 
for i in range(4):
  total[s[i] - 1] -= 1
  total[t[i] - 1] -= 1
 
for i in range(1, 10):
  for j in range(1, 10):
    if total[i - 1] > 0 and total[j - 1] > 0:
      s[4] = i
      t[4] = j
      
      takahashi_score = score(s)
      aoki_score = score(t)
      
      combinations = total[i - 1] * (total[j - 1] if i != j else (total[j - 1] - 1))
      
      if takahashi_score > aoki_score:
        win += combinations
      sample_space += combinations
 
print(str(decimal.Decimal(win) / decimal.Decimal(sample_space)))

