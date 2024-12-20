echo "Enter two numbers:"
read a b
sum=$(echo "$a + $b" | bc)
echo "Sum: $sum"
