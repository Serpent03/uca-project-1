directory="./out"
cd $directory
file_count=$(find -maxdepth 1 -type f | wc -l)
if [ "$file_count" -lt 5 ]; then
    tar -xvf frames.tar.gz
fi

file_count=$(find -maxdepth 1 -type f | wc -l)
actual=$(($file_count-1))
echo "Launch the program with $actual as argument"
sleep 1 &
wait