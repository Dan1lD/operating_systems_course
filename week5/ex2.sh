touch ex2.txt
if [ -z "$(grep -Eo '^[0-9]+$' ex2.txt | tail -1)" ]
then
	echo "0" >> ex2.txt
fi

for i in {1..1000}
do
	if ln ex2.txt ex2.txt.lock
	then
		num=$(($(grep -Eo '^[0-9]+$' ex2.txt.lock | tail -1)+1))
		echo "$num" >> ex2.txt.lock
		rm ex2.txt.lock
	fi
done
