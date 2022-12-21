import fileinput


input = open("input.txt")
output = open("output.txt", "w")

count = 0

for line in input:
       # output.write("Line: " + line)
        cur_pair = line.split(',')
       # output.write(cur_pair[0] + " " + cur_pair[1])
        pair_1 = cur_pair[0].split('-')
        pair_2 = cur_pair[1].split('-')
        output.write(pair_1[0] + " " + pair_1[1] + " " + pair_2[0] + " " + pair_2[1])

        pair_1 = [int(i) for i in pair_1]
        pair_2 = [int(i) for i in pair_2]

        #Get low and high of each range 
        p1_low = pair_1[0]
        p1_high = pair_1[1]
        p2_low = pair_2[0]
        p2_high = pair_2[1]

        #If range of pair 1 is in pair 2 or if range of pair 2 is in pair 1, add to count 
        if ((p1_low >= p2_low) and (p1_high <= p2_high)) or ((p2_low >= p1_low) and (p2_high <= p1_high)):
                count += 1
                output.write("CONTAINED\n")
        #If 
     #   elif:

        else:
                output.write("NOT CONTAINED\n")
print(count) 
        