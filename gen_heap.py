import random
import sys





#limite int
lowr = -1 * (1 << 31)
uppr = 1 << 31


n=int(sys.argv[1])
nums=[]
#generarea propriu-zisa


def gen_worst():
        #fortez multe mutari in constructia heap ului
        global nums
        nums = [random.randint for _ in range(n)]
        nums.sort()

def gen_average():
        global nums
        nums = [random.randint(lowr,uppr) for _ in range(n)]
        


def gen_best():
        #cel mai bun este cand toate el sunt egale - O(n)
        global nums
        x = random.randint(lowr,uppr)
        nums = [x for _ in range(n)]
        




if len(sys.argv) > 2:
        mode = sys.argv[2]
        if(mode == "worst"):
                gen_worst()
               
                
        elif(mode == "best"):
                gen_best()
        #else pp average
        else:
                gen_average()
else:
        gen_average()

print(n)
for x in nums:
        print(x, end=" ")

