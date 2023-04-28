echo _______________oop lab4 Test Author: Liu Jiaxing___________________
echo pdlist测试
./pdlist
echo 插入来自input.txt的数据
./pdadd < input.txt
echo 展示插入后的结果
./pdlist
echo 展示特定日期范围内的日记
./pdlist 20200101 20221111
echo 展示日记的全部内容
./pdshow < show.txt
echo 删除日记内容
./pdremove < remove.txt