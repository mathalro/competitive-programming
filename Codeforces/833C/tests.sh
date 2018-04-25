num=$(find . -name "in*" | wc -l);
for ((i=1; i <= $num; i++))
do
	cat "in$i";
	./a.out < in$i;
	echo;
done;
