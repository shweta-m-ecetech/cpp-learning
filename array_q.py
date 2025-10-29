a=input()
b=list()
for i in range(len(a)):
     for j in range(len(a)-i):
         c=a[i:j]
         b.append(c)
words=list()
count=0
for string in a:
    for letter in string:
        e=list(string)
        if e.count(letter)==1:
              pass
        else:
              break
        count=count+1
for string in a:
     if count==len(string):
           words.append(string)
    

print(words)
length=list()
for word in words:
      length.append(len(word))
print(max(length))
       