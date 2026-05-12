import random
import sys

#limite int
lowr = -1 * (1 << 31)
uppr = 1 << 31

n=int(sys.argv[1])

#generarea propriu-zisa
nums = [random.randint(lowr, uppr) for _ in range(n)]


if len(sys.argv) > 2:
        mode = sys.argv[2]
        if(mode == "worst"):
                nums.sort(reverse = True)
                
        elif(mode == "best"):
                nums.sort()
        #else pp average

print(n)
for x in nums:
        print(x, end=" ")

