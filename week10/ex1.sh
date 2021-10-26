rm week10/_ex1_1.txt
rm week10/_ex1_2.txt
echo "Danil" > week10/_ex1.txt
ln week10/_ex1.txt week10/_ex1_1.txt
ln week10/_ex1.txt week10/_ex1_2.txt
echo $(ls -i week10/_ex1.txt) > week10/ex1.txt
echo $(ls -i week10/_ex1_1.txt) >> week10/ex1.txt
echo $(ls -i week10/_ex1_2.txt) >> week10/ex1.txt
