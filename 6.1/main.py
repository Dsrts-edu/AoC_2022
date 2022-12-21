input = open("input.txt")
output = open("output.txt", "w")

# Do some BS to get the input as a string, we know it is one line, so this is ok here. 
line = ''
for i in input:
        line = i

for i in range(len(line)-3):
       # Brute force 
        if line[i] == line[i+1] or line[i] == line[i+2] or line[i] == line[i+3] or line[i+1] == line[i+2] or line[i+1] == line[i+3] or line[i+2] == line[i+3]:
                print(line[i],line[i+1],line[i+2],line[i+3], end = " | ")
                continue
        else:
                print(line[i],line[i+1],line[i+2],line[i+3])
                print(i)
                print(str(i+4))
                break    
print()

