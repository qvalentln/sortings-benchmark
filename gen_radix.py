import random
import sys





#limite int
lowr = -1 * (1 << 31)
uppr = 1 << 31


n=int(sys.argv[1])
nums=[]
#generarea propriu-zisa
def nrcif(x):
        r=0
        while(x != 0):
                r+=1
                x//=10
        return r

def gen_worst():
        global nums
        for _ in range(n):
                #numere cu cat mai multe cifre
                #ma asigur de worst case
                x = random.randint(1000000000, uppr) 
                nums.append(x)

def gen_average():
        global nums
        for _ in range(n):
                x = random.randint(1000,999999)
                nums.append(x)
        
                
def gen_best():
        global nums
        #best cand am putine cifre pe toate nrle
        #ma asigur ca e best pe bune, generez in [-9,9]
        dlo=-9
        dhi=9

        for _ in range(n):
                x = random.randint(dlo,dhi)
                nums.append(x)
        




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

