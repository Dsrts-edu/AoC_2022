input = open("input.txt")
output = open("output.txt", "w")

# Do some BS to get the input as a string, we know it is one line, so this is ok here. 
line = ''
for i in input:
        line = i

position = 14 # add to this to determine position where the string is accepted 

# Loop through groups in the string, find the first group with no matches
for i in range(len(line)-14):
        flag_1 = False # Remains False if matches are found!
        flag_2 = False # Remains False if no matches are found!

        # capture the next 14 chars as a list. 
        current_14 = line[i:i+14]
        for j in range(14):
                cur_char = line[i+j]
                for k in range(14):
                        if current_14[k] == cur_char and k != j:
                                flag_1 = True
                                break # once a match is found, you can move on to the next group 
                        else:
                                flag_2 = True # if not a match, set true 
        if (not flag_1) and flag_2:
                position += i # update position for the problem 
                break # You are done, break out.        
print("Position:", position)
                


