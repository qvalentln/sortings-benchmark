# sortings-benchmark
proiect ptr SD



gen teste

[]heapsort
-worst case: elementele sunt deja sortate, se fac multe mutari in constructia heap ului
-best case: elementele sunt egale -> O(n)

[]insertionsort
-worst case: el sortate invers
-best case: el sortate corect

[]radix
-worst case: el max cu multe cifre (comparabil cu O(nlogn))
-best case: el max cu putine cifre (comparabil cu O(n))

usage gen_X.py:

```bash
#gen_X inlocuiesti cu gen_heap, etc...
python3 gen_X.py [N] {best/worst}
#{} este optional, default este average
```