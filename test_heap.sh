#compileaza
g++ -std=c++20 -o2 heapsort.cpp -o heapsort


for i in $(seq 101 105); do
    echo "Test $i - Random:"
    /usr/bin/time -f "%e seconds" ./heapsort < "heap/big_granturismo_$i.in" > /dev/null
    echo "------------"
done

for i in $(seq 106 110); do
    echo "Test $i - Worst:"
    /usr/bin/time -f "%e seconds" ./heapsort < "heap/big_granturismo_$i.in" > /dev/null
    echo "------------"
done

for i in $(seq 111 115); do
    echo "Test $i - Best:"
    /usr/bin/time -f "%e seconds" ./heapsort < "heap/big_granturismo_$i.in" > /dev/null
    echo "------------"
done