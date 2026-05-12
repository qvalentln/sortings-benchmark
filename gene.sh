#!/bin/bash

#in general
#primele 5 sunt random
#urmatoarele 5 worst
#ultimele 5 best
#ptr small/big


#generare small 
python3 gen_comp.py 20000 > small_granturismo_01.in
python3 gen_comp.py 20000 > small_granturismo_02.in
python3 gen_comp.py 20000 > small_granturismo_03.in
python3 gen_comp.py 20000 > small_granturismo_04.in
python3 gen_comp.py 20000 > small_granturismo_05.in
python3 gen_comp.py 20000 worst > small_granturismo_06.in
python3 gen_comp.py 20000 worst > small_granturismo_07.in
python3 gen_comp.py 20000 worst > small_granturismo_08.in
python3 gen_comp.py 20000 worst > small_granturismo_09.in
python3 gen_comp.py 20000 worst > small_granturismo_10.in
python3 gen_comp.py 20000 best > small_granturismo_11.in
python3 gen_comp.py 20000 best > small_granturismo_12.in
python3 gen_comp.py 20000 best > small_granturismo_13.in
python3 gen_comp.py 20000 best > small_granturismo_14.in
python3 gen_comp.py 20000 best > small_granturismo_15.in


#generare big



python3 gen_comp.py 10000000 > big_granturismo_01.in
python3 gen_comp.py 10000000 > big_granturismo_02.in
python3 gen_comp.py 10000000 > big_granturismo_03.in
python3 gen_comp.py 10000000 > big_granturismo_04.in
python3 gen_comp.py 10000000 > big_granturismo_05.in
python3 gen_comp.py 10000000 worst > big_granturismo_06.in
python3 gen_comp.py 10000000 worst > big_granturismo_07.in
python3 gen_comp.py 10000000 worst > big_granturismo_08.in
python3 gen_comp.py 10000000 worst > big_granturismo_09.in
python3 gen_comp.py 10000000 worst > big_granturismo_10.in
python3 gen_comp.py 10000000 best > big_granturismo_11.in
python3 gen_comp.py 10000000 best > big_granturismo_12.in
python3 gen_comp.py 10000000 best > big_granturismo_13.in
python3 gen_comp.py 10000000 best > big_granturismo_14.in
python3 gen_comp.py 10000000 best > big_granturismo_15.in