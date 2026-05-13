#compileaza
g++ -std=c++20 -o2 radixsort.cpp -o radixsort


for i in $(seq -f "%03g" 1 5); do
    echo "Test $i - Random:"
    /usr/bin/time -f "%e seconds" ./radixsort < "radix/big_granturismo_$i.in" > /dev/null
    echo "------------"
done

for i in $(seq -f "%03g" 6 10); do
    echo "Test $i - Worst:"
    /usr/bin/time -f "%e seconds" ./radixsort < "radix/big_granturismo_$i.in" > /dev/null
    echo "------------"
done

for i in $(seq -f "%03g" 11 15); do
    echo "Test $i - Best:"
    /usr/bin/time -f "%e seconds" ./radixsort < "radix/big_granturismo_$i.in" > /dev/null
    echo "------------"
done