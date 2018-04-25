for file in *.cpp *.py
do
	s=$(echo $file | cut -d. -f1)
	mkdir $s
	mv $file $s/solution.cpp
done
