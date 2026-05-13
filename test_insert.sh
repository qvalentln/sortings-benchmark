g++ -std=c++20 -o2 insertionsort.cpp -o insertionsort

for i in $(seq -f "%02g" 1 5); do
    echo "Test $i - Random:"
    /usr/bin/time -f "%e seconds" ./insertionsort < "compares/small_granturismo_$i.in" > /dev/null
done

for i in $(seq -f "%02g" 6 10); do
    echo "Test $i - Worst:"
    /usr/bin/time -f "%e seconds" ./insertionsort < "compares/small_granturismo_$i.in" > /dev/null
done

for i in $(seq -f "%02g" 11 15); do
    echo "Test $i - Best:"
    /usr/bin/time -f "%e seconds" ./insertionsort < "compares/small_granturismo_$i.in" > /dev/null
done