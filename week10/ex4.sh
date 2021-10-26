rm -rf week10/tmp
mkdir week10/tmp
touch week10/tmp/file1
touch week10/tmp/file2
ln week10/tmp/file1 week10/tmp/link1
cd week10
gcc ex4.c -o out
./out > ex4.txt
cd ..