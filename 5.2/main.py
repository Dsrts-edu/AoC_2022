import fileinput


input = open("input.txt")
output = open("output.txt", "w")

stacks = []

for i in range(9):
        stacks.append([])

#Get the stacks, place them into the stacks list in an acceptable way
# each line will place items into each 'stack' in stacks
for line in input:

        # hard coded cuz I have had a colorado mule and IDGAF HAPPY CHRIMMS
        # don't @ me 
        # 'balmer curve' my a$$
        if(line.split(' ') == ['', '1', '', '', '2', '', '', '3', '', '', '4', '', '', '5', '', '', '6', '', '', '7', '', '', '8', '', '', '9', '\n']):
                break
        # Place the current line in an array 
        cur_line_array = line.split(' ')

      #  print(cur_line_array, end = " ")

        # for tracking the input stacks index, which varies (because of the split using spaces)
        input_stacks_idx = 0 
        # for each column in stacks (there are 9 here, CONST would be better, but this is the holidays, and this is my present to myself)
        for i in range(9):

                #If a column contains something, add it to the stacks array
                if (len(cur_line_array[input_stacks_idx]) > 0):
                        #print(cur_line_array[input_stacks_idx][1])

                        # add to the relevant stack 
                        stacks[i] = [cur_line_array[input_stacks_idx][1]] + stacks[i] 
                        input_stacks_idx += 1
                        
                # If a column is empty (denoted by a ''), 'skip' to the next column,
                # for this input, it will be 4 extra spaces over in the array 
                else:
                        #if the line is a space, 'skip' a column (4 spaces)
                        input_stacks_idx += 4 


## ok, whew, now it's time to get moves. I am doing this in its own for loop
# I could do it in the same for loop above, but don't want to. SO. There you have it. 
# Python makes this ez pz 

moves = []

line_count = 0
for line in input: 
        if line[0] != '\n':
                moves.append(line.split(' '))
for i in moves:
     #   print(i)
        num_blocks = int(i[1])
        from_idx = int(i[3]) - 1
        to_idx = int(i[5][0]) - 1

        output.write("Move " + str(num_blocks) + ' from ' + str(from_idx + 1) + ' to ' + str(to_idx + 1) + "\n")

        # Move i blocks from one place to another, as a whole stack
        cur_blocks = []
        output.write(str(stacks[from_idx]) + "\n")
        for i in range (num_blocks):
             cur_blocks = [stacks[from_idx].pop()] + cur_blocks
             output.write("curblocks " + str(cur_blocks) + "\n")

        output.write("Stacks\n")        
        stacks[to_idx].extend(cur_blocks)
        for j in stacks:
                 output.write(str(j) + "\n")
        output.write("\n")

        # this is a (tm) Hot Mess 
        # enjoy! 

print(len(moves))

print(stacks)

for i in stacks:
        print(i[-1], end = '')
print()
