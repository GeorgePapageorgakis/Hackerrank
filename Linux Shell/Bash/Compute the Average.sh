#Given N integers, compute their average correct to three decimal places. 
#!/bin/bash
read n
for i in $(seq 1 $n);
do
    read k
    let sum=sum+k
done
#echo "scale = 3; $sum/$n" | bc -l	#does not round correctly, gives wrong out for test case 2
printf "%.3f" `echo $sum/$n |  bc -l`