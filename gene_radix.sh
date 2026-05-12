#!/bin/bash

#in general
#primele 5 sunt random
#urmatoarele 5 worst
#ultimele 5 best
#ptr small/big



#generare big
python3 gen_radix.py 10000000 > big_granturismo_001.in
python3 gen_radix.py 10000000 > big_granturismo_002.in
python3 gen_radix.py 10000000 > big_granturismo_003.in
python3 gen_radix.py 10000000 > big_granturismo_004.in
python3 gen_radix.py 10000000 > big_granturismo_005.in
python3 gen_radix.py 10000000 worst > big_granturismo_006.in
python3 gen_radix.py 10000000 worst > big_granturismo_007.in
python3 gen_radix.py 10000000 worst > big_granturismo_008.in
python3 gen_radix.py 10000000 worst > big_granturismo_009.in
python3 gen_radix.py 10000000 worst > big_granturismo_010.in
python3 gen_radix.py 10000000 best > big_granturismo_011.in
python3 gen_radix.py 10000000 best > big_granturismo_012.in
python3 gen_radix.py 10000000 best > big_granturismo_013.in
python3 gen_radix.py 10000000 best > big_granturismo_014.in
python3 gen_radix.py 10000000 best > big_granturismo_015.in
