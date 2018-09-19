for p in {1..10}
do
	while ! ln ex2file.txt ex2file.txt.lock
	do
		sleep 1
	done


	i=$( tail -n1 ex2file.txt )
	i=$((i+1))
	echo $i >> ex2file.txt

	rm -f ex2file.txt.lock
done
