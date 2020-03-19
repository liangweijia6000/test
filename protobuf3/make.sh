
echo "--make"

if [ ! -d "./out" ]; then
	mkdir ./out
fi

for file in ./protobuf/*
do
 	protoc -I=./protobuf/ --cpp_out=./out/ $file
done
